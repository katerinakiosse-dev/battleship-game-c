#include <stdio.h>
#include <stdlib.h>

#define M 20
#define N 20

int main() {
    int board1[M][N] = {0};
    int board2[M][N] = {0};    
    int shots1[M][N] = {0};
    int shots2[M][N] = {0};
    int shipLength[5] = {5, 4, 3, 3, 2}; 
    int shipHealth1[5] = {5, 4, 3, 3, 2};
    int shipHealth2[5] = {5, 4, 3, 3, 2};  
    int shipsLeft1 = 5;
    int shipsLeft2 = 5;   
    int row, col, orient;
    int shipId;  
    int i, j, k;
    int ok;

    // Player 1 places ships
    for (k = 0; k < 5; k++) {   
        ok = 0;
        while (ok == 0) {
            printf("\nPlayer 1 - Ship %d (length %d)\n", k + 1, shipLength[k]);
            printf("Enter row col orientation (0=horizontal, 1=vertical): ");
            scanf("%d %d %d", &row, &col, &orient);
            ok = 1;

            if (row < 0 || row >= M || col < 0 || col >= N)
                ok = 0;

            if (orient == 0 && col + shipLength[k] - 1 >= N)
                ok = 0;

            if (orient == 1 && row + shipLength[k] - 1 >= M)
                ok = 0;

            if (ok == 1) {
                for (i = 0; i < shipLength[k]; i++) {
                    if (orient == 0 && board1[row][col + i] != 0)
                        ok = 0;
                    if (orient == 1 && board1[row + i][col] != 0)
                        ok = 0;
                }
            }

            if (ok == 0)
                printf("Invalid placement. Try again.\n");
        }

        for (i = 0; i < shipLength[k]; i++) {
            if (orient == 0)
                board1[row][col + i] = k + 1;
            else
                board1[row + i][col] = k + 1;
        }
    }

    // Player 2 places ships
    for (k = 0; k < 5; k++) {
        ok = 0;
        while (ok == 0) {
            printf("\nPlayer 2 - Ship %d (length %d)\n", k + 1, shipLength[k]);
            printf("Enter row col orientation (0=horizontal, 1=vertical): ");
            scanf("%d %d %d", &row, &col, &orient);
            ok = 1;

            if (row < 0 || row >= M || col < 0 || col >= N)
                ok = 0;

            if (orient == 0 && col + shipLength[k] - 1 >= N)
                ok = 0;

            if (orient == 1 && row + shipLength[k] - 1 >= M)
                ok = 0;

            if (ok == 1) {
                for (i = 0; i < shipLength[k]; i++) {
                    if (orient == 0 && board2[row][col + i] != 0)
                        ok = 0;
                    if (orient == 1 && board2[row + i][col] != 0)
                        ok = 0;
                }
            }

            if (ok == 0)
                printf("Invalid placement. Try again.\n");
        }

        for (i = 0; i < shipLength[k]; i++) {
            if (orient == 0)
                board2[row][col + i] = k + 1;
            else
                board2[row + i][col] = k + 1;
        }
    }

    // Print boards (optional)
    printf("\nPlayer 1 Board:\n");
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++)
            printf("%d ", board1[i][j]);
        printf("\n");
    }

    printf("\nPlayer 2 Board:\n");
    for (i = 0; i < M; i++) {
        for (j = 0; j < N; j++)
            printf("%d ", board2[i][j]);
        printf("\n");
    }

    // Game loop
    while (shipsLeft1 > 0 && shipsLeft2 > 0) {

        // Player 1 turn
        do {
            printf("\nPlayer 1's turn. Enter row col: ");
            scanf("%d %d", &row, &col);
        } while(row < 0 || row >= M || col < 0 || col >= N || shots1[row][col] != 0);

        if (board2[row][col] == 0) {
            shots1[row][col] = 1; // Miss
            printf("MISS\n");
        } else {
            shots1[row][col] = 2; // Hit
            shipId = board2[row][col];
            shipHealth2[shipId - 1]--;
            printf("HIT on ship %d!\n", shipId);

            if (shipHealth2[shipId - 1] == 0) {
                shipsLeft2--;
                printf("SUNK ship %d of Player 2!\n", shipId);
            }
        }

        if (shipsLeft2 == 0) {
            printf("\nPlayer 1 WINS!\n");
            break;
        }

        // Player 2 turn
        do {
            printf("\nPlayer 2's turn. Enter row col: ");
            scanf("%d %d", &row, &col);
        } while(row < 0 || row >= M || col < 0 || col >= N || shots2[row][col] != 0);

        if (board1[row][col] == 0) {
            shots2[row][col] = 1; // Miss
            printf("MISS\n");
        } else {
            shots2[row][col] = 2; // Hit
            shipId = board1[row][col];
            shipHealth1[shipId - 1]--;
            printf("HIT on ship %d!\n", shipId);

            if (shipHealth1[shipId - 1] == 0) {
                shipsLeft1--;
                printf("SUNK ship %d of Player 1!\n", shipId);
            }
        }

        if (shipsLeft1 == 0) {
            printf("\nPlayer 2 WINS!\n");
            break;
        }
    }

    return 0;
}
