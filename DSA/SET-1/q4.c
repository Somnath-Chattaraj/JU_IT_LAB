#include <stdio.h>
#include <math.h>

typedef struct {
    int coefficient;
    int exponent;
} Term;

int evaluateSparsePolynomial(Term poly[], int size, int x) {
    int result = 0;
    for (int i = 0; i < size; i++) {
        result += poly[i].coefficient * pow(x, poly[i].exponent);
    }
    return result;
}

int main() {
    Term poly[] = {{3, 0}, {2, 1}, {4, 3}};
    int x;
    printf("Enter the value of x: ");
    scanf("%d", &x);

    int result = evaluateSparsePolynomial(poly, 3, x);
    printf("Result: %d\n", result);

    return 0;
}
