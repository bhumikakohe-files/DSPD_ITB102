

#include <stdio.h>

int main() {
    int n, i;
    int arr[100];
    int odd_sum = 0;
    int even_sum = 0;

    printf("Enter the number of elements (n): ");
    scanf("%d", &n);

    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (i = 0; i < n; i++) {
        if (i % 2 == 0) {
            odd_sum += arr[i];
        } else {
            even_sum += arr[i];
        }
    }

    printf("Sum of numbers at odd positions: %d\n", odd_sum);
    printf("Sum of numbers at even positions: %d\n", even_sum);

    return 0;
}


