#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;

bool busca(int valor, vector<int> lista) {
    for (int i = 0; i < lista.size(); i++) {
        if (lista[i] == valor) {
            return true;
        }
    }
    return false; 
}

int main() {
     ifstream arquivo("grafo.txt"); // cria um ponteiro para acessar o arquivo de texto
    int m = 0 , n=0 , objetivo;
    int inicial, numero;
    vector<vector<int>> listadj;  
  
   // indentifica se or arquivo foi aberto corretamente
    if(!arquivo.is_open()) { // 
        cerr << "Erro ao abrir o arquivo." << endl;
        return 1;
    }
   
   // salva o arquivo em um vetor no formato desejado
    while (arquivo >> numero) {
        if(m == 0){ // salva o numero de nós
            m = numero;
        }   
            else if(n == 0){ // salva o numero de arestas
                 n = numero;
            }
            else if (listadj.empty() || listadj.back().size() == 3) { 
                    listadj.push_back({numero});
                    
                }else {
                listadj.back().push_back(numero);
            }
         
    }
    arquivo.close();
 
    int grafo[m+1][m+1] = {0};

    // tranforma a lista de adjacência em matriz de adjacência
    for(int i = 0; i < listadj.size(); i++) {
            grafo[listadj[i][0]][listadj[i][1]] = listadj[i][2];
    }   

    // // Imprimir a matriz
    // cout<< m << endl;
    // cout<< n << endl;
    // for (int i = 1; i < m+1 ; i++) {
    //     for (int j = 1; j < m+1; j++) {
    //         cout << " " << grafo[i][j]; 
    //     }
    //   cout << endl;
    // }

    // solicita ao usuario o no de inicio e de fim
    cout<< "Digite o valor do estado inicial\n";
	    cin >> inicial;
	cout<< "Digite o valor do estado objetivo\n";
	    cin >> objetivo;
    cin.ignore();

///////////////////// Busca Uniforme /////////////////////////

    int pai [m];
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> avisitar;
    avisitar.push({0, inicial});
    pai[inicial] = -1;
    vector<int> visitados(m,0), vizinhos;

    while (!avisitar.empty()) {
        pair<int, int> atual = avisitar.top();
        avisitar.pop();

        if (atual.second == objetivo) {
            vector<int> caminho;
            int custofinal = atual.first;

            while (atual.second != -1) { // cria a caminho ate chegar ao objetivo
                caminho.push_back(atual.second);
                atual.second = pai[atual.second];
            }

            cout << "Caminho de " << inicial << " para " << objetivo << ": ";
            for (int i = caminho.size() - 1; i >= 0; i--) {
                cout << caminho[i];
                if (i != 0)
                    cout << " -> ";
            }
            cout << endl;
            cout << "Custo total do percurso: "<< custofinal << endl;
            return 0;
        }

        for (int i = 1; i <= m; i++) {
            if (grafo[atual.second][i] != 0 && !busca(i, visitados)) {
                avisitar.push({atual.first + grafo[atual.second][i], i});
                pai[i] = atual.second;
                cout << "Visitando o no: " << i << ", custo: " << atual.first + grafo[atual.second][i] << endl;
                visitados.push_back(i);
            }
        }
    }

    cout << "Nao foi encontrado um caminho de " << inicial << " para " << objetivo << endl;
 
    return 0;
}
