#include <iostream>
#include <fstream>
#include <vector>
#include <stack>

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
    ifstream arquivo("grafo.txt");
    int m = 0, n = 0, objetivo;
    int inicial, linha = 1, numero;
    vector<vector<int>> grafo;

    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo." << endl;
        return 1;
    }

    while (arquivo >> numero) {
        if (m == 0) {
            m = numero;
        } else if (n == 0) {
            n = numero;
        } else if (linha < 2) {
            grafo.push_back({numero});
        } else {
            if (grafo.empty() || grafo.back().size() == 3) {
                grafo.push_back({numero});
            } else {
                grafo.back().push_back(numero);
            }
        }
        linha++;
    }
    arquivo.close();

    cout << "Digite o valor do estado inicial\n";
    cin >> inicial;
    system("cls");
    cout << "Digite o valor do estado objetivo\n";
    cin >> objetivo;
    system("cls");


/////////////////////////////////////////////////////////////////////////////

    vector<int> pai(m, -1);
    stack<int> pilha;
    pilha.push(inicial);

    while (!pilha.empty()) {
        int atual = pilha.top();
        pilha.pop();

        if (atual == objetivo) {
            vector<int> caminho;
            while (atual != -1) {
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
            if (grafo[i][0] == atual && pai[grafo[i][1]] == -1) {
                pai[grafo[i][1]] = atual;
                pilha.push(grafo[i][1]);
                cout << pilha.top();
            }
        }
    }

    cout << "Nao foi encontrado um caminho de " << inicial << " para " << objetivo << endl;

    return 0;
}
