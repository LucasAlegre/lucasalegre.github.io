#include <iostream>
#include <list>
using namespace std;
 
// Grafo não direcionado
class Graph
{
    int V;    // Numero de vértices
    list<int> *adj;    // Lista de adjacências
public:
    Graph(int V)   { this->V = V; adj = new list<int>[V]; }
    ~Graph()       { delete [] adj; }
 
    // Adiciona aresta entre vértices v e w
    void addEdge(int v, int w);
 
    // Printa coloração greedy
    void greedyColoring();
};
 
void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
    adj[w].push_back(v);
}
 
// Colore os vértices (começando do 0) e printa o resultado
void Graph::greedyColoring()
{
    int result[V];
 
    // Vertice 0 recebe cor 0
    result[0]  = 0;
 
    // Inicializa os V-1 vertices
    for (int u = 1; u < V; u++)
        result[u] = -1;  // -1 representa que o vertice nao foi colorido
 
    // Array temporario que guarda cores disponiveis
    // available[cr] true significa que algum vertice adjacente possui cor cr
    bool available[V];
    for (int cr = 0; cr < V; cr++)
        available[cr] = false;
 
    // Colore V-1 vertices restantes
    for (int u = 1; u < V; u++)
    {
        list<int>::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        
        // COMPLETE AQUI !
 
        result[u] = cr; // Vertice u recebe cor cr
 
        // Reseta os valores para falso na próxima iteração
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
            if (result[*i] != -1)
                available[result[*i]] = false;
    }
 
    // printa a coloração
    for (int u = 0; u < V; u++)
        cout << "Vertex " << u << " --->  Color "
             << result[u] << endl;
}
 

int main()
{
    Graph g1(5);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 2);
    g1.addEdge(1, 3);
    g1.addEdge(2, 3);
    g1.addEdge(3, 4);
    cout << "Colorindo Grafo 1 \n";
    g1.greedyColoring();
 
    Graph g2(5);
    g2.addEdge(0, 1);
    g2.addEdge(0, 2);
    g2.addEdge(1, 2);
    g2.addEdge(1, 4);
    g2.addEdge(2, 4);
    g2.addEdge(4, 3);
    cout << "\nColorindo Grafo 2 \n";
    g2.greedyColoring();
 
    return 0;
}