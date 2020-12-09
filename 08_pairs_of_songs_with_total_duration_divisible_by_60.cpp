/*
You are given a list of songs where the ith song has a duration of time[i] seconds.

Return the number of pairs of songs for which their total duration in seconds is divisible by 60. Formally, we want the number of indices i, j such that i < j with (time[i] + time[j]) % 60 == 0.

 

Example 1:

Input: time = [30,20,150,100,40]
Output: 3
Explanation: Three pairs have a total duration divisible by 60:
(time[0] = 30, time[2] = 150): total duration 180
(time[1] = 20, time[3] = 100): total duration 120
(time[1] = 20, time[4] = 40): total duration 60
Example 2:

Input: time = [60,60,60]
Output: 3
Explanation: All three pairs have a total duration of 120, which is divisible by 60.
 

Constraints:

1 <= time.length <= 6 * 104
1 <= time[i] <= 500
*/




class Solution {
private:
    int tri(int num) {
        int sum = 0;
        for (int i=1; i<num; ++i)
            sum += i;
        return sum;
    }
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> mod(60);
        int pairs = 0;
        for (int t : time)
            ++mod[t%60];
        if (mod[0])
            pairs += tri(mod[0]);
        for (int i=1; i<30; ++i) {
            if (i != 60-i)
                pairs = pairs + mod[i] * mod[60-i];
        }
        if (mod[30])
            pairs += tri(mod[30]);
        return pairs;
    }
};


// Optimal and concise solution
class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> mods(60);
        int pairs = 0;
        for (int t : time) {
            int target = (60 - (t % 60)) % 60;
            pairs += mods[target];
            ++mods[t % 60];
        }
        return pairs;
    }
};

