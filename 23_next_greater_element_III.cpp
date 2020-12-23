/*
Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.

Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.

 

Example 1:

Input: n = 12
Output: 21
Example 2:

Input: n = 21
Output: -1
 

Constraints:

1 <= n <= 231 - 1
*/




class Solution {
private:
    long long toNumber(string s) {
        long long num = 0;
        for (char ch : s)
            num = num * 10 + (ch - '0');
        return num;
    }
public:
    int nextGreaterElement(int n) {
        string num = to_string(n);
        int len = num.length(), x = -1, y = -1;
        for (int i=0; i<len-1; ++i) {
            for (int j=i+1; j<len; ++j) {
                if (num[j] > num[i]) {
                    x = i;
                    y = j;
                }
            }
        }
        if (x == -1 and y == -1) return -1;
        swap(num[x], num[y]);
        sort(num.begin()+x+1, num.end());
        long long nextGreat = toNumber(num);
        return nextGreat > INT_MAX ? -1 : (int)nextGreat;
    }
};

