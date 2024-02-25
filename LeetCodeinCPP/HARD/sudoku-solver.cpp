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


bool isValid(vector<vector<char>>& board, int row, int col, char c){
    for (int i = 0; i < 9; i++)
    {
        if(board[row][i] == c) return false;
        if(board[i][col] == c) return false;
        if(board[3*(row/3) + i/3][3*(col/3) + i%3] == c) return false;
    }
    return true;
}

bool solve(vector<vector<char>>& board){
    for (int i = 0; i < board.size(); i++)
    {
        for (int j = 0; j < board[0].size(); j++)
        {
            if(board[i][j] == '.'){
               
               for(char c = '1'; c <= '9'; c++){
                    if(isValid(board, i , j, c)){
                        board[i][j] = c;
                        if(solve(board)) return true;
                        else board[i][j] = '.'; //backtrack
                    }
               }
               return false;
            }
        }
        
    }
    return true;
    
}

void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
int main()
{
    vector<int> v = {1,2,3,4,5};

    return 0;
}