#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int>pq;
        for(int i=0;i<stones.size();i++)
            pq.push(stones[i]);

        while (pq.size() >= 2) {
            int u = pq.top();
            pq.pop();
            int v = pq.top();
            pq.pop();
            if (u != v)
                pq.push(u - v);
        }
        if (pq.size() == 1)
            return pq.top();
        else return 0;
    }
};

int main() {
    vector<int> v = { 2,7,4,1,8,1 };
    Solution s;
    s.lastStoneWeight(v);
}