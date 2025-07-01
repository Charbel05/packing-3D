#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include "problemReader.h"
#include "packing.h"

//Para nao imprimir mensagens de debug, comente a linha abaixo
#define DEBUG ;

using namespace std;

int main(int argc, char* argv[]) {

	const time_t begin = clock();

	//Cria e lê o problema do arquivo
	problemReader* problem = new problemReader(argv[1]);

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

	return 0;
}
