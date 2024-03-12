#include <stdio.h>
#define N_SIZE 5


void rotate_matrix(int matrix[N_SIZE][N_SIZE])
{
    for (int level = 0; level < N_SIZE / 2 ; level++)
    {
        for (int j = 0; j < N_SIZE - (level * 2) - 1; j++)
        {
            int temp = matrix[level][N_SIZE - level - j - 1];
            matrix[level][N_SIZE - level - j - 1] = matrix[level + j][level];
            matrix[level + j][level] = matrix[N_SIZE - level - 1][level + j];
            matrix[N_SIZE - level - 1][level + j] = matrix[N_SIZE - level - j - 1][N_SIZE - level - 1];
            matrix[N_SIZE - level - j - 1][N_SIZE - level - 1] = temp;
        }
    }

}

void print_matrix(int matrix[N_SIZE][N_SIZE])
{
    for (int i = 0; i < N_SIZE; i++) {
        for (int j = 0; j < N_SIZE; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}


int main() {
    int matrix[N_SIZE][N_SIZE] = {
            {1,  2,  3,  4, 5},
            {6,  7,  8,  9, 10},
            {48,  43,  32,  10, 15},
            {99,  98,  97,  96, 95},
            {8,  7,  21,  32, 33},
    };
    print_matrix(matrix);
    rotate_matrix(matrix);
    printf("------- 90 degree Rotation -> R E S U L T ------\n\n");
    print_matrix(matrix);


    return 0;
}