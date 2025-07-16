#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <fstream>
#include "problemReader.h"
#include "packing.h"

//Para nao imprimir mensagens de debug, comente a linha abaixo
#define DEBUG ;

using namespace std;

int main(int argc, char* argv[]) {
	
	ifstream file(argv[1]);
	if (!file.is_open()) {
		cerr << "Erro ao abrir o arquivo " << argv[1] << endl;
		return 1;
	}

	int totalProblems;
	file >> totalProblems;

	for (int i = 0; i < totalProblems; ++i) {
		const time_t begin = clock();
		try {
			problemReader* problem = new problemReader(file);

			// Aqui você chama seu solver
			/*static int packing_solve(int nItems,
			int W, int H, int L,
			vector <int>&w, vector <int>&h, vector <int>&l,
			vector <int>&x, vector <int>&y, vector <int>&z,
			int dominio);*/
			vector <int> x(problem->nItems), y(problem->nItems), z(problem->nItems);
			int feasible = packing::packing_solve(problem->nItems, problem->W, problem->H, problem->L,
				problem->w, problem->h, problem->l,
				x, y, z);
			const time_t end = clock();
			float time = (end - begin) / (float)(CLOCKS_PER_SEC);
			cout << "TIME: " << time << endl;
			cout << "STATUS: " << feasible << endl;
			delete(problem);
		}
		catch (const exception& e) {
			cerr << "Erro ao processar o problema " << (i + 1) << ": " << e.what() << endl;
			break;
		}
	}

	file.close();

	return 0;
}
