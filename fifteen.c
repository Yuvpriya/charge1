#include<stdio.h>
#include<conio.h>
void main()
{
int array[100],n,i,j,store=0;
clrscr();
printf("Enter the size of array\n");
scanf("%d",&n);
printf("enter the array element");
for(i=0;i<n;i++)
{
scanf("%d",&array[i]);
}
for(i=0;i<n;i++)
for(j=i+1;j<n;j++)
{
if(array[i]<array[j])
{
store=array[i];
array[i]=array[j];
array[j]=temp;
}
}
for(i=0;i<n;i++)
printf("%d\n",array[i]);
getch();
}
Status API Trainin
