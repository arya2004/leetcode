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


struct ListNode {
     int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
  };

using namespace std;

void io()
{
    int a;
    cin >> a;
    cout << a;
    cout << "a";
}

void Pairs(){
    //in utility lib
    pair<int, int> p = {3,4};
    cout << p.first << p.second;

    pair<int, pair<int, char>> lel;
    cout << lel.second.first;

    pair<int, int> arr[] = {{1,2},{4,5}};
    cout << arr[1].first;

}

void Vectors()
{
    vector<int> v;

    v.push_back(1); // adds 1 at last
    v.emplace_back(1);  // same but faster

    vector<pair<int,int>> vec;

    vec.push_back({1,2});
    vec.emplace_back(1,2);

    vector<int> V(5,100); // vector of size 5 with 100
    vector<int> V1(5); // vector of size 5 with 0/garbag
    vector<int> V2(V1); //copy of V!


    cout << v[0];

    //iterator points at memory adress
    //similar to pointer
    vector<int>::iterator it = v.begin();
    it++;
    cout << *(it); 

    vector<int>::iterator itt = v.end(); //points after last element
    // vector<int>::iterator itw = v.rend(); not used
    // vector<int>::iterator itr = v.rbegin();

    cout << v.back(); //last elemn

        //iterate
    for (int i = 0; i < v.size(); i++)
    {
       cout << v[i];
    }
    for (auto it:v)
    {
       cout << it;
    }
    
    
    //delete
    v.erase(v.begin() + 1); // erases 2nd elemetn
    v.erase(v.begin(), v.begin() + 4); // end isnt deleted

    v.insert(v.begin(), 200);
    v.insert(v.begin() + 1, 2,10); //2 instance of 10 inserted

    v.insert(v.begin(), V.begin(), V.end()); //inserts V into v


    v.size();
    v.pop_back(); // removes last

    v.clear(); // 
    v.empty(); //is empty bool


}

void List(){
    //used DLL inside, so push front is cheaper
    list<int> ls;
    ls.push_back(4);
    ls.emplace_back(4);

    ls.push_front(2);

    //begin, end, clear, insert, size, swap are same as vector

}

void Deque()
{
    deque<int> dq;
    dq.push_back(1);
    dq.emplace_back(2);
    dq.push_front(3);

    dq.pop_back();
    dq.pop_front();

    dq.front();
    dq.back();
        //begin, end, clear, insert, size, swap are same as vector
    //other same as vecore
}


void Stack(){
    stack<int> s;
    s.push(3);
    s.push(3);
    s.push(3);
    s.pop();

    s.top();
    s.size();
    s.empty();

}

void Queue()
{
    queue<int> q;
    q.push(3);
    q.pop();

    q.back(); //last
    q.front(); //front
    
}

void PriQ(){
    //push log n
    //top/pop o(1)
    //greatest on top
    priority_queue<int> pq;
    pq.push(45);
    pq.pop();

    cout << pq.top();

    //Min HEap
    priority_queue<int, vector<int>, greater<int>> pq;
    pq.push(4);
    pq.push(4);
    pq.push(4);

}


void Set()
{   //logn
    //sorted and unique
    set<int> s;
    s.insert(3);
    s.emplace(6);

    auto it = s.find(3); // points at ele
    //if not in set, points at s.end()
    s.erase(3);

    int c= s.count(2);  // 1 or 0
}

void MiltiSet()
{
    //sorted
    multiset<int>s;
     s.insert(3);
    s.emplace(6);

    auto it = s.find(3); // points at ele
    //if not in set, points at s.end()
    s.erase(3); //delets all occurece

    int c= s.count(2); // any no

    s.erase(s.find(1)); //delete 1 occurence
    //s.erase(s.find(1), s.find(1) +1);//
}

void UnorderSet()
{   
    // o(1)
    unordered_set<int> s;
    //all similar to Set
}

void Map()
{
    map<int,int> m;
    //key value pair
    m[1] = 2;
    m.emplace(3,1);
    m.insert({5,4});
    //sorted order of key
    for(auto it: m){
        cout << it.first ;
    }
    cout << m[1]; // 0/null if not exist

    //MultiMap stores duplicate KEys
    //Unorder Map not sorted o(1)
}

bool somp(pair<int,int> a, pair<int,int> b)
{
    if(a.second < b.second) return true;
    if(a.second > b.second) return false;

    if(a.first > a.second) return true;
    return false;
}

void Algo()
{
    int a[13];
    sort(a, a + 4);
    //sort(a, a + 5, greater<int>); //builtin comparator

    pair<int,int> a[] = {{1,2}, {3,4}};
    sort(a , a + 1, somp);
    
    string s = "12,3";
    //sort before t print all 
    do
    {
        cout << s << endl;
    } while (next_permutation(s.begin(), s.end()));
    
    int maxi = *max_element(a, a + 1);
    //min_element
}

int main()
{
    return 0;
}