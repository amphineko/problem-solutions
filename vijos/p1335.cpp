/*
    Luna Capsule / vijos-1335

    Problem: https://vijos.org/p/1335
    Record: https://vijos.org/records/53e9d4c748c5fcae5f8b458a

    - 使用了二進制位運算小小地優化了一下
*/

#include <iostream>

using namespace std;

unsigned cm[10] = {0, 1, 2, 4, 8, 16, 32, 64, 128, 256};

bool process() {
    unsigned short cell[10][10], i, j, state, x, y;
    for (i = 1; i <= 9; i++)
        for (j = 1; j <= 9; j++)
            cin >> cell[i][j];

    // Column Checking
    for (i = 1; i <= 9; i++) {
        state = 0;
        for (j = 1; j <= 9; j++)
            state = state | cm[cell[i][j]];
        if (state != 511) {
            return false;
        }
    }

    // Row Checking
    for (j = 1; i <= 9; i++) {
        state = 0;
        for (i = 1; j <= 9; j++)
            state = state | cm[cell[i][j]];
        if (state != 511) {
            return false;
        }
    }

    // Block Checking
    for (i = 1; i <= 9; i += 3) {
        for (j = 1; j <= 9; j += 3) {
            state = 0;
            for (x = i; x <= i + 2; x++)
                for (y = j; y <= j + 2; y++)
                    state = state | cm[cell[x][y]];
            if (state != 511) {
                return false;
            }
        }
    }

    return true;
}

int main() {
    unsigned a, i;
    cin >> a;
    for (i = 1; i <= a; i++) {
        cout << (process() ? "Right" : "Wrong") << endl;
    }
}
