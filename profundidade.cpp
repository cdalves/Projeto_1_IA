#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

using namespace std;

// Busca em Profundidade

int main() {
    ifstream arquivo("grafo.txt"); // Substitua "seuarquivo.txt" pelo nome do seu arquivo
    int m = 0 , n=0 , objetivo;
    int inicial, numero;
    vector<vector<int>> listadj;  
  
    if(!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo." << endl;
        return 1;
    }
   
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

    for(int i = 0; i < listadj.size(); i++) {
            grafo[listadj[i][0]][listadj[i][1]] = listadj[i][2];
    }   

    // Imprimir os grafo de três números restantes
    cout<< m << endl;
    cout<< n << endl;
    for (int i = 1; i < m+1 ; i++) {
        for (int j = 1; j < m+1; j++) {
            cout << " " << grafo[i][j]; 
        }
      cout << endl;
    }

    cout<< "Digite o valor do estado inicial\n";
	    cin >> inicial;
	cout<< "Digite o valor do estado objetivo\n";
	    cin >> objetivo;
    cin.ignore();
    
////////////////////////////////////////////////////////////////

    vector <int> pai(m,-1);
    stack <int> avisitar;
    avisitar.push(inicial);
      

    while (!avisitar.empty()) {
    int atual = avisitar.top();
    avisitar.pop();

    if (atual == objetivo) {
        vector<int> caminho;

        while (atual != -1) { // A raiz do caminho será -1.
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

    for (int i = 1; i <= m; i++) {
            if (grafo[atual][i] != 0 && pai[i] == -1) {
                pai[i] = atual;
                avisitar.push(i);
                cout << "Visitando o no: " << avisitar.top() << endl;
            }
        }
}

cout << "Nao foi encontrado um caminho de " << inicial << " para " << objetivo << endl;
 
return 0;
}
