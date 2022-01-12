#include<stdio.h>
void main()
{
int arr1[50],arr2[50],arr3[100],m,n,i,j,k=0;
clrscr();
printf("\n Enter size of array 1: ");
scanf("%d",&m);
printf("\n Enter sorted elements of array 1: \n");
for(i=0;i<m;i++)
{
scanf("%d",&arr1[i]);
}
printf("\n Enter size of array 2: ");
scanf("%d",&n);
printf("\n Enter sorted elements of array 2: \n");
for(i=0;i<n;i++)
{
scanf("%d",&arr2[i]);
}
i=0;
j=0;
while(i<m&&j<n)
{
if(arr1[i]<arr2[j])
{
arr3[k]=arr1[i];
i++;
}
else
{
arr3[k]=arr2[j];
j++;
}
k++;
}
if(i>=m)
{
while(j<n)
{
arr3[k]=arr2[j];
j++;
k++;
}
}
if(j>=n)
{
while(i<m)
{
arr3[k]=arr1[i];
i++;
k++;
}
}
printf("\n After merging: \n");
for(i=0;i<m+n;i++)
{
printf("%d ",arr3[i]);
}
getch();
}