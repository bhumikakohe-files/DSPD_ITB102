//AIM:   C.	Write a program which creates a structure Student which must have the attribute Avg Marks with 3 more 
//attributes sort the list of the student in descending order using Bubble sort.	
//roll no 102
#include <stdio.h>
#include <string.h>


struct Student {
    char name[50];
    int rollNo;
    float avgMarks;
    int age;
};
 
void swap(struct Student *a, struct Student *b) {
    struct Student temp = *a;
    *a = *b;
    *b = temp;
}

 
void bubbleSort(struct Student students[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (students[j].avgMarks < students[j + 1].avgMarks) {
                swap(&students[j], &students[j + 1]);
            }
        }
    }
}

int main() {
    int n;

    
    printf("Enter the number of students: ");
    scanf("%d", &n);

    struct Student students[n];

     
    for (int i = 0; i < n; i++) {
        printf("\nEnter details for student %d:\n", i + 1);
        printf("Name: ");
        scanf(" %[^\n]", students[i].name);  
        printf("Roll No: ");
        scanf("%d", &students[i].rollNo);
        printf("Average Marks: ");
        scanf("%f", &students[i].avgMarks);
        printf("Age: ");
        scanf("%d", &students[i].age);
    }

    
    bubbleSort(students, n);

    
    printf("\nStudents sorted by Average Marks (Descending Order):\n");
    for (int i = 0; i < n; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Name: %s\n", students[i].name);
        printf("Roll No: %d\n", students[i].rollNo);
        printf("Average Marks: %.2f\n", students[i].avgMarks);
        printf("Age: %d\n", students[i].age);
    }

    return 0;
}