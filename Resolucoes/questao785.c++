#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        //defino o número de nós e guardo a cor do nó no vetor color
        int n = graph.size();
        vector<int> color(n, -1);

        //crio o start como sendo meu nó, para cada nó start que não foi colorido faço uma busca em largura, caso já esteja colorido pulo para o próximo
        for (int start = 0; start < n; start++) {
            if (color[start] != -1) continue;

            //crio uma fila para busca em largura, coloco um nó de inicio e defini ele com a cor 0
            queue<int> q;
            q.push(start);
            color[start] = 0;

            //verifico se a fila tá vazia, enquanto não estiver vazia pego o node que é o primeiro elemento da fila, removo ele da fila e verifico cada vizinho do node
            while (!q.empty()) {
                int node = q.front();
                q.pop();

                //verifico 2 casos:
                for (int neighbor : graph[node]) {
                    //se o vizinho ainda não foi colorido, colorimos com a cor oposta do node e coloca o vizinho na fila
                    if (color[neighbor] == -1) {
                        color[neighbor] = 1 - color[node];
                        q.push(neighbor);
                    //se o vizinho já estiver colorido, verifico se a cor é igual a do node, se for igual retorno falso pois o grafo não pode ser bipartido se viznhos possuirem a mesma cor
                    } else if (color[neighbor] == color[node]) {
                        return false;
                    }
                }
            }
        }
        //se colorir todo o grafo sem encontrar vizinhos com a mesma cor retorna true pois então o grafo é bipartido
        return true;
    }
};