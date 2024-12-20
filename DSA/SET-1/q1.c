#include <stdio.h>

int main() {
    int arr[10];
    int i;

    printf("Enter 10 elements of the array:\n");
    for (i = 0; i < 10; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 2; i < 9; i++) {
        arr[i] = arr[i + 1]; 
    }

    for (i = 4; i < 8; i++) {
        arr[i] = arr[i + 1];  
    }

    printf("The 5th element after deletion is: %d\n", arr[4]);

    return 0;
}
