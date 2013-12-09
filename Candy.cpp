/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

    Each child must have at least one candy.
    Children with a higher rating get more candies than their neighbors.

What is the minimum candies you must give? 
*/

class Solution {
public:
    int candy(vector<int> &ratings) {
        if (ratings.empty()) return 0;
        int sum = 1, cur = 1;
        int peak = cur, ipeak = 0;
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i-1]) {
                sum += ++cur;
                ipeak = i;
            }
            else if (ratings[i] == ratings[i-1]) {
                cur = 1;
                sum += cur;
                ipeak = i;
            }
            else {
                if (ipeak == i-1)
                    peak = cur;
                cur = 1;
                sum += i - ipeak < peak ? i - ipeak : i - ipeak + 1;
            }
        }
        return sum;
    }
};
