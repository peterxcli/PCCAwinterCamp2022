// https://leetcode.com/problems/arithmetic-slices-ii-subsequence/
#include<bits/stdc++.h>
// #define int long long
using namespace std;
class Solution {
public:
    int numberOfArithmeticSlices(vector<int> &nums) {
        // sort(nums.begin(), nums.end());
        vector<unordered_map<int64_t, int> > dp(nums.size());
        int ans = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                int64_t dif = (int64_t)nums[i]-nums[j];
                int cnt = (dp[j].find(dif) == dp[j].end() ? 0 : dp[j][dif]);
                ans += cnt;
                dp[i][dif] += cnt+1;
            }
        }
        return ans;
    }
};