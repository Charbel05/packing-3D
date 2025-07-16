#include "problemReader.h"
#include <iostream>
#include <fstream>


problemReader::problemReader(ifstream& file) {
	
	int nProblem = 0, seed = 0, typeItens = 0, nItems = 0;
	if (!(file >> nProblem >> seed >> this->W >> this->H >> this->L >> typeItens)) {
		// Fim de arquivo ou erro
		throw std::runtime_error("Erro ao ler cabeçalho do problema.");
	}

	for (int i = 0; i < typeItens; i++) {
		int ti, vertical_permission;
		int wi, hi, li;

		if (!(file >> ti >> wi >> vertical_permission >> hi >> vertical_permission >> li >> vertical_permission >> nItems)) {
			throw std::runtime_error("Erro ao ler item.");
		}

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
