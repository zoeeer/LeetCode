/*** Longest Palindromic Substring ***

Given a string S, find the longest palindromic substring in S. You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.

*/
# include <string>
# include <iostream>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int left, right, mid;
        int maxlen, maxi;
        maxlen = maxi = 0;
        left = right = mid = s.size() / 2; // start from the middle
        --left, ++right;    // left and right edge
        for (int c = mid; c >= maxlen/2 && c < (s.size() - maxlen/2); ) {
            int i = c, j = c;
            int cnt = 1;
            while (--i != -1 && s[i] == s[c])
                ++cnt;
            while (++j != s.size() && s[j] == s[c])
                ++cnt;
            if (c < mid) left = i;
            else right = j;
            for ( ; i != -1 && j != s.size() && s[i] == s[j]; --i, ++j)
                cnt += 2;
            if (cnt > maxlen)
                maxlen = cnt, maxi = i + 1;
            if (left < s.size() - right) c = right;
            else c = left; // go to the side closer to the middle
        }
        return s.substr(maxi, maxlen);
    }
};

int main()
{
    string s;
    Solution ans;
    while (cin >> s)
        cout << ans.longestPalindrome(s) << endl;
}
