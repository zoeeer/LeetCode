# include <string>
# include <vector>
# include <iostream>

using namespace std;

class Solution {
public:
    int minCut(string s) {
        if (s.size() <= 1)
            return 0;
        int N = s.size();
        vector<vector<bool> > isPal(N, vector<bool> (N, 0));
        for (int i = 0, next; i < N; i = next) {
            int j = i-1;
            while (++j < N && s[j] == s[i])
                for (int ii = i; ii <= j; ++ii)
                    isPal[ii][j] = 1;
            next = j;
            for (--i; i !=-1 && j < N && s[i] == s[j]; --i, ++j)
                isPal[i][j] = 1; // expand palindromic substrings
        }
        vector<int> mincut(N, 0);
        for (int i = 1; i < N; ++i) {
            if (isPal[0][i]) continue;
            mincut[i] = mincut[i-1] + 1;
            for (int j = 1; j < i; ++j) {
                if (isPal[j][i] && mincut[j-1] + 1 < mincut[i])
                    mincut[i] = mincut[j-1] + 1;
            }
        }
        return mincut[N-1];
    }
};

int main()
{
    string s;
    Solution ans;
    while (cin >> s) {
        cout << ans.minCut(s) << endl;
    }
}
