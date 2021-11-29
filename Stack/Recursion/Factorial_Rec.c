#include<stdio.h>
#include<conio.h>
int fact(int);
void main()
{
    int n;
    printf("Enter the number:");
    scanf("%d",&n);
    int factorial=fact(n);
    printf("Factorial of %d is %d.",n,factorial);
    getch();
}
int fact(int n)
{
    if(n==0)
    return 1;
    else
    return n*fact(n-1);
}