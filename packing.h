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
		vector <int>& x, vector <int>& y, vector <int>& z);

	static int cp_solver(int nItems,
		int W, int H, int L,
		vector <int>& w, vector <int>& h, vector <int>& l,
		vector <int>& x, vector <int>& y, vector <int>& z);
};

#endif /* PACKING_H_ */

