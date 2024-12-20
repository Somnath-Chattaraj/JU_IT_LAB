// 1. Write a program to take a 10 element array as input and delete the 3rd and 6th element. 
// Now print the 5th element of the resulting array.
// 1 2 3 4 5 6 7
// 1 2   4 5   7

#include <stdio.h>

void DeleteElement(int arr[10], int first, int second){
    int i;
    for (i = first-1; i < 10-1; i++){
        arr[i] = arr[i+1];
    }
    for(i = second-2; i < 10-2; i++){
        arr[i] = arr[i+1];
    }
}

int main(){
    int n = 10;
    int arr[n];
    printf("Enter 10 elements of array: ");
    int i;
    for (i = 0; i < 10; i++){
        scanf("%d", &arr[i]);
    }
    DeleteElement(arr,3,6);
    printf("5th Element is: %d\n", arr[4]);
    return 0;
}