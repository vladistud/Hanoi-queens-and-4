#include <iostream>
#include <cmath>

using namespace std;

const int BOARD_SIZE = 8; // Размер шахматной доски

// Проверка корректности позиции для нового ферзя
bool checkQueenPosition(int queen_cols[], int current_row, int check_col) {
    for (int prev_row = 0; prev_row < current_row; prev_row++) {
        bool same_column = (queen_cols[prev_row] == check_col);
        bool same_diagonal = abs(queen_cols[prev_row] - check_col) == (current_row - prev_row);
        
        if (same_column || same_diagonal) return false;
    }
    return true;
}

// Отображение текущей расстановки ферзей
void displayChessBoard(int queen_cols[]) {
    for (int row = 0; row < BOARD_SIZE; row++) {
        for (int col = 0; col < BOARD_SIZE; col++) {
            cout << (queen_cols[row] == col ? "♕ " : "· ");
        }
        cout << '\n';
    }
    cout << "────────────────────\n";
}

// Поиск всех возможных решений
void findQueenSolutions(int queen_cols[], int current_row, int& solution_count) {
    if (current_row == BOARD_SIZE) {
        solution_count++;
        displayChessBoard(queen_cols);
        return;
    }

    int col = 0;
    while (col < BOARD_SIZE) {
        if (checkQueenPosition(queen_cols, current_row, col)) {
            queen_cols[current_row] = col;
            findQueenSolutions(queen_cols, current_row + 1, solution_count);
        }
        col++;
    }
}

int main() {
    int queen_positions[BOARD_SIZE] = {};  // Позиции ферзей по столбцам
    int total_solutions = 0;

    findQueenSolutions(queen_positions, 0, total_solutions);

    cout << "Для доски " << BOARD_SIZE << "x" << BOARD_SIZE 
         << " найдено вариантов расстановки: " << total_solutions << '\n';
    
    return 0;
}
