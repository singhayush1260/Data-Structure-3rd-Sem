#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
void bubbleSort(int*,int);
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
    bubbleSort(ar,n);
    printf("\nArray after sorting:\n");
    print(ar,n);
    getch();
}
void bubbleSort(int* ar,int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(ar[i]>ar[j])
            {
                int temp=ar[i];
                ar[i]=ar[j];
                ar[j]=temp;
            }
        }
    }
}
void print(int* ar,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",ar[i]);
    }
}