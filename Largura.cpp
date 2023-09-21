#include <iostream>
#include <fstream>
#include <vector>
#include <queue>

using namespace std;


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
    
/////////////////////  algotitimo de busca em largura  /////////////////////

    vector <int> pai(m,-1);
    queue <int> avisitar;
    avisitar.push(inicial);
    pai[inicial] = -1;
    vector <int> visitados(m,0);
      

    while (!avisitar.empty()) {
    int atual = avisitar.front();
    avisitar.pop();

    if (atual == objetivo) { // verifica se ja chegou ao destino
        vector<int> caminho;

        while (atual != -1) { // cria a caminho ate chegar ao objetivo
            caminho.push_back(atual);
            atual = pai[atual];
        }

        cout << "Caminho de " << inicial << " para " << objetivo << ": ";
        for (int i = caminho.size() - 1; i >= 0; i--) {
            cout << caminho[i];
            if (i != 0)
                cout << " -> ";
        }
        cout << endl;
        return 0;
    }

    for (int i = 1; i <= m; i++) { // percorre a matriz e enconta os nos filhos
            if (grafo[atual][i] != 0 && pai[i] == -1) {
                avisitar.push(i);
                pai[i] = atual;                
                cout << "Visitando o no: " << i << endl;
            }
        }
}

cout << "Nao foi encontrado um caminho de " << inicial << " para " << objetivo << endl;
 
return 0;
}
