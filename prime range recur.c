#include<stdio.h>
void prime(int,int);
int main(){

   int a,b;
   printf("enter a");
   scanf("%d",&a);
   printf("enter b");
   scanf("%d",&b);
   prime(a,b);

   return 0;
}
void prime(int a,int b)
{
     int c=1,d=0;
     if(a<=b)
     {
        while(c<=a)
        {
          if(a%c==0)
          {
            d++;
          }
          c++;
        }
        if(d==2)
        {
           printf("%d\n",a);
        }
        a++;
        prime(a,b);
     }
}
