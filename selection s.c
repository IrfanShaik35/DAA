#include<stdio.h>
int main()
{
  int a[5]={16,17,7,9,6},i,j,min,t;
  for(i=0;i<4;i++)
  {
  min=i;
  for(j=i+1;j<5;j++){
    if(a[j]<a[min])
    {
      min=j;
    }
    }
    t=a[i];
    a[i]=a[min];
    a[min]=t;
  }
  for(j=0;j<4;j++)
  {
  printf("%d\n",a[j]);
  }
  return 0;
}
