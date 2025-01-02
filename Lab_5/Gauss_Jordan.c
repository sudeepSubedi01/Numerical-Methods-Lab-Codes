#include<stdio.h>
#include<conio.h>
#include<math.h>

int main(){
  int i,j,n,k;
  float a[100][100], tol, temp, X[100];

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

  for (j=1;j<=n;j++){
    if (fabs(a[j][j]) <= tol){
      printf("Diagonal Element close to zero.....");
      return 1;
    }
    for(i=1;i<=n;i++){
      if (i != j){
        temp = a[i][j] / a[j][j];
        for(k=1;k<=n+1;k++){
          a[i][k] = a[i][k] - temp * a[j][k];
        }
      }
    }
  }
  printf("Diagonal form of the equations:\n");
  for(i=1;i<=n;i++){
    for(j=1;j<=n+1;j++){
      printf("%f\t",a[i][j]);
    }
    printf("\n");
  }

  printf("The solution by Gauss-Jordan:\n");
  for(i=1;i<=n;i++){
    X[i] = a[i][n+1] / a[i][i];
    printf("X[%d] = %f\n", i,X[i]);
  }
}