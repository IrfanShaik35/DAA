#include <stdio.h>

int main()
{
  int a[5],min,max,i;
  for(i=0;i<5;i++)
  {
    printf("enter\n");
    scanf("%d",&a[i]);
  }

  min=a[0];
  max=a[0];
  for(i=0;i<5;i++)
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
}

