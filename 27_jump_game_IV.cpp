/*
Given an array of integers arr, you are initially positioned at the first index of the array.

In one step you can jump from index i to index:

i + 1 where: i + 1 < arr.length.
i - 1 where: i - 1 >= 0.
j where: arr[i] == arr[j] and i != j.
Return the minimum number of steps to reach the last index of the array.

Notice that you can not jump outside of the array at any time.

 

Example 1:

Input: arr = [100,-23,-23,404,100,23,23,23,3,404]
Output: 3
Explanation: You need three jumps from index 0 --> 4 --> 3 --> 9. Note that index 9 is the last index of the array.
Example 2:

Input: arr = [7]
Output: 0
Explanation: Start index is the last index. You don't need to jump.
Example 3:

Input: arr = [7,6,9,6,9,6,9,7]
Output: 1
Explanation: You can jump directly from index 0 to index 7 which is last index of the array.
Example 4:

Input: arr = [6,1,9]
Output: 2
Example 5:

Input: arr = [11,22,7,7,7,7,7,7,7,22,13]
Output: 3
 

Constraints:

1 <= arr.length <= 5 * 10^4
-10^8 <= arr[i] <= 10^8
*/




class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> neighbors;
        int n = arr.size(), jumps = 0, genPop = 1;
        for (int i=0; i<n; ++i)
            neighbors[arr[i]].push_back(i);
        queue<int> q({0});
        vector<bool> visited(n, false);
        unordered_set<int> seen;
        while (!q.empty()) {
            if (genPop == 0) {
                genPop = q.size();
                ++jumps;
            }
            int node = q.front();
            if (node == n-1) break;
            q.pop();
            --genPop;
            visited[node] = true;
            if (seen.find(arr[node]) == seen.end()) {
                seen.insert(arr[node]);
                for (int neighbor : neighbors[arr[node]]) {
                    if (!visited[neighbor])
                        q.push(neighbor);
                }
            }
            if (node > 0) {
                if (!visited[node-1])
                    q.push(node-1);
            }
            if (node < n-1) {
                if (!visited[node+1])
                    q.push(node+1);
            }
        }
        return jumps;
    }
};

