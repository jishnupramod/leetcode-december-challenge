/*
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

The answer is guaranteed to fit in a 32-bit integer.

 

Example 1:

Input: s = "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: s = "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
Example 3:

Input: s = "0"
Output: 0
Explanation: There is no character that is mapped to a number starting with '0'. We cannot ignore a zero when we face it while decoding. So, each '0' should be part of "10" --> 'J' or "20" --> 'T'.
Example 4:

Input: s = "1"
Output: 1
 

Constraints:

1 <= s.length <= 100
s contains only digits and may contain leading zero(s).
*/




class Solution {
private:
    vector<int> dp;
    int decodes(string& s, int i, int n) {
        if (i == n) return 1;
        if (dp[i]) return dp[i];
        int count = 0;
        if (s[i] != '0')
            count += decodes(s, i+1, n);
        if (s[i] == '1' and i+2 <= n)
            count += decodes(s, i+2, n);
        if (s[i] == '2' and s[i+1] <= '6' and i+2 <= n)
            count += decodes(s, i+2, n);
        dp[i] = count;
        return count;
    }
public:
    int numDecodings(string s) {
        int n = s.length();
        dp.resize(n+1);
        return decodes(s, 0, n);
    }
};

