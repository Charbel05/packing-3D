#ifndef PACKING_H_
#define PACKING_H_

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class packing {
public:
	packing();
	virtual ~packing();

	static int packing_solve(int nItems,
		int W, int H, int L,
		vector <int>& w, vector <int>& h, vector <int>& l,
		vector <int>& x, vector <int>& y, vector <int>& z,
		int input_domain_option, int input_pre_process);

	static int cp_solver(int nItems,
		int W, int H, int L,
		vector <int>& w, vector <int>& h, vector <int>& l,
		vector <int>& x, vector <int>& y, vector <int>& z,
		int domain_option);
};

class packing2D {
public:
	packing2D();
	virtual ~packing2D();

	static int auxiliary_packing2D_solve(
		vector <int>& indice_items,
		int D1, int D2,
		vector <int>& dim_itens1, vector <int>& dim_itens2,
		vector <int>& dim_solver1, vector <int>& dim_solver2,
		int domain_option);

	static int pre_process_packing2D_solve(
		string text,
		vector <int>& indice_items,
		int D1, int D2,
		int camadas, vector<int>& peso, 
		vector <int>& dim_itens1, vector <int>& dim_itens2,
		vector <int>& dim_solver1, vector <int>& dim_solver2,
		int domain_option);
};

#endif /* PACKING_H_ */

