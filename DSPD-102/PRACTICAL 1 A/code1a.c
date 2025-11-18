//AIM:1 A.	Write a program to accept ‘n’ numbers into an array and then calculate the sum of numbers present 
//in odd positions and even positions respectively.//roll no 102
#include <stdio.h>

int main() {
    int n, i, sumOdd = 0, sumEven = 0;

     
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

     
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

     
    for (i = 0; i < n; i++) {
        if ((i + 1) % 2 == 0) {  
            sumEven += arr[i];
        } else {  
            sumOdd += arr[i];
        }
    }

     
    printf("Sum of numbers at odd positions: %d\n", sumOdd);
    printf("Sum of numbers at even positions: %d\n", sumEven);

    return 0;
}