#include "packing.h"
#include <cmath>
#include <ilcp/cp.h>

int count_itens_largos, count_itens_altos, count_itens_profundos;
int count_itens_largos_altos, count_itens_largos_profundos, count_itens_altos_profundos;
int count_packing_largos, count_packing_altos, count_packing_profundos;

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
				mdl.add(
					X[i] + w[i] <= X[j] || 
					X[j] + w[j] <= X[i] ||
					Y[i] + h[i] <= Y[j] || 
					Y[j] + h[j] <= Y[i] ||
					Z[i] + l[i] <= Z[j] || 
					Z[j] + l[j] <= Z[i]
				);
			}
		}


		//solver
		IloCP cp(mdl); 
		cp.setParameter(IloCP::Workers, 1);
		cp.setParameter(IloCP::TimeLimit, 1800);

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
		cp.end();
		mdl.end();
	}
	catch (IloException& error) {
		env.out() << "Error: " << error << endl;
	}
	env.end();

	return feasible;
}

int packing2D::auxiliary_packing2D_solve(vector <int>& indice_itens, int D1, int D2, vector <int>& dim_itens1, vector <int>& dim_itens2, vector <int>& dim_solver1, vector <int>& dim_solver2) {

	IloEnv env;
	int feasible = 1;

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
				mdl.add(
					X[i] + dim_itens1[item_i] <= X[j] ||
					X[j] + dim_itens1[item_j] <= X[i] ||
					Y[i] + dim_itens2[item_i] <= Y[j] ||
					Y[j] + dim_itens2[item_j] <= Y[i]
				);

			}
		}


		//solver
		IloCP cp(mdl);
		cp.setParameter(IloCP::Workers, 1);
		cp.setParameter(IloCP::TimeLimit, 10);

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
			//feasible = 1;
		}
		else{
			if (cp.getStatus() == IloAlgorithm::Infeasible) {
				feasible = 0;
			}
		}
		cp.end();
		mdl.end();
	}
	catch (IloException& error) {
		env.out() << "Error: " << error << endl;
	}
	env.end();

	return feasible;
}

int packing2D::pre_process_packing2D_solve(string text, vector <int>& indice_itens, int D1, int D2, int camadas, vector<int>& peso, vector <int>& dim_itens1, vector <int>& dim_itens2, vector <int>& dim_solver1, vector <int>& dim_solver2) {

	IloEnv env;
	int feasible = 1;

	try {
		IloModel mdl(env);

		IloIntVarArray X(env);
		IloIntVarArray Y(env);
		int item_atual = 0;

		int limite_inicial = indice_itens.size();
		for (int k = 0; k < limite_inicial; k++) {
			item_atual = indice_itens[k];
			if (peso[item_atual] > 1) {
				for (int p = 1; p < peso[item_atual]; p++) {
					indice_itens.push_back(item_atual);
				}
			}
		}

		for (int j = 0; j < indice_itens.size(); j++) {
			item_atual = indice_itens[j];
			X.add(IloIntVar(env, 0, (D1*(camadas-1) ) - dim_itens1[item_atual]));
			Y.add(IloIntVar(env, 0, D2 - dim_itens2[item_atual]));
		}

		for (IloInt i = 0; i < indice_itens.size(); i++) {
			int item_i = indice_itens[i];
			for (IloInt j = i + 1; j < indice_itens.size(); j++) {
				int item_j = indice_itens[j];
				mdl.add(
					X[i] + dim_itens1[item_i] <= X[j] ||
					X[j] + dim_itens1[item_j] <= X[i] ||
					Y[i] + dim_itens2[item_i] <= Y[j] ||
					Y[j] + dim_itens2[item_j] <= Y[i]
				);

			}
		}


		//solver
		IloCP cp(mdl);
		cp.setParameter(IloCP::Workers, 1);
		cp.setParameter(IloCP::TimeLimit, 10);

		//executando o resolvedor
		if (cp.solve()) {
			cout << "=======SOLUCAO 2D======= " << text << endl;
			for (IloInt i = 0; i < indice_itens.size(); i++) {
				item_atual = indice_itens[i];
				cout << "Item[" << item_atual << "]:" 
					<< cp.getValue(X[i]) << " " 
					<< cp.getValue(Y[i]) << endl;
			}
			cout << "========================" << endl;
			//feasible = 1;
		}
		else {
			if (cp.getStatus() == IloAlgorithm::Infeasible) {
				feasible = 0;
			}
		}
		cp.end();
		mdl.end();
	}
	catch (IloException& error) {
		env.out() << "Error: " << error << endl;
	}
	env.end();

	return feasible;
}


void classificar_em_3faixas(string text, int nItems, int dim_bin, vector<int>& peso, vector<int>& itens_pesados, int dim_bin_aux1, int dim_bin_aux2, vector <int>& dim_itens, vector <int>& dim_itens_aux1, vector <int>& dim_itens_aux2) {

	cout << endl;
	cout << "------- 3 FAIXAS ----------" << endl;
	cout << "=======PESO" << text << "=======" << endl;
	for (int i = 0; i < nItems; i++){
		peso[i] = floor(dim_itens[i] / ( ((float)dim_bin)/3 + 0.00001));
		if (peso[i] > 0) {
			itens_pesados.push_back(i);
			cout << "Item[" << i << "]: peso " << peso[i] << " " << endl;
		}
	}
	cout << "==========================" << endl;
	int soma = 0;
	for (int i = 0; i < itens_pesados.size(); i++) {
		int item_atual = itens_pesados[i];
		soma += peso[item_atual] * dim_itens_aux1[item_atual] * dim_itens_aux2[item_atual];
	}
	if (soma > 2 * dim_bin_aux1 * dim_bin_aux2) {
		itens_pesados = { -1 };
	}
}

int classificar_em_Nfaixas(string text, int nItems, int dim_bin, vector <int>& peso_Nfaixas, vector <int>& itens_pesados_Nfaixas, int dim_bin_aux1, int dim_bin_aux2, vector <int>& dim_itens, vector <int>& dim_itens_aux1, vector <int>& dim_itens_aux2) {

	vector <vector<int>> peso_todos_itens(nItems, vector<int>(dim_bin + 1, 0)), todos_itens_pesados(dim_bin + 1, vector<int>(nItems, 0));

	// Cálculo para encontrar o peso de cada item por faixa
	for (int f = 2; f < dim_bin + 1; f++){
		for (int i = 0; i < nItems; i++) {
			peso_todos_itens[i][f] = floor(dim_itens[i] / (( ((float)dim_bin) / f) + 0.00001));
			if (peso_todos_itens[i][f] > 0) {
				todos_itens_pesados[f][i] = i;
			}
		}
	}

	// Aqui é feito o cálculo para encontrar o valor que máximize o valor de F*
	int fEstrela = 0;
	double soma_fEstrela = 0;
	for (int f = 2; f < dim_bin + 1; f++){
		double soma_f = 0;
		for (int i = 0; i < todos_itens_pesados[f].size(); i++){
			int item_atual = todos_itens_pesados[f][i];
			soma_f += (peso_todos_itens[item_atual][f] * dim_itens_aux1[item_atual] * dim_itens_aux2[item_atual]);
		}
		soma_f = soma_f / (f - 1);
		cout << "Soma camada[" << f << "]: " << soma_f << endl;
		if (soma_f > soma_fEstrela) {
			fEstrela = f;
			soma_fEstrela = soma_f;
		}
	}
	
	// Aqui separamos os índices e pesos dos itens que serão utilizados no modelo 2D
	cout << text << "F* = " << fEstrela << endl;
	for (int i = 0; i < todos_itens_pesados[fEstrela].size(); i++) {
		int item_atual = todos_itens_pesados[fEstrela][i];
		itens_pesados_Nfaixas.push_back(item_atual);
		peso_Nfaixas[item_atual] = peso_todos_itens[item_atual][fEstrela];
		cout << "Peso Item[" << item_atual << "]: " << peso_Nfaixas[item_atual] << endl;
	}

	peso_todos_itens.clear();
	todos_itens_pesados.clear();

	// Iremos fazer o último teste para garantir que o somatório dos itens respeitará a restrição
	int soma = 0;
	for (int i = 0; i < nItems; i++) {
		int item_atual = peso_Nfaixas[i];
		soma += (peso_Nfaixas[item_atual] * dim_itens_aux1[item_atual] * dim_itens_aux2[item_atual]) ;
	}
	if (soma > (fEstrela - 1) * dim_bin_aux1 * dim_bin_aux2) {
		itens_pesados_Nfaixas = { -1 };
		return -1;
	}
	cout << "Soma = " << soma << endl;
	return fEstrela;
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
	if (area_itens_largos > H * L) {
		cout << "Falha no Pre processamento -> ITENS LARGOS" << endl;
		return 0;
	}
	// Agrupando os Altos
	for (int i = 0; i < itens_altos.size(); i++) {
		int item_atual = itens_altos[i];
		area_itens_altos += w[item_atual] * l[item_atual];
	}
	if (area_itens_altos > W * L) {
		cout << "Falha no Pre processamento -> ITENS ALTOS" << endl;
		return 0;
	}
	// Agrupando os Profundos
	for (int i = 0; i < itens_profundos.size(); i++) {
		int item_atual = itens_profundos[i];
		area_itens_profundos += w[item_atual] * h[item_atual];
	}
	if (area_itens_profundos > W * H) {
		cout << "Falha no Pre processamento -> ITENS PROFUNDOS" << endl;
		return 0;
	}
	// Agrupando os Largos e Altos
	for (int i = 0; i < itens_largos_altos.size(); i++) {
		int item_atual = itens_largos_altos[i];
		profundidade_itens += l[item_atual];
	}
	if (profundidade_itens > L) {
		cout << "Falha no Pre processamento -> ITENS LARGOS E ALTOS" << endl;
		count_itens_largos_altos++;
		return 0;
	}
	// Agrupando os Largos e Profundos
	for (int i = 0; i < itens_largos_profundos.size(); i++) {
		int item_atual = itens_largos_profundos[i];
		altura_itens += h[item_atual];
	}
	if (altura_itens > H) {
		cout << "Falha no Pre processamento -> ITENS LARGOS E PROFUNDOS" << endl;
		count_itens_largos_profundos++;
		return 0;
	}
	// Agrupando os Altos e Profundos
	for (int i = 0; i < itens_altos_profundos.size(); i++) {
		int item_atual = itens_altos_profundos[i];
		largura_itens += w[item_atual];
	}
	if (largura_itens > W) {
		cout << "Falha no Pre processamento -> ITENS ALTOS E PROFUNDOS" << endl;
		return 0;
	}

	if (itens_largos.size() > 0 && packing2D::auxiliary_packing2D_solve(itens_largos, H, L, h, l, y, z) == 0){
		cout << "Falha no PACKING 2D -> ITENS LARGOS" << endl;
		count_packing_largos++;
		return 0;
	}
	if (itens_altos.size() > 0 && packing2D::auxiliary_packing2D_solve(itens_altos, W, L, w, l, x, z) == 0) {
		cout << "Falha no PACKING 2D -> ITENS ALTOS" << endl;
		count_packing_altos++;
		return 0;
	}
	if (itens_profundos.size() > 0 && packing2D::auxiliary_packing2D_solve(itens_profundos, W, H, w, h, x, y) == 0) {
		cout << "Falha no PACKING 2D -> ITENS PROFUNDOS" << endl;
		count_packing_profundos++;
		return 0;
	}

	vector<int> pesoW(nItems, 0), itens_pesados_3faixasW{};
	classificar_em_3faixas("(W)", nItems, W, pesoW, itens_pesados_3faixasW, H, L, w, h, l);
	if (itens_pesados_3faixasW.size() > 0 && (itens_pesados_3faixasW[0] == -1 || packing2D::pre_process_packing2D_solve("(W)", itens_pesados_3faixasW, H, L, 3, pesoW, h, l, y, z) == 0)) {
		cout << "Falha no PACKING 2D -> DISCRETIZACAO 3 faixas (W)" << endl;
		return 0;
	}

	vector<int> pesoH(nItems, 0), itens_pesados_3faixasH{};
	classificar_em_3faixas("(H)", nItems, H, pesoH, itens_pesados_3faixasH, W, L, h, w, l);
	if (itens_pesados_3faixasH.size() > 0 && (itens_pesados_3faixasH[0] == -1 || packing2D::pre_process_packing2D_solve("(H)", itens_pesados_3faixasH, W, L, 3, pesoH, w, l, x, z) == 0)) {
		cout << "Falha no PACKING 2D -> DISCRETIZACAO 3 faixas (H)" << endl;
		return 0;
	}

	vector<int> pesoL(nItems, 0), itens_pesados_3faixasL{};
	classificar_em_3faixas("(L)", nItems, L, pesoL, itens_pesados_3faixasL, W, H, l, w, h);
	if (itens_pesados_3faixasL.size() > 0 && (itens_pesados_3faixasL[0] == -1 || packing2D::pre_process_packing2D_solve("(L)", itens_pesados_3faixasL, W, H, 3, pesoL, w, h, x, y) == 0)) {
		cout << "Falha no PACKING 2D -> DISCRETIZACAO 3 faixas (L)" << endl;
		return 0;
	}

	vector <int> pesoW_Nfaixas(nItems, 0), itens_pesadosW_Nfaixas{};
	int camadas = classificar_em_Nfaixas("(W)", nItems, W, pesoW_Nfaixas, itens_pesadosW_Nfaixas, H, L, w, h, l);
	if (itens_pesadosW_Nfaixas.size() > 0 && (itens_pesadosW_Nfaixas[0] == -1 || packing2D::pre_process_packing2D_solve("(W)", itens_pesadosW_Nfaixas, H, L, camadas, pesoW_Nfaixas, h, l, y, z) == 0)) {
		cout << "Falha no PACKING 2D -> DISCRETIZACAO " << camadas << " faixas (W)" << endl;
		return 0;
	}

	vector <int> pesoH_Nfaixas(nItems, 0), itens_pesadosH_Nfaixas{};
	camadas = classificar_em_Nfaixas("(H)", nItems, H, pesoH_Nfaixas, itens_pesadosH_Nfaixas, W, L, h, w, l);
	if (itens_pesadosH_Nfaixas.size() > 0 && (itens_pesadosH_Nfaixas[0] == -1 || packing2D::pre_process_packing2D_solve("(H)", itens_pesadosH_Nfaixas, W, L, camadas, pesoH_Nfaixas, w, l, x, z) == 0)) {
		cout << "Falha no PACKING 2D -> DISCRETIZACAO " << camadas << " faixas (H)" << endl;
		return 0;
	}

	vector <int> pesoL_Nfaixas(nItems, 0), itens_pesadosL_Nfaixas{};
	camadas = classificar_em_Nfaixas("(L)", nItems, L, pesoL_Nfaixas, itens_pesadosL_Nfaixas, W, H, l, w, h);
	if (itens_pesadosL_Nfaixas.size() > 0 && (itens_pesadosL_Nfaixas[0] == -1 || packing2D::pre_process_packing2D_solve("(L)", itens_pesadosL_Nfaixas, W, H, camadas, pesoL_Nfaixas, w, h, x, y) == 0)) {
		cout << "Falha no PACKING 2D -> DISCRETIZACAO " << camadas << "faixas(H)" << endl;
		return 0;
	}

	feasible = cp_solver(nItems, W, H, L, w, h, l, x, y, z);
	return feasible;
}
