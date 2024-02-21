#include<stdio.h>
#include<time.h>

int main()
{
  int a[3][3]={{1,2,3},{4,5,6},{7,8,9}},b[3][3]={{1,2,3},{4,5,6},{7,8,9}},c[3][3],i,j,k;
  clock_t start_time = clock();
  for(i=0;i<3;i++)
  {
    for(j=0;j<3;j++)
    {
      c[i][j]=0;
      for(k=0;k<3;k++)
      {
        c[i][j]+=a[i][k]*b[k][j];
      }

    }
  }
  /*for(i=0;i<3;i++)
  {
    for(k=0;k<3;k++)
    {
        printf("%d\t",c[i][k]);
      }
      printf("\n");

  }*/
  clock_t end_time = clock();

    // Calculate the time taken
    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Time taken for matrix multiplication: %.6f seconds\n", time_taken);
  return 0;

}
