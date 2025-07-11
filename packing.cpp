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
		IloCP cp(mdl); 
		cp.setParameter(IloCP::Workers, 1);
		//cp.setParameter(IloCP::OptimalityTolerance, 100);

		//executando o resolvedor
		if (cp.solve()) {
			cout << "=======SOLUCAO 3D (FINAL)=======" << endl;
			for (IloInt i = 0; i < nItems; i++) {
				x[i] = cp.getValue(X[i]);
				y[i] = cp.getValue(Y[i]);
				z[i] = cp.getValue(Z[i]);
				cout << "Item[" << i << "]:" << x[i] << " " << y[i] << " " << z[i] << endl;
			}
			cout << "================================" << endl;
			feasible = 1;
		}
	}
	catch (IloException& error) {
		env.out() << "Error: " << error << endl;
	}
	env.end();

	return feasible;
}

int packing2D::auxiliary_packing2D_solve(vector <int>& indice_itens, int D1, int D2, vector <int>& dim_itens1, vector <int>& dim_itens2, vector <int>& dim_solver1, vector <int>& dim_solver2) {

	IloEnv env;
	int feasible = 0;

	try {
		IloModel mdl(env); //modelo do problema

		//variaveis do problema
		IloIntVarArray X(env);
		IloIntVarArray Y(env);
		int item_atual;

		//dominio sem padroes
		for (IloInt j = 0; j < indice_itens.size(); j++) {
			item_atual = indice_itens[j];
			X.add(IloIntVar(env, 0, D1 - dim_itens1[item_atual]));
			Y.add(IloIntVar(env, 0, D2 - dim_itens2[item_atual]));
		}

		//Restrição de não sobreposição
		for (IloInt i = 0; i < indice_itens.size(); i++) {
			int item_i = indice_itens[i];
			for (IloInt j = i + 1; j < indice_itens.size(); j++) {
				int item_j = indice_itens[j];
				mdl.add(X[i] + dim_itens1[item_i] <= X[j] || X[j] + dim_itens1[item_j] <= X[i] ||
					Y[i] + dim_itens2[item_i] <= Y[j] || Y[j] + dim_itens2[item_j] <= Y[i]
				);
			}
		}


		//solver
		IloCP cp(mdl);
		cp.setParameter(IloCP::Workers, 1);

		//executando o resolvedor
		if (cp.solve()) {
			cout << "=======SOLUCAO 2D=======" << endl;
			for (IloInt i = 0; i < indice_itens.size(); i++) {
				item_atual = indice_itens[i];
				dim_solver1[item_atual] = cp.getValue(X[i]);
				dim_solver2[item_atual] = cp.getValue(Y[i]);
				cout << "Item[" << i << "]:" << dim_solver1[item_atual] << " " << dim_solver2[item_atual] << endl;
			}
			cout << "========================" << endl;
			feasible = 1;
		}
	}
	catch (IloException& error) {
		env.out() << "Error: " << error << endl;
	}
	env.end();

	return feasible;
}

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
	vector <int> itens_largos_profundos = {};
	vector <int> itens_altos_profundos = {};

	for (int i = 0; i < nItems; i++) {
		// Teste da largura 
		if (w[i] > W / 2) {
			itens_largos.push_back(i); // Passa o índice do item largo
			cout << "Item largo: " << i << " " << endl;
			if (h[i] > H / 2) {
				itens_largos_altos.push_back(i);
				cout << "Item largo e alto: " << i << " " << endl;
			}
			if (l[i] > L / 2) {
				itens_largos_profundos.push_back(i);
				cout << "Item largo e profundo: " << i << " " << endl;
			}	
		}
		// Teste da altura 
		if (h[i] > H / 2) {
			itens_altos.push_back(i);
			cout << "Item alto: " << i << " " << endl;
			if (l[i] > L / 2) {
				itens_altos_profundos.push_back(i);
				cout << "Item alto e profundo: " << i << " " << endl;
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
	int largura_itens = 0, altura_itens = 0, profundidade_itens = 0;

	// Agrupando os Largos
	for (int i = 0; i < itens_largos.size(); i++) {
		int item_atual = itens_largos[i];					// Aqui obtemos o índice do item no conjunto primário
		area_itens_largos += h[item_atual] * l[item_atual]; // Para que aqui possamos manipulá-los
	}
	// Agrupando os Altos
	for (int i = 0; i < itens_altos.size(); i++) {
		int item_atual = itens_altos[i];
		area_itens_altos += w[item_atual] * l[item_atual];
	}
	// Agrupando os Profundos
	for (int i = 0; i < itens_profundos.size(); i++) {
		int item_atual = itens_profundos[i];
		area_itens_profundos += w[item_atual] * h[item_atual];
	}
	// Agrupando os Largos e Altos
	for (int i = 0; i < itens_largos_altos.size(); i++) {
		int item_atual = itens_largos_altos[i];
		profundidade_itens += l[item_atual];
	}
	// Agrupando os Largos e Profundos
	for (int i = 0; i < itens_largos_profundos.size(); i++) {
		int item_atual = itens_largos_profundos[i];
		altura_itens += h[item_atual];
	}
	// Agrupando os Altos e Profundos
	for (int i = 0; i < itens_altos_profundos.size(); i++) {
		int item_atual = itens_altos_profundos[i];
		largura_itens += w[item_atual];
	}

	if (area_itens_largos > H * L || 
		area_itens_altos > W * L  ||
		area_itens_profundos > W * H ||
		profundidade_itens > L ||
		altura_itens > H || 
		largura_itens > W) 
	{
		cout << "Falha no Pre processamento" << endl;
		return 0;
	}

	if (
	 packing2D::auxiliary_packing2D_solve(itens_largos, H, L, h, l, y, z)     == 0 ||
	 packing2D::auxiliary_packing2D_solve(itens_altos, W, L, w, l, x, z)      == 0 ||
	 packing2D::auxiliary_packing2D_solve(itens_profundos, W, H, w, h, x, y)  == 0
	 ){
		cout << "Falha no PACKING 2D" << endl;
		return 0;
	}

	feasible = cp_solver(nItems, W, H, L, w, h, l, x, y, z);
	return feasible;
}
