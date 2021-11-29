#include<stdio.h>
#include<conio.h>
int fib(int);
void main()
{
    int n;
    printf("Enter the limit:");
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
    printf("%d ",fib(i));
    // for just the nth term of the series call fib(n) i.e don't use loop 
    getch();
}
int fib(int n)
{
    if(n<2)
    return n;
    else
    return fib(n-1)+fib(n-2);
}