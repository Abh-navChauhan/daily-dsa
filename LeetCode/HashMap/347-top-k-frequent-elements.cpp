
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        // Count frequency of each number
        unordered_map<int, int> freq;

        for (int num : nums) {
            freq[num]++;
        }

        // Min heap: {frequency, number}
        priority_queue<
            pair<int, int>,
            vector<pair<int, int>>,
            greater<pair<int, int>>
        > pq;

        // Keep only k most frequent elements
        for (auto& it : freq) {
            pq.push({it.second, it.first});

            if (pq.size() > k) {
                pq.pop();
            }
        }

        // Store the answer
        vector<int> ans;

        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};

// Time Complexity: O(n log k)
// Space Complexity: O(n)
