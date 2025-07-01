#include "packing.h"
#include <ilcp/cp.h>

packing::packing() {
	// TODO Auto-generated constructor stub

}

packing::~packing() {
	// TODO Auto-generated destructor stub
}

int packing::cp_solver(int nItems, int W, int H, int L, vector <int>& w, vector <int>& h, vector <int>& l, vector <int>& x, vector <int>& y, vector <int>& z) {

	IloEnv env;
	int feasible = 0;

	try {
		IloModel mdl(env); //modelo do problema

		//variaveis do problema
		IloIntVarArray X(env);
		IloIntVarArray Y(env);
		IloIntVarArray Z(env);

		//dominio sem padroes
		for (IloInt j = 0; j < nItems; j++) {
			X.add(IloIntVar(env, 0, W - w[j]));
			Y.add(IloIntVar(env, 0, H - h[j]));
			Z.add(IloIntVar(env, 0, L - l[j]));
		}


		//Restrição de não sobreposição
		for (IloInt i = 0; i < nItems; i++) {
			for (IloInt j = i + 1; j < nItems; j++) {
				mdl.add(X[i] + w[i] <= X[j] || X[j] + w[j] <= X[i] ||
					Y[i] + h[i] <= Y[j] || Y[j] + h[j] <= Y[i] ||
					Z[i] + l[i] <= Z[j] || Z[j] + l[j] <= Z[i]
				);
			}
		}


		//solver
		IloCP cp(mdl); //resolvedor do CP Optimizer
		cp.setParameter(IloCP::Workers, 1);
		//cp.setParameter(IloCP::OptimalityTolerance, 100);

		//executando o resolvedor
		if (cp.solve()) {
			cout << "=======SOLUCAO=======" << endl;
			for (IloInt i = 0; i < nItems; i++) {
				x[i] = cp.getValue(X[i]);
				y[i] = cp.getValue(Y[i]);
				z[i] = cp.getValue(Z[i]);
				cout << "Item[" << i << "]:" << x[i] << " " << y[i] << " " << z[i] << endl;
			}
			cout << "=====================" << endl;
			feasible = 1;
		}
	}
	catch (IloException& error) {
		env.out() << "Error: " << error << endl;
	}
	env.end();

	return feasible;
}

//&w quer dizer que recebo o vector w como referencia e não como valor.
int packing::packing_solve(int nItems, int W, int H, int L, vector <int>& w, vector <int>& h, vector <int>& l, vector <int>& x, vector <int>& y, vector <int>& z) {
	int feasible = 0;

	if (nItems == 1) {
		feasible = 1;
		x[0] = 0;
		y[0] = 0;
		z[0] = 0;
		return feasible;
	}

	// Teste do volume
	int volumeTotal = 0;
	for (int i = 0; i < nItems; i++) {
		volumeTotal += (w[i] * h[i] * l[i]);
	}
	if (volumeTotal > W * H * L)
		return 0;

	cout << "Tentando empacotar!" << endl;
	cout << "W " << W << " H " << H << " L " << L << endl;
	for (int i = 0; i < nItems; i++) {
		cout << "Item[" << i << "]:" << w[i] << ", " << h[i] << ", " << l[i] << endl;
	}
	cout << "iniciando os testes..." << endl;

	// Pré-processamento
	vector <int> itens_largos = {};
	vector <int> itens_altos = {};
	vector <int> itens_profundos = {};
	vector <int> itens_largos_altos = {};
	vector <int> itens_altos_profundos = {};
	vector <int> itens_largos_profundos = {};

	for (int i = 0; i < nItems; i++) {
		// Teste da largura 
		if (w[i] > W / 2) {
			if (h[i] > H / 2) {
				itens_largos_altos.push_back(i);
				cout << "Item largo e alto: " << i << " " << endl;
			}
			if (l[i] > L / 2) {
				itens_largos_profundos.push_back(i);
				cout << "Item largo e profundo: " << i << " " << endl;
			}
			else {
				itens_largos.push_back(i); // Passa o índice do item largo
				cout << "Item largo: " << i << " " << endl;
			}
		}
		// Teste da altura 
		if (h[i] > H / 2) {
			if (l[i] > L / 2) {
				itens_largos_profundos.push_back(i);
				cout << "Item largo e profundo: " << i << " " << endl;
			}
			else {
				itens_altos.push_back(i);
				cout << "Item alto: " << i << " " << endl;
			}
		}
		// Teste da profundidade
		if (l[i] > L / 2) {
			itens_profundos.push_back(i);
			cout << "Item profundo: " << i << " " << endl;
		}
	}

	// Percorreres o vetores
	int area_itens_largos = 0, area_itens_altos = 0, area_itens_profundos = 0;

	// Largura
	for (int i = 0; i < itens_largos.size(); i++) {
		int item_atual = itens_largos[i];					// Aqui obtemos o índice do item no conjunto primário
		area_itens_largos += h[item_atual] * l[item_atual]; // Para que aqui possamos manipulá-los
	}
	if (area_itens_largos > H * L) {
		return 0;
	}
	// Altura
	for (int i = 0; i < itens_altos.size(); i++) {
		int item_atual = itens_altos[i];
		area_itens_altos += w[item_atual] * l[item_atual];
	}
	if (area_itens_altos > W * L) {
		return 0;
	}
	// Profundidade
	for (int i = 0; i < itens_profundos.size(); i++) {
		int item_atual = itens_profundos[i];
		area_itens_profundos += w[item_atual] * h[item_atual];
	}
	if (area_itens_profundos > W * H) {
		return 0;
	}

	feasible = cp_solver(nItems, W, H, L, w, h, l, x, y, z);
	return feasible;
}