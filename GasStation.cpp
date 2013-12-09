class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        if (gas.empty()) return -1;
        int sum = 0, total = 0;
        int k = -1;
        for (int i = 0; i < gas.size(); i++) {
            total += gas[i] - cost[i];
            sum += gas[i] - cost[i];
            if (sum < 0) {
                sum = 0;
                k = i;
            }
        }
        return total >= 0 ? k+1 : -1;
    }
};
