#include<stdio.h>
#include<conio.h>

float f(float x){
  return x*x*x-4*x-9;
}


int main(){
  float a,b,c;
  int i;
  printf("Enter initial interval [a,b]:");
  scanf("%f%f",&a,&b);

  printf("\ni\t\ta\t\tb\t\tc\t\tf(c)\n");

  for(i=0;i<11;i++){
    c = (a + b)/2;

    printf("%i\t%f\t%f\t%f\t%f\n",i,a,b,c,f(c));

    if ( f(c) * f(a) < 0 ){
      b = c;
    }
    else{
      a = c;
    }

  }
  printf("\nThe root is: %f",c);

  return 0;
}