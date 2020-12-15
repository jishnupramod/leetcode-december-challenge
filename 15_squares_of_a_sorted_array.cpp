/*
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

 

Example 1:

Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].
Example 2:

Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
 

Constraints:

1 <= nums.length <= 104
-104 <= nums[i] <= 104
nums is sorted in non-decreasing order.
*/




// O(nlogn) simple, sort solution
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        for (int& i : nums)
            i *= i;
        sort(nums.begin(), nums.end());
        return nums;
    }
};




// O(n) Solution using negative and non-negative deques
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        deque<int> nonNegs, negs;
        for (int i : nums) {
            if (i < 0) negs.push_front(i*i);
            else nonNegs.push_back(i*i);
        }
        vector<int> res;
        while (!nonNegs.empty() and !negs.empty()) {
            if (nonNegs.front() < negs.front()) {
                res.push_back(nonNegs.front());
                nonNegs.pop_front();
            } else {
                res.push_back(negs.front());
                negs.pop_front();
            }
        }
        vector<int> merged(res.size()+nonNegs.size());
        merge(res.begin(), res.end(), nonNegs.begin(), nonNegs.end(), merged.begin());
        vector<int> ans(merged.size()+negs.size());
        merge(merged.begin(), merged.end(), negs.begin(), negs.end(), ans.begin());
        return ans;
    }
};




// Two pointer solution
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int l = 0, r = nums.size()-1;
        vector<int> res(r+1);
        for (int i=nums.size()-1; i>=0; --i) {
            if (nums[l] * nums[l] > nums[r] * nums[r]) {
                res[i] = nums[l] * nums[l];
                ++l;
            } else {
                res[i] = nums[r] * nums[r];
                --r;
            }
        }
        return res;
    }
};

