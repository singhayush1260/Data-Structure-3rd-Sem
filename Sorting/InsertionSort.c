#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void insertionSort(int *, int);
void print(int *, int);
void main()
{
    int *ar;
    int n;
    printf("Enter the size of the array:\n");
    scanf("%d", &n);
    ar = (int *)malloc(n * sizeof(int)); // dynamically creating array
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &ar[i]);
    }
    printf("Array before sorting:\n");
    print(ar, n);
    insertionSort(ar, n);
    printf("\nArray after sorting:\n");
    print(ar, n);
    getch();
}
void insertionSort(int *ar, int n)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int temp = ar[i];
        while (j >= 0 && ar[j] > temp)
        {
            ar[j + 1] = ar[j];
            j--;
        }
        ar[j + 1] = temp;
    }
}

void print(int *ar, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ar[i]);
    }
}