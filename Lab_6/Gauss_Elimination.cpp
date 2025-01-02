#include<stdio.h>
#include<conio.h>
#include<math.h>

int main(){
  int i,j,n,k;
  float a[100][100], tol, temp, X[100], sum;

  printf("Enter the number of unknowns:");
  scanf("%d",&n);

  printf("Enter the tolerance:");
  scanf("%f",&tol);

  for(i=1;i<=n;i++){
    for(j=1;j<=n+1;j++){
      printf("Enter element a[%d][%d]:",i,j);
      scanf("%f",&a[i][j]);
    }
  }

  printf("The system of equations:\n");
  for(i=1;i<=n;i++){
    for(j=1;j<=n+1;j++){
      printf("%f\t",a[i][j]);
    }
    printf("\n");
  }

  for (j=1;j<=n-1;j++){
    if (fabs(a[j][j]) <= tol){
      printf("Diagonal Element close to zero.....");
      return 1;
    }
    for(i=j+1;i<=n;i++){
      temp = a[i][j] / a[j][j];
      for(k=1;k<=n+1;k++){
        a[i][k] = a[i][k] - temp * a[j][k];
      }
    }
  }

  X[n] = a[n][n+1] / a[n][n];
  for (i=n-1;i>=1;i--){
    sum = 0;
    for (j=i+1;j<=n;j++){
      sum = sum + a[i][j] * X[j];
    }
    X[i] = (a[i][n+1] - sum)/a[i][i];
  }

  printf("Triangular form of the equations:\n");
  for(i=1;i<=n;i++){
    for(j=1;j<=n+1;j++){
      printf("%f\t",a[i][j]);
    }
    printf("\n");
  }

  printf("The solution by Gauss-Elimination:\n");
  for(i=1;i<=n;i++){
    printf("X[%d] = %f\n", i,X[i]);
  }
}