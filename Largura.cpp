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
    ifstream arquivo("grafo.txt"); // Substitua "seuarquivo.txt" pelo nome do seu arquivo
    int m = 0, n = 0, objetivo;
    int inicial, linha = 1 , numero;
    vector<vector<int>> grafo;
    


    if (!arquivo.is_open()) {
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
            else if (grafo.empty() || grafo.back().size() == 3) {
                    grafo.push_back({numero});
                } else {
                    grafo.back().push_back(numero);
                }
            
            linha++;
        }
    arquivo.close();
  

   

    // Imprimir os grafo de três números restantes
   /* cout<< m << endl;
    cout<< n << endl;
    for (size_t i = 0; i < grafo.size(); i++) {
        for (size_t j = 0; j < grafo[i].size(); j++) {
            cout << " " << grafo[i][j];
        }
      cout << std::endl;
    }*/

    
    cout<< "Digite o valor do estado inicial\n";
	    cin >> inicial;
	system("cls");
	cout<< "Digite o valor do estado objetivo\n";
	    cin >> objetivo;
	system("cls");

    
    
/////////////////////////////////////////////////////////////////
    int pai [m];
    queue <int> fila;
    fila.push(inicial);
    pai[inicial] = -1;
    vector <int> visitados(m,0);
    
   

    while (!fila.empty()) {
    int atual = fila.front();
    fila.pop();

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
    for (int i = 0; i < grafo.size(); i++) {
        if (grafo[i][0] == atual && !busca(grafo[i][1], visitados)) {         // Se o valor não estiver em visitados, adicione-o e atualize o pai.
            fila.push(grafo[i][1]);
            pai[grafo[i][1]] = atual; // Atualize o pai do nó visitado.
            visitados[atual] = atual;
            
        }
    }
}

cout << "Nao foi encontrado um caminho de " << inicial << " para " << objetivo << endl;

return 0;
}
