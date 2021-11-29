#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int binarySearch(int*,int,int,int);
void main()
{
    int n,k;
    int *ar;
    printf("Enter the size of array:\n");
    scanf("%d",&n);
    ar=(int*)malloc(n*sizeof(int));
    printf("Enter the elements:\n");
    for(int i=0;i<n;i++)
    {
      scanf("%d",&ar[i]);
    }
    printf("Enter the element to be searched\n");
    scanf("%d",&k);
    int found=binarySearch(ar,0,n,k);
    if(found==-1)
    printf("%d is not present in the array.",k);
    else
    printf("%d is present in the array at index %d.",k,found);
    getch();
}
int binarySearch(int* ar,int l,int r,int k)
{
    if(l<=r)
    {
    int mid=(r+l)/2;
    if(ar[mid]==k)
    return mid;
    else if(k>ar[mid])
    return binarySearch(ar,mid+1,r,k);
    else
    return binarySearch(ar,l,mid-1,k);
    }
    return -1;
}