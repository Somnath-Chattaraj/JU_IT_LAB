#include <stdio.h>
#include <string.h>

void addLargeNumbers(char num1[], char num2[], char result[]) {
    int len1 = strlen(num1);
    int len2 = strlen(num2);
    int carry = 0, i, j, k;

    if (len1 < len2) {
        char temp[1000];
        strcpy(temp, num1);
        strcpy(num1, num2);
        strcpy(num2, temp);

        int tempLen = len1;
        len1 = len2;
        len2 = tempLen;
    }

    i = len1 - 1;
    j = len2 - 1;
    k = len1;

    result[k--] = '\0';

    while (j >= 0) {
        int sum = (num1[i] - '0') + (num2[j] - '0') + carry;
        carry = sum / 10;
        result[k--] = (sum % 10) + '0';
        i--;
        j--;
    }

    while (i >= 0) {
        int sum = (num1[i] - '0') + carry;
        carry = sum / 10;
        result[k--] = (sum % 10) + '0';
        i--;
    }

    if (carry) {
        result[k--] = carry + '0';
    }

    printf("Sum: %s\n", &result[k + 1]);
}

int main() {
    char num1[1000], num2[1000], result[1000];
    printf("Enter the first large number: ");
    scanf("%s", num1);
    printf("Enter the second large number: ");
    scanf("%s", num2);

    addLargeNumbers(num1, num2, result);

    return 0;
}
