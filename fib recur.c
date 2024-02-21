#include <stdio.h>
void fib(int,int);
int main()
{
   int n=5;
   printf("0 \n 1\n");
   fib(n-2,0);
   return 0;
}
void fib(int n,int sum)
{
   static int n1=0,n2=1,n3;
   if(n>0)
   {

      n3=n1+n2;
      n1=n2;
      n2=n3;
      sum=sum+n3;
      printf("%d\n",n3);
      fib(n-1,sum);
   }
   else
   {
      printf("%d\n",sum+1);
   }
}
