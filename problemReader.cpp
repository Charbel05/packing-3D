#include "problemReader.h"
#include <iostream>
#include <fstream>


problemReader::problemReader(char* file_name) {
	ifstream file(file_name);

	if (!file.is_open()) {
		cerr << "Problema ao abrir o arquivo " << file_name << endl;
		exit(-1);
	}

	file >> this->nItems >> this->W >> this->H >> this->L;

	// Preenche vetores de dimensões dos itens
	for (int i = 0; i < this->nItems; i++)
	{
		int wi, hi, li;
		file >> wi >> hi >> li;
		this->add_item(wi, hi, li);
	}
}

void problemReader::add_item(int w_, int h_, int l_) {
	this->w.push_back(w_);
	this->h.push_back(h_);
	this->l.push_back(l_);
}

problemReader::~problemReader() {
	cout << "Morrendo" << endl;
}
