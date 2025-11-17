#include "packing.h"
#include <cmath>
#include <algorithm>
#include <ilcp/cp.h>

vector<int> BW, BH, BL;
vector<int> BD1, BD2;

packing::packing() {
	// TODO Auto-generated constructor stub

}

packing::~packing() {
	// TODO Auto-generated destructor stub
}

void static dominio_Boschetti(int nItems, int W, int H, int L, vector <int>& w, vector <int>& h, vector <int>& l) {

	int number_points, lastCount;
	vector <vector<int>> BiW(nItems), BiH(nItems), BiL(nItems);

	for (int i = 0; i < nItems; i++) {
		BiW[i].push_back(0);
		number_points = 1;
		for (int j = 0; j < nItems; j++) {
			if (j != i)
			{
				lastCount = number_points;
				for (int k = 0; k < lastCount; k++) {
					if (w[j] + BiW[i][k] <= W - w[i] 
						&& ( find(BiW[i].begin(), BiW[i].end(), w[j] + BiW[i][k]) == BiW[i].end() ) // Verifica se esse ponto existe no vetor 
						)
					{
						BiW[i].push_back(w[j] + BiW[i][k]);
						number_points++;
					}
				}
			}
		}
	}
	//concatena e elimina a duplicidade (ordena/unifica/apaga)
	for (int i = 0; i < nItems; i++) {
		for (int j = 0; j < BiW[i].size(); j++) {
			BW.push_back(BiW[i][j]);
		}
		cout << endl;
	}

	for (int i = 0; i < nItems; i++) {
		BiH[i].push_back(0);
		number_points = 1;
		for (int j = 0; j < nItems; j++) {
			if (j != i)
			{
				lastCount = number_points;
				for (int k = 0; k < lastCount; k++) {
					if (h[j] + BiH[i][k] <= H - h[i] //testa a combinação do item adicionado e os que ja estavam no padrao
						&&
						(find(BiH[i].begin(), BiH[i].end(), h[j] + BiH[i][k]) == BiH[i].end()) // Verifica se esse ponto existe no vetor 
						) 
					{
						BiH[i].push_back(h[j] + BiH[i][k]); //e toma a posicao pos item adicionado
						number_points++;
					}
				}
			}
		}
	}
	//concatena e elimina a duplicidade (ordena/unifica/apaga)
	for (int i = 0; i < nItems; i++) {
		for (int j = 0; j < BiH[i].size(); j++) {
			BH.push_back(BiH[i][j]);
		}
	}

	for (int i = 0; i < nItems; i++) {
		BiL[i].push_back(0);
		number_points = 1;
		for (int j = 0; j < nItems; j++) {
			if (j != i)
			{
				lastCount = number_points;
				for (int k = 0; k < lastCount; k++) {
					if (l[j] + BiL[i][k] <= L - l[i] // Testa a combinação do item adicionado e os que ja estavam no padrao
						&&
						(find(BiL[i].begin(), BiL[i].end(), l[j] + BiL[i][k]) == BiL[i].end()) // Verifica se esse ponto existe no vetor 
						)
					{
						BiL[i].push_back(l[j] + BiL[i][k]); //e toma a posicao pos item adicionado
						number_points++;
					}
				}
			}
		}
	}

	//concatena e elimina a duplicidade (ordena/unifica/apaga)
	for (int i = 0; i < nItems; i++) {
		for (int j = 0; j < BiL[i].size(); j++) {
			BL.push_back(BiL[i][j]);
		}
	}


	sort(BW.begin(), BW.end());
	auto last = unique(BW.begin(), BW.end());
	BW.erase(last, BW.end());

	sort(BH.begin(), BH.end());
	auto lastBH = unique(BH.begin(), BH.end());
	BH.erase(lastBH, BH.end());

	sort(BL.begin(), BL.end());
	auto lastBL = unique(BL.begin(), BL.end());
	BL.erase(lastBL, BL.end());
}

