#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <algorithm>

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
    int inicial, numero;
    vector<vector<int>> listadj;

    if (!arquivo.is_open()) {
        cerr << "Erro ao abrir o arquivo." << endl;
        return 1;
    }

    while (arquivo >> numero) {
        if (m == 0) {
            m = numero; // Number of nodes
        } else if (n == 0) {
            n = numero; // Number of edges
        } else if (listadj.empty() || listadj.back().size() == 3) {
            listadj.push_back({numero});
        } else {
            listadj.back().push_back(numero);
        }
    }
    arquivo.close();

    // Create an adjacency matrix
    vector<vector<int>> grafo(m + 1, vector<int>(m + 1, 0));

    for (int i = 0; i < listadj.size(); i++) {
        grafo[listadj[i][0]][listadj[i][1]] = listadj[i][2];
        grafo[listadj[i][1]][listadj[i][0]] = listadj[i][2]; // Assuming an undirected graph
    }

    // Print the adjacency matrix
    cout << "Adjacency Matrix:" << endl;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            cout << " " << grafo[i][j];
        }
        cout << endl;
    }

    cout << "Digite o valor do estado inicial:" << endl;
    cin >> inicial;
    cout << "Digite o valor do estado objetivo:" << endl;
    cin >> objetivo;

    int pai[m + 1];
    queue<int> avisitar;
    avisitar.push(inicial);
    pai[inicial] = -1;
    vector<int> visitados(m + 1, 0);

    while (!avisitar.empty()) {
        int atual = avisitar.front();
        avisitar.pop();

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

        for (int i = 1; i <= m; i++) {
            if (grafo[atual][i] != 0 && visitados[i] == 0) {
                avisitar.push(i);
                pai[i] = atual;
                visitados[i] = 1;
            }
        }
    }

    cout << "Nao foi encontrado um caminho de " << inicial << " para " << objetivo << endl;

    return 0;
}
