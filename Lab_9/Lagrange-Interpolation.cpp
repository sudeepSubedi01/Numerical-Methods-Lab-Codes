#include<iostream>
#include<conio.h>
using namespace std;

int main(){
  int i,j,n;
  float x[100],y[100],xp,s=0,p=1;

  cout<<"Enter the number of data points: ";
  cin>>n;

  cout<<"Enter x value to be interpolated:";
  cin>>xp;

  cout<<"Enter the data points:"<<endl;
  for(i=0;i<n;i++){
    cout<<"Enter x["<<i<<"],y["<<i<<"]: ";
    cin>>x[i]>>y[i];
  }
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(i!=j){
        p= p * (xp-x[j]) / (x[i]-x[j]);
      }
    }
    s = y[i] * p + s;
    p=1;
  }
  cout<<"y["<<xp<<"] = "<<s;
}