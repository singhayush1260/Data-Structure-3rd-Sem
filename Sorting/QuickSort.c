#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void quickSort(int *, int, int);
int partitioning(int *, int, int);
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
    quickSort(ar, 0, n - 1);
    printf("\nArray after sorting:\n");
    print(ar, n);
    getch();
}
void quickSort(int *ar, int lb, int ub)
{
    printf("in qs\n");
    if (lb < ub)
    {
        int i = partitioning(ar, lb, ub);
        quickSort(ar, lb, i - 1);
        quickSort(ar, i + 1, ub);
    }
}
int partitioning(int *ar, int lb, int ub)
{
    printf("in pa\n");
    int pivot = ar[lb];
    int start = lb;
    int end = ub;
    while (start < end)
    {
        while (ar[start] <= pivot)
            start++;
        while (ar[end] > pivot)
            end--;
        if (start < end)
        {
            int temp = ar[start];
            ar[start] = ar[end];
            ar[end] = temp;
        }
    }
    int temp = ar[end];
    ar[end] = ar[lb];
    ar[lb] = temp;
    return end;
}
void print(int *ar, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ar[i]);
    }
}