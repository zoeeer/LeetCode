#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        const int N = 9;
        vector<vector<int> > note = vector<vector <int> > (N, vector<int> (N, 511));
        // initialize fill note
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] != '.') {
                    note[i][j] = 0;
                    updateNote(note, board[i][j]-'0', i, j);
                }
            }
        }
        int update_cnt;
        do {
            update_cnt = 0;
            for (int i = 0; i < N; i++) {
                for (int j = 0; j < N; j++) {
                    if (note[i][j] != 0 
                        && (note[i][j] & (note[i][j] - 1)) == 0) { // only one possible number
                        board[i][j] = '1';
                        while (note[i][j] >>= 1)
                            board[i][j]++;
                        updateNote(note, board[i][j]-'0', i, j);
                        update_cnt++;
                    }
                }
            }
        } while (update_cnt != 0);
    }

    void updateNote(vector<vector<int> > &note, int n, int x, int y) {
        const int N = 9;
        int flag = ~(1 << (n-1));
        for (int j = 0; j < N; j++)
            note[x][j] &= flag;
        for (int i = 0; i < N; i++)
            note[i][y] &= flag;
        for (int i = x/3*3; i < x/3*3 + 3; i++)
            for (int j = y/3*3; j < y/3*3 + 3; j++)
                note[i][y] &= flag;
    }

    bool isValidSudoku(vector<vector<char> > &board) {
        const int N = 9;
        const int M = 3;
        vector<int> isUsedV = vector<int> (N, 0);
        vector<int> isUsedB = vector<int> (N, 0);
        for (int i = 0; i < N; i++) {
            int isUsedH = 0;
            for (int j = 0; j < N; j++) {
                char c;
                if ((c = board[i][j]) != '.') {
                    c -= '0';
                    if (isUsedH & (1 << c)) // Horizontal
                        return false;
                    else
                        isUsedH |= 1 << c;
                        
                    if (isUsedV[j] & (1 << c)) // Vertical
                        return false;
                    else
                        isUsedV[j] |= 1 << c;
                        
                    if (isUsedB[i/3*3 + j/3] & (1 << c)) // Block
                        return false;
                    else
                        isUsedB[i/3*3 + j/3] |= 1 << c;
                }
            }
        }
        return true;
    }
};

int main()
{
    vector<vector<char> > board = vector<vector<char> > (9, vector<char> (9, 0));
    char *table[] = {
        "..9748...",
        "7........",
        ".2.1.9...",
        "..7...24.",
        ".64.1.59.",
        ".98...3..",
        "...8.3.2.",
        "........6",
        "...2759..",
    };
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            board[i][j] = table[i][j];
    Solution sol;
    sol.solveSudoku(board);
}
