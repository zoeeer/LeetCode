#include<vector>
using namespace std;

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
