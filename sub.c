#include<stdio.h>
#include<conio.h>
void main()
{
char s1[100],s2[50];
intc,count=0;
printf("Enter the string");
for(i=0;i<100;i++)
scanf("%c",&s1[i]);
printf("Enter the substring");
for(i=0;i<50;i++)
scanf("%c",&s2[i]);
for(i=0;i<100;i++)
c=srtcmp(s1[i],s2[i])
if(c==0)
{
count++;
}
printf("The number of occurances is %d",count);
getch()
}
