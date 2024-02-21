#include<stdio.h>
int arm(int,int);
int main()
{
  int a=153,b,c;
  b=a;
  c=arm(b,0);
  if(c==a)
  {
    printf("armstrong");

  }
  else
  {
    printf("not");
  }
  return 0;
}
int arm(int b,int s)
{
   static int sum=0;
   if(b>0)
   {
   sum=sum+pow((b%10),3);
   arm(b/10,sum);
   }
   else
   {
     return sum;
   }

}
