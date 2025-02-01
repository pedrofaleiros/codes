#include <stdbool.h>

bool isValidSudoku(char **board, int boardSize, int *boardColSize) {
  int rows[10][10] = {0};
  int cols[10][10] = {0};
  int boxes[3][3][10] = {0};

  for (int i = 0; i < boardSize; i++) {
    for (int j = 0; j < *boardColSize; j++) {
      if (board[i][j] != '.') {
        int current = board[i][j] - '0';

        if (current > 0 && current <= 9) {
          if (rows[i][current] == 1 || cols[j][current] == 1 ||
              boxes[i / 3][j / 3][current] == 1) {
            return false;
          }

          rows[i][current] = 1;
          cols[j][current] = 1;
          boxes[i / 3][j / 3][current] = 1;
        }
      }
    }
  }

  return true;
}

int main() { return 0; }