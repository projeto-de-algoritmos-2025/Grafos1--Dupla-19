#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>

using namespace std;

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        //Converte em String
        string target = "123450";
        string current_board_str = "";
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                current_board_str += to_string(board[i][j]);
            }
        }

        // Se ja tiver resolvido, retorna 1
        if (current_board_str == target) {
            return 1;
        }

        // Cria a fila e mapeia os vizinhos
        queue<pair<string, int>> q;
        q.push({current_board_str, 0});
        vector<vector<int>> neighbors = {
            {1, 3},
            {0, 2, 4},
            {1, 5},
            {0, 4},
            {1, 3, 5},
            {2, 4}
        };

        while (!q.empty()) {
            string current = q.front().first;
            int moves = q.front().second;
            q.pop();

            if (current == target) {
                return moves;
            }
            
            int zero_pos = current.find('0');
            for (int neighbor_pos : neighbors[zero_pos]) {
                string next_state = current;
                swap(next_state[zero_pos], next_state[neighbor_pos]);
                q.push({next_state, moves + 1});
            }
        }
        
        return -1;
    }
};
