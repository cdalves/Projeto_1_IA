#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

#include "largura.h"

using namespace std;


int main() {
    ifstream arquivo("grafo.txt"); // Substitua "seuarquivo.txt" pelo nome do seu arquivo
    int m = 0, n = 0, objetivo;
    int atual, inicial, linha = 1 , numero;
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
            else if (linha < 2) {
                // Armazenar os dois primeiros números em uma linha separada
                grafo.push_back({numero});
            } else {
                // Armazenar os números restantes em grafo de três
                if (grafo.empty() || grafo.back().size() == 3) {
                    grafo.push_back({numero});
                } else {
                    grafo.back().push_back(numero);
                }
            }
            linha++;
        }
    arquivo.close();
  

    cout<< m << endl;
    cout<< n << endl;

    // Imprimir os grafo de três números restantes
    for (size_t i = 0; i < grafo.size(); i++) {
        for (size_t j = 0; j < grafo[i].size(); j++) {
            cout << " " << grafo[i][j];
        }
      cout << std::endl;
    }
    cout<< "Digite o valor do estado inicial\n";
	    cin >> inicial;
	system("cls");
	cout<< "Digite o valor do estado objetivo\n";
	    cin >> objetivo;
	system("cls");

    
    
/////////////////////////////////////////////////////////////////
    vector <int> pai;
    queue <int> fila;
    
   fila.push(inicial);
   cout<< "work";
   pai[inicial] = inicial;
    
   

   while(true){
    int atual = fila.front();
    fila.pop();

    if(atual == objetivo){
        vector <int> caminho, filhos;

        while(atual!= inicial){
            caminho.push_back(atual);
            atual = pai[atual];
        }
        caminho.push_back(inicial);

        cout<< "caminho de " << inicial << " para " << objetivo << " : ";
        for(int i = caminho.size()-1; i>= 0; i++){
            cout << caminho[i];
            if(i != 0 )
                cout<< " -> ";
        }
        cout << endl;
        
    }
    
    for (int i = 0; i < grafo.size(); i++) {
        if(grafo[i][0] == atual){
                fila.push(grafo[i][1]);
                cout << grafo[i][1];
            }
    }
    


   }
             

return 0;
}
