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


  queue<int>  q;
   
    
    void push(int x) {
        q.push(x);
        for (int i = 1; i < q.size(); i++)
        {
           q.push(q.front());
           q.pop();
        }
        
    }
    
    int pop() {
        int a = q.front();
        q.pop();
        return a;
    }
    
    int top() {
        q.front();
    }
    
    bool empty() {
        q.empty();
    }
int main()
{
    return 0;
}