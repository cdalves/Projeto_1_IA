#include <iostream>
#include <vector>
#include <string>
#include <cstdio>
#include <cstdlib>

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
            fgets(o,500, arquivo);
            a.push_back(o);
           
        }
        m = stoi(a[0]);
        n = stoi(a[1]);


    
    for(int x= 0; x <= a.size(); x++){
        cout<<a[x]<< endl;
    }
        cout << m << endl;
        cout << n << endl;

        
    }
    
        
    
    
    
    
  

    


    return 0;
}