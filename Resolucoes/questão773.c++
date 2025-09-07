#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>

using namespace std;

class Solution {
public:
    int slidingPuzzle(vector<vector<int>>& board) {
       //Converte em string
        string target = "123450";
        string current_board_str = "";
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                current_board_str += to_string(board[i][j]);
            }
        }

        // Se já estiver resolvido retorna 0
        if (current_board_str == target) {
            return 0;
        }
        
        int zero_pos = current_board_str.find('0');
        int moves = 0;
        
        return -1;
    }
};