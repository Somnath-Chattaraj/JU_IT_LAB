#include <stdio.h>

int getIndex(int row, int col, int numCols) {
    return row * numCols + col;
}
int i,j;
int main() {
    int rows = 3, cols = 4;
    int array[3][4];  // 2D array
    int oneDArray[rows * cols];  // 1D array

    printf("Enter the elements of the 2D array (3x4):\n");
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Element [%d][%d]: ", i, j);
            scanf("%d", &array[i][j]);
        }
    }


    for (i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int index = getIndex(i, j, cols);
            oneDArray[index] = array[i][j];  
        }
    }

    printf("1D array: ");
    for (i = 0; i < rows * cols; i++) {
        printf("%d ", oneDArray[i]);
    }
    printf("\n");

    return 0;
}
