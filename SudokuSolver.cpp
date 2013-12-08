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
	vector<vector<int> > note_cnt; // count of possible answers
	queue<int> qi, qj; // single answer positions
    static const int N = 9;

public:
	Sudoku(const vector<vector<char> > &board) : board(board) {
		note = vector<vector <int> > (N, vector<int> (N, 511));
		note_cnt = vector<vector <int> > (N, vector<int> (N, N));

        // initialize notes
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
                if (board[i][j] != '.') {
                    note[i][j] = 0;
					note_cnt[i][j] = 0;
                    updateNote(i, j);
                }
	}

	Sudoku(const Sudoku *p) : board(p->board), 
							  note(p->note),
							  note_cnt(p->note_cnt),
							  qi(p->qi), qj(p->qj) {
	}

	inline int testIJ(int flag, int i, int j) {
		if (note[i][j] & flag) {
	        note[i][j] &= ~flag;
			if (--note_cnt[i][j] == 0) // board invalid
				return -1;
			else if (note_cnt[i][j] == 1) // single answer reached
				qi.push(i), qj.push(j);
		}
		return 0;
	}

	int updateNote(int x, int y) {
        int flag = 1 << (board[x][y]-'1');
        for (int j = 0; j < N; j++)
			if (testIJ(flag, x, j) == -1)
				return -1;
        for (int i = 0; i < N; i++)
			if (testIJ(flag, i, y) == -1)
				return -1;
        for (int i = x/3*3; i < x/3*3 + 3; i++) {
            for (int j = y/3*3; j < y/3*3 + 3; j++) {
				if (testIJ(flag, i, j) == -1)
					return -1;
			}
		}
		return 0;
    }

	bool solve() {
		// solve single answer positions
		while (!qi.empty()) {
			int i = qi.front();
			int j = qj.front();
			qi.pop(), qj.pop();

            board[i][j] = '1';
            while (note[i][j] >>= 1)
                board[i][j]++;
            if (updateNote(i, j) == -1)
				return false;
		}

		int mincnt = N;
		int imin = 0, jmin = 0;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
				if (board[i][j] == '.' && note_cnt[i][j] < mincnt) {
					mincnt = note_cnt[i][j];
					imin = i;
					jmin = j;
				}
			}
		}
		if (mincnt == N) // solved
			return true;

        // solve remaining recursively
		int n = 0;
		int noteij = note[imin][jmin];
		note[imin][jmin] = 0;
		note_cnt[imin][jmin] = 0;
		while (mincnt--) {
			while ((noteij & (1 << n)) == 0)
                n++;
			board[imin][jmin] = ++n + '0';
			Sudoku sub(this);
			if ((sub.updateNote(imin, jmin) != -1) && sub.solve()) {
				board = sub.board;
				note = sub.note;
				note_cnt = sub.note_cnt;
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
