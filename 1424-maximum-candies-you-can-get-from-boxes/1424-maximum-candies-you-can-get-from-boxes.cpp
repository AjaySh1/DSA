#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        
        int n = status.size();
        vector<bool> hasKey(n, false), hasBox(n, false), opened(n, false);
        queue<int> q;
        
        for (int box : initialBoxes) {
            hasBox[box] = true;
            if (status[box]) q.push(box);
        }
        
        int totalCandies = 0;
        
        while (!q.empty()) {
            int box = q.front();
            q.pop();
            
            if (opened[box]) continue;
            opened[box] = true;
            
            totalCandies += candies[box];
            
            for (int k : keys[box]) {
                hasKey[k] = true;
                if (hasBox[k] && !opened[k]) {
                    q.push(k);
                }
            }
            
            for (int b : containedBoxes[box]) {
                hasBox[b] = true;
                if (status[b] || hasKey[b]) {
                    q.push(b);
                }
            }
        }
        
        return totalCandies;
    }
};
