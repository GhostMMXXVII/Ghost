#include<stdio.h>
int main (){
int
a[100],n,i,j,temp,key,first,mid,last,flag;

        printf("Enter the size of array: ");
        scanf("%d", &n);
        printf("Enter the array elements: ");

for(i=0;i<n;i++)
        scanf("%d" , &a[i]);

for(i=1;i<n;i++)
for(j=0;j<(n-1);j++)

        if(a[j]<a[j+1])
        {temp=a[j];
         a[j]=a[j+1];
         a[j+1]=temp;
        }
 printf("\nArray after sorting: ");

for(i=0;i<n;++i)
   printf("%d    ", a[i]);

printf("\nEnter the element to search: ");
scanf("%d", &key);

first=0;
last=n-1;

while(first<=last)
{
mid=(first+last)/2;
if (key==a[mid]){
flag=1;
break;}
else
if(key<a[mid])
first=mid+1;
else
last=mid-1;
}
if (flag==1)
printf("\nElement found at position %d\n",mid+1);
else
printf("\nElement not found");
return (0);}
