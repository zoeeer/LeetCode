/*** Sudoku Solver ***

Write a program to solve a Sudoku puzzle by filling the empty cells.

Empty cells are indicated by the character '.'.

You may assume that there will be only one unique solution.
*/
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

class Sudoku {
    vector<vector<char> > board;
    vector<vector<int> > note; // possible answers
    queue<int> qi, qj; // single answer positions
    static const int N = 9;

public:
    Sudoku(const vector<vector<char> > &board) : board(board) {
        note = vector<vector <int> > (N, vector<int> (N, 511));

        // initialize notes
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (board[i][j] != '.')
                    updateNote(i, j);
    }

    Sudoku(const Sudoku *p) : board(p->board), 
                              note(p->note),
                              qi(p->qi), 
                              qj(p->qj) {
    }

    inline void testIJ(int & flag, int i, int j) {
        if (note[i][j] & flag) {
            note[i][j] &= ~flag;
            if (note[i][j] && (note[i][j] & (note[i][j] - 1)) == 0)
                qi.push(i), qj.push(j);
        }
    }

    void updateNote(int x, int y) {
        int flag = 1 << (board[x][y] - '1');
        note[x][y] = 0;
        for (int j = 0; j < N; j++)
            testIJ(flag, x, j);
        for (int i = 0; i < N; i++)
            testIJ(flag, i, y);
        for (int i = x/3*3; i < x/3*3 + 3; i++)
            for (int j = y/3*3; j < y/3*3 + 3; j++)
                testIJ(flag, i, j);
    }

    bool solve() {
        while (!qi.empty()) { // solve single answer positions
            int i = qi.front();
            int j = qj.front();
            qi.pop(), qj.pop();

            if (note[i][j] == 0) // number no longer posible
                return false;

            board[i][j] = '1';
            while (note[i][j] >>= 1)
                board[i][j]++;
            updateNote(i, j);
        }

        int imin = -1, jmin = -1;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (board[i][j] == '.') { // find a empty position
                    imin = i;
                    jmin = j;
                    goto DFS;
                }
            }
        }
        return true; // Sudoku solved if didn't goto DFS
DFS:
        for (int n = 0; n < N; n++) {
            if ((note[imin][jmin] & (1 << n)) == 0)
                continue;
            board[imin][jmin] = n + '1';
            Sudoku sub(this);
            sub.updateNote(imin, jmin);
            if (sub.solve()) {
                board = sub.board;
                note = sub.note;
                return true;
            }
        }
        return false;
    }

    const vector<vector<char> > & getBoard() {
        return board;
    }
};

class Solution {
public:
    void solveSudoku(vector<vector<char> > &board) {
        Sudoku sudoku(board);
        sudoku.solve();
        board = sudoku.getBoard();
    }
};
