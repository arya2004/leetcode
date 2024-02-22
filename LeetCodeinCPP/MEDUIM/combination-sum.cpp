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
//TC = (2^t)*k
//Sc = k * X


void findCombination(int index, vector<int>& candidates, int target, vector<vector<int>>& answer, vector<int>& single){
    if(index == candidates.size()){
        if(target == 0){
            answer.push_back(single);
        }
        return;
    }
    if( candidates[index] <= target){
        single.push_back(candidates[index]);
        findCombination(index, candidates, target - candidates[index], answer, single);
        single.pop_back();
    }
    findCombination(index + 1, candidates, target, answer, single);
}

vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> answer;
        vector<int> single;
        findCombination(0, candidates,target, answer, single );
        return answer;  
    }


int main()
{
    return 0;
}