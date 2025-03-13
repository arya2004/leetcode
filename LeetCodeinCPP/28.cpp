#include <bits/stdc++.h>
using namespace std;


class Solution {
    public:
        int strStr(string haystack, string needle) {
            int j = -1;
            if (haystack == needle) {
                return 0;
            }
            for (int i = 0; i <= haystack.length() - needle.length(); i++) {
                if (haystack[i] == needle[0]) {
                    j = i;
                    for (int j2 = 0; j2 < needle.length(); j2++) {
                        if (haystack[i + j2] != needle[j2]) {
                            j = -1;
                            break;
                        }
                    }
                    if (j != -1) return j;
                }
            }
            return j;
        }
    };