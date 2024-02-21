#include<stdio.h>
int main()
{
  int a[5]={16,17,7,9,6},i,j,t;
  for(i=0;i<4;i++)
  {
  for(j=0;j<4;j++){
    if(a[j]>a[j+1])
    {
      t=a[j];
      a[j]=a[j+1];
      a[j+1]=t;
    }
    }
  }
  for(j=0;j<4;j++)
  {
  printf("%d\n",a[j]);
  }
  return 0;
}
