#include <iostream>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;



int main(){
    int m = 0; //número de nós
    int n = 0; //número de arestas
    vector<vector<string>> grafo; //recebe os dados do grafo.txt
    float gs = 0; // salva o peso entre os nós 
    char o[500];
    vector <string> a;
    FILE* arquivo = fopen("grafo.txt","r");
    
    if (arquivo)
    {
        while (!feof(arquivo))
        {
            fgets(o,500 , arquivo);
            a.push_back(o);            
        }
    
    for(int x= 0; x <= a.size(); x++){
        cout<<a[x];
    }
        
        
    }
    
        
    
    
    
    
  

    


    return 0;
}