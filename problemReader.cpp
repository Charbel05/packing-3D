#include "problemReader.h"
#include <iostream>
#include <fstream>


problemReader::problemReader(char* file_name) {
	ifstream file(file_name);

	if (!file.is_open()) {
		cerr << "Problema ao abrir o arquivo " << file_name << endl;
		exit(-1);
	}

	int nProblem = 0, seed = 0, typeItens = 0, nItems = 0;
	file >> nProblem >> seed >> this->W >> this->H >> this->L >> typeItens;

	for (int i = 0; i < typeItens; i++)
	{
		int ti, vertical_permission;
		int wi, hi, li;
		file >> ti >> wi >> vertical_permission >> hi >> vertical_permission >> li >> vertical_permission >> nItems;
		this->nItems += nItems;
		this->add_item(wi, hi, li, nItems);
	}
}

void problemReader::add_item(int w_, int h_, int l_, int nItems) {
	for (int i = 0; i < nItems; i++){
		this->w.push_back(w_);
		this->h.push_back(h_);
		this->l.push_back(l_);
	}
}

problemReader::~problemReader() {
	cout << "Morrendo" << endl;
}
