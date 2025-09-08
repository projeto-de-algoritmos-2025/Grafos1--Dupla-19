class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        //defino o número de nós e se caso existir só 1 nó retorno 0 pois não tem o que percorrer
        int n = graph.size();
        if (n == 1) return 0;

        int Maks = (1 << n) - 1;

        //aqui guardo na fila q o nó atual, a máscara de nós visitados e a distância percorrida. O visited guarda os pares de (nó, máscara) que já foram visitados
        queue<tuple<int, int, int>> q;
        set<pair<int, int>> visited;

        //para cada nó i, crio uma máscara e coloco na fila o nó i, a máscara e a distância 0, e marco como visitado
        for (int i = 0; i < n; i++) {
            int mask = 1 << i;
            q.push({i, mask, 0});
            visited.insert({i, mask});
        }

        //enquanto a fila não estiver vazia pego o primeiro elemento da fila, removo ele da fila e pego o node, a máscara e a distância
        while (!q.empty()){
            auto [node, mask, dist] = q.front();
            q.pop();

            //se a máscara atual fica igual a Maks que são todos os nós visitados retorno a distância percorrida sendo esse o menor caminho
            if (mask == Maks) return dist;

            //para cada vizinho do node, crio uma nova máscara com o vizinho visitado, se o par (vizinho, nova máscara) não tiver sido visitado ainda, marco como visitado e coloco na fila o vizinho, a nova máscara e a distância + 1
            for (int neighbor : graph[node]) {
                int newMask = mask | (1 << neighbor);
        
                if (!visited.count({neighbor, newMask})) {
                    visited.insert({neighbor, newMask});
                    q.push({neighbor, newMask, dist + 1});
                }
            }
        }
        //se acabar a busca em largura e não tiver achado o objetivo, retorno -1
        return -1;
    }
};