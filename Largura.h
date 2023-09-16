#define LARGURA

#include <iostream>
#include <vector>
#include <queue>

using namespace std;


// Função para realizar a busca em largura
void buscaLagura(vector<vector<int>>& grafo, int inicial, int objetivo) {
   vector <int> pai;
   queue <int> fila;

   fila.push(inicial);
   pai[inicial] = inicial;

    cout<< "work";
   while(!fila.empty()){
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
        return;
    }
    
    for (int i = 0; i < grafo.size(); i++) {
        if(grafo[i][0] == atual){
                fila.push(grafo[i][1]);
                cout << grafo[i][1];
            }
    }
    


   }




}


