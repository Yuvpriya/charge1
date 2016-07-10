#include<stdio.h>
#include<conio.h>
void main()
{
int a,p,i,j,count=0;
clrscr();
printf("\n Enter the snumber of students:");
scanf("%d",&a);
p=2*a;
for(i=0;i<p;i++)
{
for(j=i+1;j<=p;j++)
 {
 printf("\n%d\t%d\n",i,j);
 count++;
 }  }
 printf("the daily walk combination is %d",count);
 getch();
}
