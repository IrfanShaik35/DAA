#include <stdio.h>

int main()
{
  int a[7]={23,56,25,67,78,23,2},min,max,i;
  min=a[0];
  max=a[0];
  for(i=0;i<7;i++)
  {
  if(a[i]>max)
  {
  max=a[i];
  }
  else if(a[i]<min)
  {
  min=a[i];
  }
  }
  printf("max %d",max);
  printf("min %d",min);
  return 0;
}

