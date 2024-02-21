#include <stdio.h>
void gl(int,int,int,int);
int main()
{
  int a=24,b=30,i,c=0;
  gl(a,b,1,0);
  return 0;
}
void gl(int a,int b,int c,int d)
{

   if(c<=b)
   {
      if(a%c==0 && b%c==0)
      {
        d=c;
      }
      gl(a,b,c+1,d);

   }
   else
   {
     printf("gcd %d\n",d);
    printf("lcm %d",a*b/d);
   }
}