void static dominio_Boschetti_2D(vector <int> & indice_itens, int D1, int D2, vector <int> & dim_itens1, vector <int> & dim_itens2) {

	int number_points, lastCount, item_atual;
	vector <vector<int>> BiD1(indice_itens.size()), BiD2(indice_itens.size());

	for (int i = 0; i < indice_itens.size(); i++) {
		item_atual = indice_itens[i];
		BiD1[i].push_back(0);
		number_points = 1;

		if (i > 0
			&&
			(dim_itens1[item_atual] == dim_itens1[item_atual - 1] && dim_itens2[item_atual] == dim_itens2[item_atual - 1])
			)
		{
			BiD1[i] = BiD1[i - 1];
		}
		else
		{
			for (int j = 0; j < indice_itens.size(); j++) {
				int item_aux_atual = indice_itens[j];
				if (j != i)
				{
					lastCount = number_points;
					for (int k = 0; k < lastCount; k++) {
						if (dim_itens1[item_aux_atual] + BiD1[i][k] <= D1 - dim_itens1[item_atual]
							&&
							(find(BiD1[i].begin(), BiD1[i].end(), dim_itens1[item_aux_atual] + BiD1[i][k]) == BiD1[i].end())
							)
						{
							BiD1[i].push_back(dim_itens1[item_aux_atual] + BiD1[i][k]);
							number_points++;
							cout << "item_atual: " << item_atual << endl;
							cout << "item_aux_atual: " << item_aux_atual << endl;
							cout << "BiD1[i][k]: " << BiD1[i][k] << endl;
							cout << "dim_itens1[item_aux_atual]: " << dim_itens1[item_aux_atual] << endl;
						}
					}
				}
			}
		}		
	}
	//concatena e elimina a duplicidade (ordena/unifica/apaga)
	for (int i = 0; i < indice_itens.size(); i++) {
		for (int j = 0; j < BiD1[i].size(); j++) {
			BD1.push_back(BiD1[i][j]);
		}
		cout << endl;
	}

	for (int i = 0; i < indice_itens.size(); i++) {
		item_atual = indice_itens[i];
		BiD2[i].push_back(0);
		number_points = 1;

		if (i > 0
			&&
			(dim_itens1[item_atual] == dim_itens1[item_atual - 1] && dim_itens2[item_atual] == dim_itens2[item_atual - 1])
			)
		{
			BiD1[i] = BiD1[i - 1];
		}
		else
		{
			for (int j = 0; j < indice_itens.size(); j++) {
				int item_aux_atual = indice_itens[j];
				if (j != i)
				{
					lastCount = number_points;
					for (int k = 0; k < lastCount; k++) {
						if (dim_itens2[item_aux_atual] + BiD2[i][k] <= D2 - dim_itens2[item_atual]
							&&
							(find(BiD2[i].begin(), BiD2[i].end(), dim_itens2[item_aux_atual] + BiD2[i][k]) == BiD2[i].end())
							)
						{
							BiD2[i].push_back(dim_itens2[item_aux_atual] + BiD2[i][k]);
							number_points++;
						}
					}
				}
			}
		}
	}
	//concatena e elimina a duplicidade (ordena/unifica/apaga)
	for (int i = 0; i < indice_itens.size(); i++) {
		for (int j = 0; j < BiD2[i].size(); j++) {
			BD2.push_back(BiD2[i][j]);
		}
	}

	sort(BD1.begin(), BD1.end());
	auto last = unique(BD1.begin(), BD1.end());
	BD1.erase(last, BD1.end());

	sort(BD2.begin(), BD2.end());
	auto lastBH = unique(BD2.begin(), BD2.end());
	BD2.erase(lastBH, BD2.end());
}

