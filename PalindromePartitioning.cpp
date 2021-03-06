/*** Palindrome Partitioning ***

Given a string s, partition s such that every substring of the partition is a palindrome.

Return all possible palindrome partitioning of s.

For example, given s = "aab",
Return

  [
    ["aa","b"],
    ["a","a","b"]
  ]

*/
# include <string>
# include <vector>
# include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<string> > partition(string s) {
        vector<vector<string> > ans;
        vector<Pair> pal; /* center of palindrome substrings */
        /* find all palindromes longer than 1 */
        for (int i = 0; i < s.size()-1; ) {
            int j = i;
            while (++j != s.size() && s[j] == s[i])
                ;
            int begin = i, end = --j;
            for (j = begin+1; j < end; ++j)  // handle "aaa"
                pal.push_back({i, j});
            for(--i,j=end+1; i !=-1 && j != s.size() && s[i]==s[j]; --i,++j)
                ; // expand around center "cac" "caaaaac"
            if (j - i > 2)
                pal.push_back({++i, --j});
            for (i = begin+1, j = end; i < j; ++i) // handle "aaa"
                pal.push_back({i, j});
            i = end+1;
        }
        /* expand palindrome substrings around centers */
        expand(pal, 0, s, ans);
        return ans;
    }

private:
    typedef struct _pair {
        int l, r; /* begin and end of a palindrome substring */
    } Pair;

    void expand(vector<Pair> & pals, int n, string &s,
                vector<vector<string> > &ans)
    {
        static vector<Pair> result = vector<Pair> (1, Pair({-1, -1}));
        if (n == pals.size()) { // output result
            vector<string> tmp;
            int j = -1;
            for (int i = 1; i != result.size(); ++i) {
                while (++j < result[i].l)
                    tmp.push_back(string(1, s[j]));
                tmp.push_back(s.substr(j, result[i].r-j+1));
                j = result[i].r;
            }
            while (++j != s.size())
                tmp.push_back(string(1, s[j]));
            ans.push_back(tmp);
            return;
        }
        int l = max(pals[n].l, result.back().r+1); 
        while (l - pals[n].l <= (pals[n].r - pals[n].l - 1) /2) {
            result.push_back({l, pals[n].l + pals[n].r - l});
            expand(pals, n+1, s, ans);
            result.pop_back();
            ++l;
        }
        expand(pals, n+1, s, ans);
    }
};

int main()
{
    string s;
    Solution ans;
    while (cin >> s) {
        vector<vector<string> > a = ans.partition(s);
        for (int i = 0; i != a.size(); ++i) {
            for (int j = 0; j != a[i].size(); ++j)
                cout << a[i][j] << " ";
            cout << endl;
        }
    }
}
