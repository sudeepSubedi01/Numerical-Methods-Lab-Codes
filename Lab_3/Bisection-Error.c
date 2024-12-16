#include<stdio.h>
#include<conio.h>
#include<math.h>

float f(float x){
  return x*x*x-4*x-9;
}


int main(){
  float a,b,c,tol,xn,xn_1,error;
  int i=1;
  printf("Enter initial interval [a,b]:");
  scanf("%f%f",&a,&b);

  printf("Enter tolerance:");
  scanf("%f",&tol);

  printf("\ni\t\ta\t\tb\t\tc\t\tf(c)\n");

  do {
    c = (a + b)/2;

    printf("%i\t%f\t%f\t%f\t%f\n",i,a,b,c,f(c));

    if ( f(c) * f(a) < 0 ){
      b = c;
    }
    else{
      a = c;
    }
    if (i>1){
      xn_1 = xn;
    }
    xn = f(c);
    error = fabs(xn-xn_1);
    i+=1;
  }while(error>tol);

  printf("\nThe root is: %f",c);

  return 0;
}