/*
Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.

Find the maximum coins you can collect by bursting the balloons wisely.

Note:

You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
Example:

Input: [3,1,5,8]
Output: 167 
Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
             coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
*/




class Solution {
private:
    vector<vector<int>> dp;
    int maxCoins(vector<int>& nums, int left, int right) {
        if (dp[left][right]) return dp[left][right];
        int mxm = 0, score = 0;
        for (int mid=left+1; mid<right; ++mid) {
            score = nums[left] * nums[mid] * nums[right] + maxCoins(nums, left, mid) + maxCoins(nums, mid, right);
            mxm = max(mxm, score);
        }
        dp[left][right] = mxm;
        return mxm;
    }
public:
    int maxCoins(vector<int>& nums) {
        vector<int> inputList = {1};
        inputList.insert(inputList.end(), nums.begin(), nums.end());
        inputList.push_back(1);
        int n = inputList.size();
        dp.resize(n, vector<int>(n));
        return maxCoins(inputList, 0, n-1);
    }
};

