#include <stdio.h>
int prime(int,int,int);
int main()
{
  int a=7,count=0,b=1,d;
  d=prime(a,count,b);
  if(d==2)
  {
    printf("prime");
  }
  else{
    printf("not prime");
  }
  return 0;
}
int prime(int a,int c,int b)
{
  if(b<=a)
  {
     if(a%b==0)
     {
       c++;
     }
     prime(a,c,b+1);
  }
  else
  {
    return c;
  }
}
