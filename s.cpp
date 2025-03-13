#include <bits/stdc++.h>
using namespace std;

void pairs(){

    pair<int, int> p = {1,3};

    cout << p.first << " " << p.second;

    pair<int, pair<int,int>> pp = {1, {2,3}};

    pair<int, int> arr[] = {{1,2}, {4,4}, {5,6}};
    cout << arr[1].second;

}

void vec(){

    vector<int> v;

    v.push_back(1);
    v.emplace_back(2);

    vector<pair<int, int>> ve;
    ve.push_back({1,2});
    ve.emplace_back(1,2); 

    vector<int> v(5,100);
    vector<int> v(5);
    vector<int> v2(v); //copy

    //iterator
    cout << v[1];
    cout << v.back() << "" ;

    for (auto it : v)
    {
        cout << it << "";
    }
    //erase
    v.erase(v.begin() + 1);

    //insert
    v.insert(v.begin(), 33);
    v.pop_back();

    //size
    cout << v.size();    
    v.clear();



}



void lists(){

    list<int> ls;
    ls.push_back(4);
    ls.emplace_back(4);
    ls.push_front(3);
    ls.emplace_front(4);
    
}

void dequeue(){ 
    deque<int> dq;
    dq.push_back(1);
    dq.emplace_back(3);
    dq.push_front(3);
    dq.emplace_front(3);

    dq.pop_back();

    dq.front();
    dq.back();
}

void stacc(){
    stack<int> st;
    st.push(3);
    cout << st.top();

    st.pop();
    //bool isEmpty
    st.empty();
}

void q(){
    queue<int> q;
    q.push(3);
    q.pop();

    q.front();
}


int main(){

     int num =  7;
    int cnt = __builtin_popcount(num);
    cout << cnt;

    
    return 0;
}