int packing::cp_solver(int nItems, int W, int H, int L, vector <int>& w, vector <int>& h, vector <int>& l, vector <int>& x, vector <int>& y, vector <int>& z, int domain_option) {

	IloEnv env;
	int feasible = 0;

	try {
		IloModel mdl(env); // Modelo do problema

		// Variaveis do problema
		IloIntVarArray X(env);
		IloIntVarArray Y(env);
		IloIntVarArray Z(env);

		// Dominio sem padroes
		if (domain_option == 1) {
			for (IloInt j = 0; j < nItems; j++) {
				X.add(IloIntVar(env, 0, W - w[j]));
				Y.add(IloIntVar(env, 0, H - h[j]));
				Z.add(IloIntVar(env, 0, L - l[j]));
			}
		}

		// Dominio Padrao Boschetti
		if (domain_option == 2) {	
			IloIntArray BW_Ilo(env);
			IloIntArray BH_Ilo(env);
			IloIntArray BL_Ilo(env);

			dominio_Boschetti(nItems, W, H, L, w, h, l);

			for (int i = 0; i < BW.size(); i++)
				BW_Ilo.add(BW[i]);
			for (int i = 0; i < BH.size(); i++)
				BH_Ilo.add(BH[i]);
			for (int i = 0; i < BL.size(); i++)
				BL_Ilo.add(BL[i]);
			for (IloInt j = 0; j < nItems; j++) {
				X.add(IloIntVar(env, BW_Ilo));
				Y.add(IloIntVar(env, BH_Ilo));
				Z.add(IloIntVar(env, BL_Ilo));
				mdl.add(X[j] + w[j] <= W);
				mdl.add(Y[j] + h[j] <= H);
				mdl.add(Z[j] + l[j] <= L);
			}
		}

		// Restrição de não sobreposição
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

int packing2D::auxiliary_packing2D_solve(vector <int>& indice_itens, int D1, int D2, vector <int>& dim_itens1, vector <int>& dim_itens2, vector <int>& dim_solver1, vector <int>& dim_solver2, int domain_option) {

	IloEnv env;
	int feasible = 1;

	try {
		IloModel mdl(env); //modelo do problema

		//variaveis do problema
		IloIntVarArray X(env);
		IloIntVarArray Y(env);
		int item_atual;

		// Dominio sem padroes
		if (domain_option == 1) {
			for (IloInt j = 0; j < indice_itens.size(); j++) {
				item_atual = indice_itens[j];
				X.add(IloIntVar(env, 0, D1 - dim_itens1[item_atual]));
				Y.add(IloIntVar(env, 0, D2 - dim_itens2[item_atual]));
			}
		}

		// Dominio Padrao Boschetti
		if (domain_option == 2) {
			IloIntArray BD1_Ilo(env);
			IloIntArray BD2_Ilo(env);

			dominio_Boschetti_2D(indice_itens, D1, D2, dim_itens1, dim_itens2);

			for (int i = 0; i < BD1.size(); i++)
				BD1_Ilo.add(BD1[i]);
			for (int i = 0; i < BD2.size(); i++)
				BD2_Ilo.add(BD2[i]);
			for (IloInt j = 0; j < indice_itens.size(); j++) {
				X.add(IloIntVar(env, BD1_Ilo));
				Y.add(IloIntVar(env, BD2_Ilo));
				mdl.add(X[j] + dim_itens1[j] <= D1);
				mdl.add(Y[j] + dim_itens2[j] <= D2);
			}
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
		cp.setParameter(IloCP::TimeLimit, 600);

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
	
	BD1.clear();
	BD2.clear();

	return feasible;
}

int packing2D::pre_process_packing2D_solve(string text, vector <int>& indice_itens, int D1, int D2, int camadas, vector<int>& peso, vector <int>& dim_itens1, vector <int>& dim_itens2, vector <int>& dim_solver1, vector <int>& dim_solver2, int domain_option) {

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
			X.add(IloIntVar(env, 0, (D1 * (camadas - 1)) - dim_itens1[item_atual]));
			Y.add(IloIntVar(env, 0, D2 - dim_itens2[item_atual]));
		}
		// Dominio sem padroes
		if (domain_option == 1) {
			for (int j = 0; j < indice_itens.size(); j++) {
				item_atual = indice_itens[j];
				X.add(IloIntVar(env, 0, (D1 * (camadas - 1)) - dim_itens1[item_atual]));
				Y.add(IloIntVar(env, 0, D2 - dim_itens2[item_atual]));
			}
		}

		// Dominio Padrao Boschetti
		if (domain_option == 2) {
			IloIntArray BD1_Ilo(env);
			IloIntArray BD2_Ilo(env);

			dominio_Boschetti_2D(indice_itens, (D1 * (camadas - 1)), D2, dim_itens1, dim_itens2);

			for (int i = 0; i < BD1.size(); i++)
				BD1_Ilo.add(BD1[i]);
			for (int i = 0; i < BD2.size(); i++)
				BD2_Ilo.add(BD2[i]);
			for (IloInt j = 0; j < indice_itens.size(); j++) {
				item_atual = indice_itens[j];
				X.add(IloIntVar(env, BD1_Ilo));
				Y.add(IloIntVar(env, BD2_Ilo));
				mdl.add(X[j] + dim_itens1[item_atual] <= (D1 * (camadas - 1)));
				mdl.add(Y[j] + dim_itens2[item_atual] <= D2);
			}
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
		cp.setParameter(IloCP::TimeLimit, 600);

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

	BD1.clear();
	BD2.clear();

	return feasible;
}

int soma_2faixas(vector <int>& itens_pesados, int dim_bin_aux1, int dim_bin_aux2, vector <int>& dim_itens_aux1, vector<int> dim_itens_aux2) {
	int soma = 0;
	for (int i = 0; i < itens_pesados.size(); i++) {
		int item_atual = itens_pesados[i];
		soma += dim_itens_aux1[item_atual] * dim_itens_aux2[item_atual];
	}
	cout << "Soma = " << soma << endl;
	if (soma > dim_bin_aux1 * dim_bin_aux2) {
		return -1;
	}
	else{
		return soma;
	}
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

	vector <vector<int>> peso_todos_itens(nItems, vector<int>(dim_bin + 1, 0)), todos_itens_pesados( nItems, vector<int>(dim_bin + 1, 0));

	// Cálculo para encontrar o peso de cada item por faixa
	for (int i = 0; i < nItems; i++){
		for (int f = 2; f < dim_bin + 1; f++) {
			peso_todos_itens[i][f] = floor(dim_itens[i] / (( ((float)dim_bin) / f) + 0.00001));
			if (peso_todos_itens[i][f] > 0) {
				todos_itens_pesados[i][f] = 1;
			}
		}
	}

	// Cálculo para encontrar o valor que máximize o valor de F*
	int fEstrela = 0;
	double soma_fEstrela = 0;
	for (int f = 2; f < dim_bin + 1; f++){

		double soma_f = 0;
		for (int i = 0; i < nItems; i++) {
			soma_f += (peso_todos_itens[i][f] * dim_itens_aux1[i] * dim_itens_aux2[i]);
		}
		soma_f = soma_f / (f - 1);
		cout << "Soma camada[" << f << "]: " << soma_f << endl;
		if (soma_f > soma_fEstrela) {
			fEstrela = f;
			soma_fEstrela = soma_f;
		}
	}
	
	// Separa os índices e pesos dos itens que serão utilizados no modelo 2D
	cout << text << "F* = " << fEstrela << endl;
	for (int i = 0; i < nItems; i++) {
		if (todos_itens_pesados[i][fEstrela] == 1) {
			itens_pesados_Nfaixas.push_back(i);
			peso_Nfaixas[i] = peso_todos_itens[i][fEstrela];
			cout << "Peso Item[" << i << "]: " << peso_Nfaixas[i] << endl;
		}
	}

	peso_todos_itens.clear();
	todos_itens_pesados.clear();

	// Teste para garantir que o somatório dos itens respeitará a restrição
	int soma = 0;
	for (int i = 0; i < nItems; i++) {
		soma += (peso_Nfaixas[i] * dim_itens_aux1[i] * dim_itens_aux2[i]) ;
	}
	cout << "Soma: " << soma << endl;
	cout << "fEstrela - 1: " << fEstrela - 1 << endl;
	cout << "dim_bin_aux1: " << dim_bin_aux1 << endl;
	cout << "dim_bin_aux2: " << dim_bin_aux2 << endl;
	if (soma > (fEstrela - 1) * dim_bin_aux1 * dim_bin_aux2) {
		itens_pesados_Nfaixas = { -1 };
		return -1;
	}
	return fEstrela;
}

int packing::packing_solve(int nItems, int W, int H, int L, vector <int>& w, vector <int>& h, vector <int>& l, vector <int>& x, vector <int>& y, vector <int>& z, int input_domain_option, int input_pre_process) {
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

	switch (input_pre_process){

		// PRE PROCESS 2 FAIXAS //
		case 1:{
			vector <int> itens_largos = {}, itens_altos = {}, itens_profundos = {};
			vector <int> itens_largos_altos = {}, itens_largos_profundos = {}, itens_altos_profundos = {};
			vector<int> aux_vector_ones(nItems, 1);
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

			if (soma_2faixas(itens_largos, H, L, h, l) == -1) {
				cout << "Falha na soma do Pre processamento DUAS FAIXAS [ITENS LARGOS]" << endl;
				return 0;
			}
			if (soma_2faixas(itens_altos, W, L, w, l) == -1) {
				cout << "Falha na soma do Pre processamento DUAS FAIXAS [ITENS ALTOS]" << endl;
				return 0;
			}
			if (soma_2faixas(itens_profundos, W, H, w, h) == -1) {
				cout << "Falha na soma do Pre processamento DUAS FAIXAS [ITENS PROFUNDOS]" << endl;
				return 0;
			}
			if (soma_2faixas(itens_altos_profundos, W, 1, w, aux_vector_ones) == -1) {
				cout << "Falha no Pre processamento -> [ITENS ALTOS E PROFUNDOS]" << endl;
				return 0;
			}
			if (soma_2faixas(itens_largos_profundos, H, 1, h, aux_vector_ones) == -1) {
				cout << "Falha no Pre processamento -> [ITENS LARGOS E PROFUNDOS]" << endl;
				return 0;
			}
			if (soma_2faixas(itens_largos_altos, L, 1, l, aux_vector_ones) == -1) {
				cout << "Falha no Pre processamento -> [ITENS LARGOS E ALTOS]" << endl;
				return 0;
			}
			if (itens_largos.size() > 0 && packing2D::auxiliary_packing2D_solve(itens_largos, H, L, h, l, y, z, input_domain_option) == 0) {
				cout << "Falha no PACKING 2D -> [ITENS LARGOS]" << endl;
				return 0;
			}
			if (itens_altos.size() > 0 && packing2D::auxiliary_packing2D_solve(itens_altos, W, L, w, l, x, z, input_domain_option) == 0) {
				cout << "Falha no PACKING 2D -> [ITENS ALTOS]" << endl;
				return 0;
			}
			if (itens_profundos.size() > 0 && packing2D::auxiliary_packing2D_solve(itens_profundos, W, H, w, h, x, y, input_domain_option) == 0) {
				cout << "Falha no PACKING 2D -> [ITENS PROFUNDOS]" << endl;
				return 0;
			}
			break;
		}
		// PRE PROCESS 3 FAIXAS //
		case 2:{
			vector<int> pesoW(nItems, 0), itens_pesados_3faixasW{};
			vector<int> pesoH(nItems, 0), itens_pesados_3faixasH{};
			vector<int> pesoL(nItems, 0), itens_pesados_3faixasL{};
			classificar_em_3faixas("(W)", nItems, W, pesoW, itens_pesados_3faixasW, H, L, w, h, l);
			if (itens_pesados_3faixasW.size() > 0 && (itens_pesados_3faixasW[0] == -1 || packing2D::pre_process_packing2D_solve("(W)", itens_pesados_3faixasW, H, L, 3, pesoW, h, l, y, z, input_domain_option) == 0)) {
				cout << "Falha no PACKING 2D -> DISCRETIZACAO 3 faixas (W)" << endl;
				return 0;
			}

			classificar_em_3faixas("(H)", nItems, H, pesoH, itens_pesados_3faixasH, W, L, h, w, l);
			if (itens_pesados_3faixasH.size() > 0 && (itens_pesados_3faixasH[0] == -1 || packing2D::pre_process_packing2D_solve("(H)", itens_pesados_3faixasH, W, L, 3, pesoH, w, l, x, z, input_domain_option) == 0)) {
				cout << "Falha no PACKING 2D -> DISCRETIZACAO 3 faixas (H)" << endl;
				return 0;
			}

			classificar_em_3faixas("(L)", nItems, L, pesoL, itens_pesados_3faixasL, W, H, l, w, h);
			if (itens_pesados_3faixasL.size() > 0 && (itens_pesados_3faixasL[0] == -1 || packing2D::pre_process_packing2D_solve("(L)", itens_pesados_3faixasL, W, H, 3, pesoL, w, h, x, y, input_domain_option) == 0)) {
				cout << "Falha no PACKING 2D -> DISCRETIZACAO 3 faixas (L)" << endl;
				return 0;
			}
			break;
		}
		// PRE PROCESS N FAIXAS //
		case 3:{
			vector <int> pesoW_Nfaixas(nItems, 0), itens_pesadosW_Nfaixas{};
			vector <int> pesoH_Nfaixas(nItems, 0), itens_pesadosH_Nfaixas{};
			vector <int> pesoL_Nfaixas(nItems, 0), itens_pesadosL_Nfaixas{};
			int camadas = classificar_em_Nfaixas("(W)", nItems, W, pesoW_Nfaixas, itens_pesadosW_Nfaixas, H, L, w, h, l);
			if (itens_pesadosW_Nfaixas.size() > 0 && (itens_pesadosW_Nfaixas[0] == -1 || packing2D::pre_process_packing2D_solve("(W)", itens_pesadosW_Nfaixas, H, L, camadas, pesoW_Nfaixas, h, l, y, z, input_domain_option) == 0)) {
				cout << "Falha no PACKING 2D -> DISCRETIZACAO " << camadas << " faixas (W)" << endl;
				return 0;
			}

			camadas = classificar_em_Nfaixas("(H)", nItems, H, pesoH_Nfaixas, itens_pesadosH_Nfaixas, W, L, h, w, l);
			if (itens_pesadosH_Nfaixas.size() > 0 && (itens_pesadosH_Nfaixas[0] == -1 || packing2D::pre_process_packing2D_solve("(H)", itens_pesadosH_Nfaixas, W, L, camadas, pesoH_Nfaixas, w, l, x, z, input_domain_option) == 0)) {
				cout << "Falha no PACKING 2D -> DISCRETIZACAO " << camadas << " faixas (H)" << endl;
				return 0;
			}

			camadas = classificar_em_Nfaixas("(L)", nItems, L, pesoL_Nfaixas, itens_pesadosL_Nfaixas, W, H, l, w, h);
			if (itens_pesadosL_Nfaixas.size() > 0 && (itens_pesadosL_Nfaixas[0] == -1 || packing2D::pre_process_packing2D_solve("(L)", itens_pesadosL_Nfaixas, W, H, camadas, pesoL_Nfaixas, w, h, x, y, input_domain_option) == 0)) {
				cout << "Falha no PACKING 2D -> DISCRETIZACAO " << camadas << "faixas(L)" << endl;
				return 0;
			}
			break;
		}
		default:
			cout << "SEM PRE PROCESSAMENTOS" << endl;
			break;
	}

	feasible = cp_solver(nItems, W, H, L, w, h, l, x, y, z, input_domain_option);
	return feasible;
}
