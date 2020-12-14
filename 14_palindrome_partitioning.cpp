/*
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.

 

Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]
 

Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.
*/




class Solution {
private:
    typedef vector<string> vs;
    typedef vector<vector<string>> vvs;

    bool isPal(string p) {
        int n = p.length();
        for (int i=0; i<n/2; ++i)
            if (p[i] != p[n-i-1]) return false;
        return true;
    }
    void backtrack(string s, string pal, vs& part, vvs& partitions, int idx) {
        if (idx == s.length()) {
            string temp;
            for (string each : part)
                temp += each;
            if (temp == s)
                partitions.push_back(part);
            return;
        }
        if (idx > s.length()) return;
        pal += s[idx];
        if (isPal(pal)) {
            part.push_back(pal);
            backtrack(s, "", part, partitions, idx+1);
            part.pop_back();
            backtrack(s, pal, part, partitions, idx+1);
        } else
            backtrack(s, pal, part, partitions, idx+1);
    }
public:
    vector<vector<string>> partition(string s) {
        string pal;
        vector<string> part;
        vector<vector<string>> partitions;
        backtrack(s, pal, part, partitions, 0);
        return partitions;
    }
};

