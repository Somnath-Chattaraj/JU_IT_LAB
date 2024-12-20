#include <stdio.h>
#include <stdlib.h>
int i,j;

typedef struct {
    int coeff; // Coefficient of the term
    int exp;   // Exponent of the term
} Term;

// Function to input a sparse polynomial from the user
void inputPolynomial(Term poly[], int *size) {
    printf("Enter the number of terms in the polynomial: ");
    scanf("%d", size);

    if (*size <= 0) {
        printf("No terms to input.\n");
        *size = 0;
        return;
    }

    for (i=0; i < *size; i++) {
        printf("Enter coefficient and exponent for term %d (format: coeff exp): ", i + 1);
        scanf("%d %d", &poly[i].coeff, &poly[i].exp);

        if (poly[i].coeff == 0) {
            printf("Warning: Coefficient should be non-zero. Re-enter term %d.\n", i + 1);
            i--; // Re-enter the current term
        }
    }
}

// Function to multiply two sparse polynomials
void multiplyPolynomials(Term poly1[], int size1, Term poly2[], int size2, Term result[], int *sizeResult) {
    *sizeResult = 0;

    if (size1 == 0 || size2 == 0) {
        printf("One of the polynomials is empty, so the result is zero.\n");
        return;
    }

    // Multiply each term from poly1 with every term from poly2
    for (i=0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            result[*sizeResult].coeff = poly1[i].coeff * poly2[j].coeff;
            result[*sizeResult].exp = poly1[i].exp + poly2[j].exp;
            (*sizeResult)++;
        }
    }

    // Merge like terms (combine terms with the same exponent)
    for (i=0; i < *sizeResult; i++) {
        for (j= i + 1; j < *sizeResult; j++) {
            if (result[i].exp == result[j].exp) {
                result[i].coeff += result[j].coeff;
                // Shift remaining elements to the left to remove the duplicate term
                for (int k = j; k < *sizeResult - 1; k++) {
                    result[k] = result[k + 1];
                }
                (*sizeResult)--;
                j--; // Check the current index again
            }
        }
    }

    // Remove any terms with coefficient 0
    for (i=0; i < *sizeResult; i++) {
        if (result[i].coeff == 0) {
            for (int k = i; k < *sizeResult - 1; k++) {
                result[k] = result[k + 1];
            }
            (*sizeResult)--;
            i--; // Check the current index again
        }
    }
}

// Function to print a polynomial
void printPolynomial(Term poly[], int size) {
    if (size == 0) {
        printf("0\n");
        return;
    }

    for (i=0; i < size; i++) {
        if (poly[i].coeff > 0 && i != 0) printf("+");

        if (poly[i].exp == 0) {
            printf("%d", poly[i].coeff);
        } else if (poly[i].exp == 1) {
            printf("%dx", poly[i].coeff);
        } else {
            printf("%dx^%d", poly[i].coeff, poly[i].exp);
        }
    }
    printf("\n");
}

int main() {
    Term poly1[100], poly2[100], result[200];
    int size1, size2, sizeResult;

    // Input the first sparse polynomial
    printf("\nInput the first polynomial:\n");
    inputPolynomial(poly1, &size1);

    // Input the second sparse polynomial
    printf("\nInput the second polynomial:\n");
    inputPolynomial(poly2, &size2);

    // Multiply the two polynomials
    multiplyPolynomials(poly1, size1, poly2, size2, result, &sizeResult);

    // Print the resultant polynomial
    printf("\nResultant Polynomial:\n");
    printPolynomial(result, sizeResult);

    return 0;
}
