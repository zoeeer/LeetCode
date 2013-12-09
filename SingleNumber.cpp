/*** Single Number ***

Given an array of integers, every element appears twice except 
for one. Find that single one.

Note:
Your algorithm should have a linear runtime complexity. 
Could you implement it without using extra memory?

*/
class Solution {
public:
    int singleNumber(int A[], int n) {
        if (n <= 0) return -1;
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans ^= A[i];
        return ans;
    }
};
