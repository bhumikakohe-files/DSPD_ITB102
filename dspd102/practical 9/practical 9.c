

#include <stdio.h>

#define SIZE 7
int i;
int main() {
    int hash_table[SIZE];
   
    int value,n,index;
    for (i = 0; i < SIZE; i++) {
        hash_table[i] = -1;
    }

    printf("Insert the number of nodes:\n");
    scanf("%d",&n);

    for(i = 0; i<n; i++) {
        printf("Insert the key %d \n",i+1);
        scanf("%d",&value);
        index = value % SIZE;

        while (hash_table[index] != -1) {
            index = (index + 1) % SIZE;
        }
       hash_table[index]=value;
    } 
       

    printf("\nFinal Hash Table (Slots 0-6):\n");
    for (i = 0; i < SIZE; i++) {
        printf("Index  %d-->%d\n", i, hash_table[i]);
    }

    return 0;
}


