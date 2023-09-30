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



class MyStack {
    queue<int> q ;
public:
    
    MyStack() {
    
    }
 
   
    
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
       return  q.front();
    }
    
    bool empty() {
       return  q.empty();
    }

};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */