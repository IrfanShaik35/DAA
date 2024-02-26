#include<stdio.h>
int main()
{
  int a[5],key,pos,flag=0,i,j;
  for(i=0;i<5;i++)
  {
     printf("enter\n");
     scanf("%d",&a[i]);
  }
  printf("enter key");
  scanf("%d",&key);
  int l=0,h=4,mid;
  while(l<=h)
  {
    mid=(l+h)/2;
    if(a[mid]==key)
    {
       flag=1;
       pos=mid+1;
       break;

    }
    if(a[mid]>key)
    {
      h=mid-1;

    }
    if(a[mid]<key)
    {
      l=mid+1;
    }
  }
  if(flag==1)
  {
     printf("pos %d",pos);
  }
  else
  {
    printf("not found");
  }
  return 0;
}
