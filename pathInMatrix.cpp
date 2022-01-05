//
// Created by 李思 on 2022/1/5.
//

#include "vector"
#include "string"

using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
       row = board.size();
       col = board[0].size();
       //vector<vector<bool>> visited(row, vector<bool> (col, false));

       for(int i = 0; i < row; i++){
           for(int j = 0; j < col; j++){
               if( dfs(board, word, i, j,0)) return true;

           }

       }
       return false;
    }

    void dfs(vector<vector<char>> &board, string word, int i, int j, int idx, vector<vector<bool>> &visited){
        // 超时
        if(i < 0 || i >= row || j < 0 || j >= col || board[i][j] != word[idx] || !visited[i][j]) return;
        if(idx == word.size() - 1) {target = true; return;}

        visited[i][j] = false;
        dfs(board, word, i+1, j, idx+1, visited);
        dfs(board, word, i-1, j, idx+1, visited);
        dfs(board, word, i, j-1, idx+1, visited);
        dfs(board, word, i, j+1, idx+1, visited);
        visited[i][j] = true;

    }

    bool dfs(vector<vector<char>> &board, string word, int i, int j, int idx){
        if(i < 0 || i >= row || j < 0 || j >= col || board[i][j] != word[idx]) return false;
        if(idx == word.size() - 1) return true;
        board[i][j] = '\0';
        bool ret = dfs(board, word, i+1, j, idx+1) ||
                dfs(board, word, i-1, j, idx+1) ||
                dfs(board, word, i, j-1, idx+1) ||
                dfs(board, word, i, j+1, idx+1);
        board[i][j] = word[idx];
        return ret;

    }

private:
    int row;
    int col;
    bool target = false;
};




