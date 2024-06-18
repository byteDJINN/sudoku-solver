#include "sudoku.cpp"
#include "superposition.cpp"
#include <vector>
#include <unordered_set>

class Solver {
    public:
        Solver(std::vector<std::vector<int>> board) : sudoku(Sudoku(board)) {}

        void solve() {
            // init possibilities
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    int value = sudoku.get(i, j);
                    if (value != 0) {
                        set(i, j, value);
                    }
                }
            }
        }

        void print() {
            sudoku.print();
        }

    private:
        Sudoku sudoku;
        Superposition superposition = Superposition(sudoku);
};