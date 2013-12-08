/*** Valid Sudoku  ***

Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.

The Sudoku board could be partially filled, where empty cells are filled 
with the character '.'.

*/

class Solution {
public:
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
                    if (isUsedH & (1 << c)) // Check Horizontal
                        return false;
                    else
                        isUsedH |= 1 << c;
                        
                    if (isUsedV[j] & (1 << c)) // Check Vertical
                        return false;
                    else
                        isUsedV[j] |= 1 << c;
                        
                    if (isUsedB[i/3*3 + j/3] & (1 << c)) // Check Block
                        return false;
                    else
                        isUsedB[i/3*3 + j/3] |= 1 << c;
                }
            }
        }
        return true;
    }
};
