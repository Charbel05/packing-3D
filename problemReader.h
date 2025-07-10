#ifndef PROBLEM2BPPC_H_
#define PROBLEM2BPPC_H_

#include <vector>

using namespace std;

class problemReader {
public:
	int W;
	int H;
	int L;
	int nItems;
	vector <int> h;
	vector <int> w;
	vector <int> l;

	//constructor
	problemReader(char* file_name);

	//destructor
	virtual ~problemReader();

	//methods
	void add_item(int w, int h, int l, int nItems);
};


#endif /* PROBLEM2BPPC_H_ */

