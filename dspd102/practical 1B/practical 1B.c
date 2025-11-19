

#include <stdio.h>

int main() 
{
    int n, arr[100], search;
    int start = 0, mid, high, i, found = 0;

    printf("Enter the range of array: ");
    scanf("%d", &n);

    high = n - 1;

    printf("Enter the %d elements of sorted array:\n", n);
    for(i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Enter the element you want to search: ");
    scanf("%d", &search);

    while(start <= high)
    {
        mid = (start + high) / 2;

        printf("Start = %d\n", start + 1);
        printf("Mid = %d\n", mid + 1);
        printf("End = %d\n", high + 1);

        if(arr[mid] == search)
        {
            printf("The element is found at position %d\n", mid + 1);
            found = 1;
            break;
        }
        else if(search < arr[mid])
        {
            high = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }

    if(!found)
    {
        printf("The element is not present in the array.\n");
    }

    return 0;
}


