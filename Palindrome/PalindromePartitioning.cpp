# include <string>
# include <vector>
# include <iostream>

using namespace std;

class Palindrome {
public:
    vector<vector<string> > partition(string s) {
        vector<Pair> pal; /* center of palindrome substrings */
        vector<int> d; /* palindrome substring radius to expand */
        ans.clear();
        /* find all palindromes longer than 1 */
        for (int i = 0; i < s.size()-1; ) {
            int j = i;
            while (++j != s.size() && s[j] == s[i])
                ;
            int begin = i, end = --j;
            for (j = begin+1; j < end; ++j) { // handle "aaa"
                pal.push_back({i, j});
                d.push_back((j-i-1)/2);
            }
            for(--i,j=end+1; i !=-1 && j != s.size() && s[i]==s[j]; --i,++j)
                ; // expand around center "cac" "caaaaac"
            if (j - i > 2) {
                pal.push_back({++i, --j});
                d.push_back((j-i-1)/2);
            }
            for (i = begin+1, j = end; i < j; ++i) { // handle "aaa"
                pal.push_back({i, j});
                d.push_back((j-i-1)/2);
            }
            i = end+1;
        }
        /* expand palindrome substrings around centers */
        expand(pal, d, 0, s);
        return ans;
    }

private:
    vector<vector<string> > ans;
    typedef struct _pair {
        int l, r; /* begin and end of a palindrome substring */
    } Pair;

    inline int max(int a, int b) {
        return a >= b ? a : b;
    }

    void expand(vector<Pair> & pals, vector<int> &d, int n, string &s)
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
        while (l - pals[n].l <= d[n]) {
            result.push_back({l, pals[n].l + pals[n].r - l});
            expand(pals, d, n+1, s);
            result.pop_back();
            ++l;
        }
        expand(pals, d, n+1, s);
    }
};

int main()
{
    string s = "aaabcddeefffe";
    Palindrome ans;
    //cout << (s = ans.longestPalindrome(s)) << endl;
    while (cin >> s) {
        vector<vector<string> > a = ans.partition(s);
        for (int i = 0; i != a.size(); ++i) {
            for (int j = 0; j != a[i].size(); ++j) {
                cout << a[i][j] << " ";
            }
            cout << endl;
        }
    }
}
