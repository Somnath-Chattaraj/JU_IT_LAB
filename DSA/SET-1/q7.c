#include <stdio.h>

typedef struct {
    int row;
    int col;
    int value;
} Element;

// Function to add two sparse matrices
void addSparseMatrices(Element matrix1[], int size1, Element matrix2[], int size2, Element result[], int *sizeResult) {
    int i = 0, j = 0, k = 0;

    // Merge the two sparse matrices
    while (i < size1 && j < size2) {
        if (matrix1[i].row == matrix2[j].row && matrix1[i].col == matrix2[j].col) {
            result[k].row = matrix1[i].row;
            result[k].col = matrix1[i].col;
            result[k].value = matrix1[i].value + matrix2[j].value;
            i++; 
            j++; 
            k++;
        } else if (matrix1[i].row < matrix2[j].row || 
                  (matrix1[i].row == matrix2[j].row && matrix1[i].col < matrix2[j].col)) {
            result[k++] = matrix1[i++];
        } else {
            result[k++] = matrix2[j++];
        }
    }

    // Copy remaining elements from matrix1
    while (i < size1) {
        result[k++] = matrix1[i++];
    }

    // Copy remaining elements from matrix2
    while (j < size2) {
        result[k++] = matrix2[j++];
    }

    *sizeResult = k; // Update the size of the result matrix
}

// Function to print the sparse matrix
void printSparseMatrix(Element matrix[], int size) {
    if (size == 0) {
        printf("The sparse matrix is empty.\n");
        return;
    }

    printf("Row\tCol\tValue\n");
    for (int i = 0; i < size; i++) {
        printf("%d\t%d\t%d\n", matrix[i].row, matrix[i].col, matrix[i].value);
    }
}

// Function to input a sparse matrix from the user
void inputSparseMatrix(Element matrix[], int *size) {
    printf("Enter the number of non-zero elements in the matrix: ");
    scanf("%d", size);

    if (*size <= 0) {
        printf("No non-zero elements to input.\n");
        return;
    }

    for (int i = 0; i < *size; i++) {
        printf("Enter row, column, and value for element %d: ", i + 1);
        scanf("%d %d %d", &matrix[i].row, &matrix[i].col, &matrix[i].value);

        if (matrix[i].value == 0) {
            printf("Warning: Value should be non-zero. Re-enter element %d.\n", i + 1);
            i--; // Re-enter the current element
        }
    }
}

int main() {
    Element matrix1[100], matrix2[100], result[200];
    int size1, size2, sizeResult;

    // Input the first sparse matrix
    printf("\nInput the first sparse matrix:\n");
    inputSparseMatrix(matrix1, &size1);

    // Input the second sparse matrix
    printf("\nInput the second sparse matrix:\n");
    inputSparseMatrix(matrix2, &size2);

    // Add the two sparse matrices
    addSparseMatrices(matrix1, size1, matrix2, size2, result, &sizeResult);

    // Print the resultant sparse matrix
    printf("\nResultant Sparse Matrix:\n");
    printSparseMatrix(result, sizeResult);

    return 0;
}

    // Element matrix1[] = {{0, 0, 3}, {1, 2, 5}};
    // Element matrix2[] = {{0, 0, 2}, {2, 1, 4}};
