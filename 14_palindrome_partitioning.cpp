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




// Initial backtracking approach
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




// Somemore standard approach using Backtracking
class Solution {
private:
    typedef vector<string> vs;
    typedef vector<vector<string>> vvs;
    
    bool isPal(string& s, int start, int end) {
        while (start <= end) {
            if (s[start++] != s[end--])
                return false;
        }
        return true;
    }
    void backtrack(string s, vs& part, vvs& partitions, int start) {
        if (start >= s.length()) partitions.push_back(part);
        for (int end=start; end<s.length(); ++end) {
            if (isPal(s, start, end)) {
                part.push_back(s.substr(start, end-start+1));
                backtrack(s, part, partitions, end+1);
                part.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vvs partitions;
        vs part;
        backtrack(s, part, partitions, 0);
        return partitions;
    }
};

