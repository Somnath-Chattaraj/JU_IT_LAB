#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int coefficient;
    int exponent;
} Term;

void addSparsePolynomials(Term poly1[], int size1, Term poly2[], int size2, Term result[], int *sizeResult) {
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (poly1[i].exponent == poly2[j].exponent) {
            result[k].coefficient = poly1[i].coefficient + poly2[j].coefficient;
            result[k].exponent = poly1[i].exponent;
            i++; j++; k++;
        } else if (poly1[i].exponent > poly2[j].exponent) {
            result[k++] = poly1[i++];
        } else {
            result[k++] = poly2[j++];
        }
    }

    while (i < size1) {
        result[k++] = poly1[i++];
    }

    while (j < size2) {
        result[k++] = poly2[j++];
    }

    *sizeResult = k;
}

void printPolynomial(Term poly[], int size) {
    for (int i = 0; i < size; i++) {
        if (i > 0 && poly[i].coefficient > 0) printf(" + ");
        printf("%dx^%d", poly[i].coefficient, poly[i].exponent);
    }
    printf("\n");
}

int main() {
    Term poly1[100], poly2[100], result[200];
    int size1, size2, sizeResult;

    // Input the first polynomial
    printf("\nInput the first polynomial:\n");
    inputPolynomial(poly1, &size1);

    // Input the second polynomial
    printf("\nInput the second polynomial:\n");
    inputPolynomial(poly2, &size2);

    // Add the two polynomials
    addSparsePolynomials(poly1, size1, poly2, size2, result, &sizeResult);

    // Print the resultant polynomial
    printf("\nResultant polynomial: ");
    printPolynomial(result, sizeResult);
    return 0;
}
