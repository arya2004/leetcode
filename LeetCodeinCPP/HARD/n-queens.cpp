#include <algorithm>
#include <array>
#include <bitset>
#include <deque>
#include <forward_list>
#include <functional>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
// check for W, NW, SW dir only
bool isSafe(int row, int col, vector<string> &board, int n ){
    // NW
    int duprow = row;
    int dupcol = col;

    while (row >= 0 && col >= 0 )
    {
        if(board[row][col] == 'Q') return false;
        row--;
        col--;
    }
    // W
    row = duprow;
    col = dupcol;
    while (col >= 0)
    {
       if(board[row][col] == 'Q') return false;
        col--;
    }
    // SW
    row = duprow;
    col = dupcol;
    while (col >= 0 && row < n )
    {
       if(board[row][col] == 'Q') return false;
        col--;
        row++;
    }

    return true;
    
    
}

void solve(int col, vector<string> &board, vector<vector<string>> &ans, int n){
    if(col == n){
        ans.push_back(board);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if(isSafe(row,col,board,n)){
            board[row][col] = 'Q';
            solve(col + 1, board, ans, n);
            board[row][col] = '.';
        }
    }
    
}

 vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> answer;
        vector<string> board(n);
        string s(n, '.');
        for (int i = 0; i < n; i++)
        {
            board[i] = s;
        }

        solve(0, board, answer, n);
        return answer;
        
    }
int main()
{
    vector<int> v = {1,2,3,4,5};

    return 0;
}