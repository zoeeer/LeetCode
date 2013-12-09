class Solution {
public:
    int singleNumber(int A[], int n) {
        char count[32] = {0};
        for (int i = 0; i < n; i++) {
            int t = A[i];
            for (int j = 0; j < 32; t >>= 1, j++)
                if (t & 1)
                    count[j] = (count[j] + 1) % 3;
        }
        int ans = 0;
        for (int k = 0; k < 32; k++)
            ans += count[k] << k;
        return ans;
    }
};
