// LeetCodeinCPP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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

struct Node {
    Node* links[26];
    bool flag = false;
    bool containsKey(char c)
    {
        return (links[c - 'a'] != NULL);
    }
    void put(char c, Node* node)
    {
        links[c - 'a'] = node;
    }
    Node* get(char c)
    {
        return links[c - 'a'];
    }
    bool setEnd()
    {
        flag = true;
    }
    bool isEnd()
    {
        return flag;
    }
};


class Trie {
private: Node* root;

public:
    Trie() {
        root = new Node();
    }

    void insert(string word) {
        Node* temp = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!temp->containsKey(word[i]))
            {
                temp->put(word[i], new Node());
            }
            temp = temp->get(word[i]);
        }
        temp->setEnd();
    }

    bool search(string word) {
        Node* temp = root;
        for (int i = 0; i < word.length(); i++)
        {
            if (!temp->containsKey(word[i])) {
                return false;
            }
            temp = temp->get(word[i]);
        }
        return (temp->isEnd() == true);
        

        
    }

    bool startsWith(string prefix) {
        Node* temp = root;
        for (int i = 0; i < prefix.length(); i++)
        {
            if (!temp->containsKey(prefix[i]))
            {
                return false;
            }
            temp = temp->get(prefix[i]);

        }
        return true;
    }
};


int main()
{
 
    cout << "dotnet mow";

}

