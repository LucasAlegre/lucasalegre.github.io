#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Grafo {
private:
    int V;  // Número de vértices
    vector<vector<int>> adj;  // Lista de adjacência

public:
    // Construtor
    Grafo(int V) {
        this->V = V;
        adj.resize(V);
    }

    // Adiciona uma aresta não-direcionada
    void adicionarAresta(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Algoritmo de coloração gulosa
    void colorirGuloso() {
        vector<int> resultado(V, -1); // -1 indica que ainda não foi colorido
        resultado[0] = 0; // Primeiro vértice recebe a primeira cor

        vector<bool> disponivel(V, true); // Cores disponíveis

        // Colorir os demais vértices
        for (int u = 1; u < V; ++u) {
            
            // COMPLETAR AQUI

            // Resetar disponibilidade para o próximo vértice
            for (int vizinho : adj[u]) {
                if (resultado[vizinho] != -1)
                    disponivel[resultado[vizinho]] = true;
            }
        }

        // Exibir as cores atribuídas
        for (int u = 0; u < V; ++u)
            cout << "Vértice " << u << " ---> Cor " << resultado[u] << endl;
    }
};

int main() {

    Grafo g1(5);
    g1.adicionarAresta(0, 1);
    g1.adicionarAresta(0, 2);
    g1.adicionarAresta(1, 2);
    g1.adicionarAresta(1, 3);
    g1.adicionarAresta(2, 3);
    g1.adicionarAresta(3, 4);
    cout << "Colorindo Grafo 1 \n";
    g1.colorirGuloso();
 
    Grafo g2(5);
    g2.adicionarAresta(0, 1);
    g2.adicionarAresta(0, 2);
    g2.adicionarAresta(1, 2);
    g2.adicionarAresta(1, 4);
    g2.adicionarAresta(2, 4);
    g2.adicionarAresta(4, 3);
    cout << "\nColorindo Grafo 2 \n";
    g2.colorirGuloso();
    return 0;
}
