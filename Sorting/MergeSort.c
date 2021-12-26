#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
void mergeSort(int *, int, int);
int merge(int *, int, int, int);
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
    mergeSort(ar, 0, n - 1);
    printf("\nArray after sorting:\n");
    print(ar, n);
    getch();
}
void mergeSort(int *ar, int l, int r)
{
    printf("in ms\n");
    if (l < r)
    {
        int mid = l+(r - l) / 2;
        mergeSort(ar, l, mid);
        mergeSort(ar, mid + 1, r);
        merge(ar, l, mid, r);
    }
}
int merge(int *ar, int l, int mid, int r)
{
    int i, j, k;
    int n1 = mid - l + 1;
    int n2 = r - mid;
    //int *l = (int *)malloc(n1 * sizeof(int));
    //int *r = (int *)malloc(n2 * sizeof(int));
    int L[n1],R[n2];
    for (i = 0; i < n1; i++)
    {
        L[i] = ar[l + i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = ar[mid + 1 + j];
    }
    i = 0, j = 0, k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            ar[k] = L[i];
            i++;
        }
        else
        {
            ar[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        ar[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        ar[k] = R[j];
        j++;
        k++;
    }
}
void print(int *ar, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", ar[i]);
    }
}