#include "solver.cpp"
#include <fstream>
#include <vector>
#include <string>
#include <iostream>

int main() {
    std::vector<Solver> sudokuList;
    std::ifstream file("sudoku.csv");


    // get the header line
    std::string header;
    std::getline(file, header);

    std::string line;
    while (std::getline(file, line)) {
        std::vector<std::vector<int>> board;
        for (int i = 0; i < 9; i++) {
            std::vector<int> row;
            for (int j = 0; j < 9; j++) {
                row.push_back(line[i * 9 + j] - '0');
            }
            board.push_back(row);
        }
        sudokuList.push_back(Solver(board));

        break; // TODO temporary break to only get 1 sudoku
    }
    sudokuList[0].print();
    return 0;

}