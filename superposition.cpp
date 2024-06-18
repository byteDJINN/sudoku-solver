#include "sudoku.cpp"
#include <vector>
#include <unordered_set>

class Superposition {
    public:
        Superposition(Sudoku sudoku) {
            for (int i = 0; i < 9; i++) {
                for (int j = 0; j < 9; j++) {
                    int value = sudoku.get(i,j);
                    if (value != 0) {
                        set(i, j, value);
                    }
                }
            }
        }

        void set(int row, int col, int value) {
            for (int i = 0; i < 9; i++) {
                possibilities[row][i].erase(value);
                possibilities[i][col].erase(value);
            }
            int boxRow = row / 3 * 3;
            int boxCol = col / 3 * 3;
            for (int i = boxRow; i < boxRow + 3; i++) {
                for (int j = boxCol; j < boxCol + 3; j++) {
                    possibilities[i][j].erase(value);
                }
            }
        }

        std::pair<int,int> nextGuaranteed() {
            if (!queue.empty()) {
                auto ret = queue.back();
                queue.pop_back();
                return ret;
            }
            return {-1, -1};
        }

    private:
        std::vector<std::vector<std::unordered_set<int>>> possibilities = std::vector<std::vector<std::unordered_set<int>>>(9, std::vector<std::unordered_set<int>>(9, {1, 2, 3, 4, 5, 6, 7, 8, 9}));
        std::vector<std::pair<int, int>> queue;

        void check(int row, int col) {
            if (possibilities[row][col].size() == 1) {
                int value = *possibilities[row][col].begin();
                queue.push_back({row, col});
                set(row, col, value);
            }
        }

};