#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void selectionSort(int*,int);
void print(int*,int);
void main()
{
    int*ar; 
    int n;
    printf("Enter the size of the array:\n");
    scanf("%d",&n);
    ar=(int*)malloc(n*sizeof(int)); //dynamically creating array
    printf("Enter the elements:\n");
    for(int i=0;i<n;i++)
    {
    scanf("%d",&ar[i]);
    }
    printf("Array before sorting:\n");
    print(ar,n);
    selectionSort(ar,n);
    printf("\nArray after sorting:\n");
    print(ar,n);
    getch();
}
void selectionSort(int* ar,int n)
{
    for(int i=0;i<n-1;i++)
    {
        int minIndex=i;
        for(int j=i+1;j<n;j++)
        {
           if(ar[minIndex]>ar[j])
           {
              minIndex=j;
           }
        }
        int temp=ar[minIndex];
        ar[minIndex]=ar[i];
        ar[i]=temp;
    }
}
void print(int* ar,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",ar[i]);
    }
}