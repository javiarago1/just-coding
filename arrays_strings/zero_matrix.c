#include <stdio.h>

#define M_SIZE 3
#define N_SIZE 3

/*
 * Write an algorithm such that if an element in a M x N matrix is 0, its entire row and column are set to 0
 */
void zero_matrix(int matrix[M_SIZE][N_SIZE])
{
    int buffer_row = -1;
    for (int i = 0; i < M_SIZE; i++)
    {
        for(int j = 0, k = -1, l = -1; j < N_SIZE; j++)
        {
            if (matrix[i][j] == 0)
            {
                if (buffer_row == -1)
                {
                    buffer_row = i;
                }
                if (k == -1)
                {
                    while(++k < j)
                    {
                        matrix[i][k] = 0;
                    }
                }
                if (l == -1)
                {
                    while (++l < i)
                    {
                        matrix[l][j] = 0;
                    }
                }
                matrix[buffer_row][j] = 1;
            }
            else if ((buffer_row != -1 && matrix[buffer_row][j]) || k >= 0)
            {
                matrix[i][j] = 0;
            }
        }
    }
    if (buffer_row != -1)
    {
        for (int j = 0; j < N_SIZE; j++)
        {
            matrix[buffer_row][j] = 0;
        }
    }

}

void print_matrix(int matrix[N_SIZE][N_SIZE])
{
    for (int i = 0; i < N_SIZE; i++)
    {
        for (int j = 0; j < N_SIZE; j++)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

int main()
{
    int matrix_example[M_SIZE][N_SIZE] ={
            { 1, 2, 3},
            {3, 0, 4},
            {3, 9, 7}
    };

    print_matrix(matrix_example);
    zero_matrix(matrix_example);
    print_matrix(matrix_example);

    return 0;
}