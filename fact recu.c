#include <stdio.h>
int fac(int);
int main()
{
  int n=5,a;
  a=fac(n);
  printf("%d",a);
  return 0;
}
int fac(int n)
{
  int b;
  if(n==0)
  {
  return 1;
  }
  else
  {
   b=n*fac(n-1);
  }
  return b;

}
