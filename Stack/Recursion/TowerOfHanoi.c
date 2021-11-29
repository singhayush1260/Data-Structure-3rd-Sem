#include<stdio.h>
#include<conio.h>
void towerOfHanoi(int,char,char,char);
void main()
{
    int n;
    char disk1,disk2,disk3;
    printf("Enter the number of disks:");
    scanf("%d",&n);
    printf("Enter the name of three disks:\n");
    scanf("  %c",&disk1);
    scanf("  %c",&disk2);
    scanf("  %c",&disk3);
    towerOfHanoi(n,disk1,disk2,disk3);
    getch();
}
void towerOfHanoi(int n,char disk1,char disk2,char disk3)
{
    if(n==0)
    return;
    towerOfHanoi(n-1,disk1,disk3,disk2);
    printf("Move disk %d from disk %c to disk %c\n",n,disk1,disk2);
    towerOfHanoi(n-1,disk3,disk2,disk1);
}