#include<stdio.h>
#include<conio.h>
#include<math.h>

float f(float x){
  // return x*x*x-4*x-9;                     //initial guess = 3
  // return x*sin(x)+cos(x);              //initial guess = 3
  return 1/(x*x*x)+sin(x);            //initial guess = 4
}

float f_dash(float x){
  // return 3*x*x-4;
  // return x*cos(x);
  return -3/(x*x) + cos(x);
}

int main(){
  int i=1,N;
  float x_old,x_new,tol,error;

  printf("Enter initial guess:");
  scanf("%f",&x_old);

  printf("Enter tolerance:");
  scanf("%f",&tol);

  printf("Enter max iteration:");
  scanf("%d",&N);

  printf("\ni\tx_old\t\tf(x_old)\tf'(x_old)\tx_new\n");

  do{
    if (fabs(f_dash(x_old)) <= tol){
      printf("Derivative too close to zero");
      return 1;
    }

    x_new = x_old - (f(x_old)/f_dash(x_old));
    printf("\n%d\t%f\t%f\t%f\t%f\n",i,x_old,f(x_old),f_dash(x_old),x_new);

    error = fabs(x_old - x_new);

    if (error <= tol){
      break;
    }

    x_old = x_new;

    if (i>=N){
      break;
    }

    i++;
  }while(error >= tol);

  printf("The approximated root is: %f",x_new);

  return 0;
}