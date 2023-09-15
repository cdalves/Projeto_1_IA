#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main() {
    std::ifstream arquivo("grafo.txt"); // Substitua "seuarquivo.txt" pelo nome do seu arquivo
    int m = 0, n = 0;

    if (!arquivo.is_open()) {
        std::cerr << "Erro ao abrir o arquivo." << std::endl;
        return 1;
    }

    std::vector<std::vector<int>> grafo;
    int linha = 1;
    int numero;

    while (arquivo >> numero) {
        if(m == 0)
            m = numero;
            else if(n == 0)
                 n = numero;

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

    return 0;
}
