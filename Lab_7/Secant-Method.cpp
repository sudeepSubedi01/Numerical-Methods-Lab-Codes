#include<iostream>
#include<conio.h>
#include<math.h>
using namespace std;

float f(float x){
  //return x*x*x-4*x-9;           // root=2.706528  //initial guess= (3,4)
  //return 1/(x*x*x)+sin(x);      // root=
  return x*sin(x)+cos(x);       // root=2.7983
}

int main(){
  int N,i=0;
  float a,b,c,tol;

  cout<<"Enter initial guess (a,b):" ;
  cin>>a>>b;

  cout<<"Enter tolerance: ";
  cin>>tol;

  cout<<"Enter the max number of iterations:";
  cin>>N;
  
  do{
    if(fabs(f(b)-f(a)) <= tol){
      cout<<"f(a) and f(b) are nearly equal....";
      return 1;
    }
    c = (a*f(b) - b*f(a)) / (f(b)-f(a));
    a=b;
    b=c;
    if(fabs(f(c)) <= tol){
      break;
    }
    i++;
  }while(i<N);
  cout<<"The approximated root is: "<< c <<endl;
  cout<<"The functional value f(c) is: "<< f(c) <<endl;
}