#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX 10

typedef struct {
    int row;
    int col;
    int (*multiplicand)[MAX];
    int (*multiplier)[MAX];
    int (*result)[MAX];
    int m_size;
} ThreadData;

void* multiply(void* arg) {
    ThreadData* data = (ThreadData*) arg;
    int sum = 0;

    for (int i = 0; i < data->m_size; i++) {
        sum += data->multiplicand[data->row][i] * data->multiplier[i][data->col];
    }

    data->result[data->row][data->col] = sum;
    pthread_exit(0);
}

int main() {
    int multiplicand[2][MAX] = {
        {5, 6, 7},
        {4, 8, 9}
    };

    int multiplier[3][MAX] = {
        {6, 4},
        {5, 7},
        {1, 1}
    };

    int result[2][MAX] = {0};
    int rows_multiplicand = 2;
    int cols_multiplicand = 3;
    int cols_multiplier = 2;

    pthread_t threads[rows_multiplicand][cols_multiplier];
    ThreadData thread_data[rows_multiplicand][cols_multiplier];

    // Create threads for each element in the result matrix
    for (int i = 0; i < rows_multiplicand; i++) {
        for (int j = 0; j < cols_multiplier; j++) {
            thread_data[i][j].row = i;
            thread_data[i][j].col = j;
            thread_data[i][j].multiplicand = multiplicand;
            thread_data[i][j].multiplier = multiplier;
            thread_data[i][j].result = result;
            thread_data[i][j].m_size = cols_multiplicand;
            pthread_create(&threads[i][j], NULL, multiply, (void*)&thread_data[i][j]);
        }
    }

    // Wait for all threads to complete
    for (int i = 0; i < rows_multiplicand; i++) {
        for (int j = 0; j < cols_multiplier; j++) {
            pthread_join(threads[i][j], NULL);
        }
    }

    // Print the result matrix
    printf("Result matrix:\n");
    for (int i = 0; i < rows_multiplicand; i++) {
        for (int j = 0; j < cols_multiplier; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }

    return 0;
}
