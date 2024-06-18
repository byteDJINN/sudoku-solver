#include <vector>
#include <iostream>

class Sudoku {
    public:
        Sudoku(std::vector<std::vector<int>> board): board(board) {}

        int get(int row, int col) {
            return board[row][col];
        }

        void set(int row, int col, int value) {
            board[row][col] = value;
        }

        void print() {
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    std::cout << board[i][j] << " ";
                }
                std::cout << std::endl;
            }
        }

    private:
        std::vector<std::vector<int>> board;

};