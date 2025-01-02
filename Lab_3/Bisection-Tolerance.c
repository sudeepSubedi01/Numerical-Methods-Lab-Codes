#include<stdio.h>
#include<conio.h>
#include<math.h>

float f(float x){
  // return x*x*x-4*x-9;
  // return 1/(x*x*x) + sin(x);
  return x*sin(x) + cos(x);
}


int main(){
  float a,b,c,tol;
  int i=0,N;
  printf("Enter initial interval [a,b]:");
  scanf("%f%f",&a,&b);

  printf("Enter tolerance:");
  scanf("%f",&tol);

  printf("Enter max iterations:");
  scanf("%d",&N);

  printf("\ni\t\ta\t\tb\t\tc\t\tf(c)\n");

  if (f(a)*f(b)>=0){
    printf("Invalid interval! f(a) and f(b) must have opposite signs.\n");
    return 1;
  }
  do {
    c = (a + b)/2;

    printf("%d\t%f\t%f\t%f\t%f\n",i,a,b,c,f(c));

    if ( f(c) * f(a) < 0 ){
      b = c;
    }
    else{
      a = c;
    }
    i++;
    if (i>=N){
      break;
    }
  }while(fabs(f(c))>tol);


  printf("\nThe root is: %f",c);

  return 0;
}