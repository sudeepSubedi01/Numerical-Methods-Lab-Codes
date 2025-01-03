#include<conio.h>
#include<iostream>
#include<math.h>
using namespace std;

int gauss_jordan (double a [] [100], double tol, int d) {
  double X[100],factor;
  int i,j,k;
  int n=d+1;
  for(j=0;j<n;j++){
    if (fabs(a[j][j]) <= tol) {
      cout<<"Diagonal element close to zero....."<<endl; 
      return 1;
    }
    for(i=0;i<n;i++){
      if(i!= j){ 
        factor = a[i][j] / a[j][j];
        for(k=0;k<n+1;k++){
          a[i][k] = a[i][k] - factor * a[j][k];
        }
      }
    }
  }

  cout<<"The simplified matrix:"<<endl;
  for(i=0;i<=d; i++){
    for(j=0;j<=d+1 ;j++){
      cout<< a[i][j] <<"\t\t";
    }
    cout<<endl;
  }

  cout<<"The Polynomial Coefficients: "<<endl;
  for(i=0;i<n;i++){
    X[i]=a[i][n] / a[i][i];
    cout<<"X["<<i<<"] = "<<X[i]<<endl;
  }
}

int main(){
  int n,i,j,k,d;
  double x[100],y[100],a[100][100],tol;

  cout<<"Enter the number of data points: ";
  cin>>n;

  cout<<"Enter degree of polynomial:";
  cin>>d;

  cout<<"Enter tolerance value: ";
  cin>>tol;

  cout<<"Enter the data points: "<<endl;
  for(i=0; i<n;i++){
    cout<<"Enter (x["<<i<<"]"<<" , y["<<i<<"])"<<endl;
    cin>>x[i]>>y[i];
  }

  if(n<=d){
    cout<<"Invalid values of n and d...";
    return 1;
  }

  for(i=0 ; i<=d ;i++){
    for(j=0;j<=d;j++){
      for(k=0;k<=n-1;k++){
        a[i][j] = a[i][j] + pow(x[k],i+j);
      }
    }
  }

  for(i=0;i<=d;i++){
    for(k=0;k<=n-1;k++){
      a[i][d+1] = a[i][d+1] + pow(x[k],i) * y[k];
    }
  }

  cout<<"The sum matrix: "<<endl;
  for(i=0 ; i<=d ;i++){
    for(j=0;j<=d;j++){
      cout<<a[i][j]<<"\t";
    }
    cout<<endl;
  }

  gauss_jordan(a,tol,d);
  return 0;
}