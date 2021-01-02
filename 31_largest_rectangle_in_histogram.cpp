/*
Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.

 


Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].

 


The largest rectangle is shown in the shaded area, which has area = 10 unit.

 

Example:

Input: [2,1,5,6,2,3]
Output: 10
*/




class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        vector<pair<int, int>> stk = {{-1, 0}};
        heights.push_back(0);
        int n = heights.size(), maxArea = 0;
        for (int i=0; i<n; ++i) {
            while (!stk.empty() and heights[i] < stk.back().second) {
                int height = stk.back().second;
                stk.pop_back();
                int width = i - stk.back().first - 1;
                int area = height * width;
                maxArea = max(maxArea, area);
            }
            stk.push_back({i, heights[i]});
        }
        return maxArea;
    }
};
