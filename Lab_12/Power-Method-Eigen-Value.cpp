#include<iostream>
#include<conio.h>
#include<cmath>
using namespace std;

float max_val (float arr[], int n) {
  int i;
  float maxValue;
  maxValue = fabs(arr[1]);
  for (i = 1 ; i <= n; i++) {
    if (fabs(arr[i]) > maxValue){
      maxValue = arr[i];
    }
  }
  cout << "Max value = " << maxValue << endl;
  return maxValue;
}

int main(){
  float a [10][10], x[10], y[10], z[10], D[10], temp, z_max, D_max, tol = 0.0001;
  int n, i, j,iteration=1;

  cout << "Enter size of square matrix: ";
  n = 4;

  cout << "Enter the matrix: "<<endl;
  // a[1][1] = 3 ;
  // a[1][2] = 2 ;
  // a[1][3] = 3 ;
  // a[2][1] = 2 ;
  // a[2][2] = 4 ;
  // a[2][3] = 6 ;
  // a[3][1] = 3 ;
  // a[3][2] = 6 ;
  // a[3][3] = 9 ;

  // a[1][1] = -2.1 ;
  // a[1][2] = 11 ;
  // a[1][3] = -5 ;
  // a[2][1] = 2 ;
  // a[2][2] = 14.9 ;
  // a[2][3] = -7 ;
  // a[3][1] = -4 ;
  // a[3][2] = 26 ;
  // a[3][3] = -12.1 ;

  a[1][1] = -5 ;
  a[1][2] = 6 ;
  a[1][3] = 7 ;
  a[1][4] = 2 ;
  a[2][1] = 1 ;
  a[2][2] = 9 ;
  a[2][3] = -2 ;
  a[2][4] = 6 ;
  a[3][1] = 4 ;
  a[3][2] = 6 ;
  a[3][3] = -6 ;
  a[3][4] = -1 ;
  a[4][1] = 4 ;
  a[4][2] = 2 ;
  a[4][3] = 12 ;
  a[4][4] = 18 ;

  // for(i=1 ; i<=n ; i++){
  //   for(j=1 ; j<=n ; j++){
  //     cin>>a[i][j];
  //   }
  // }

  cout << "Matrix A:" << endl;
  for(i=1 ; i<=n ; i++){
    for(j=1 ; j<=n ; j++){
      cout<<a[i][j]<<'\t';
    }
    cout<<endl;
  }

  for(i=1 ; i<=n ; i++){
    x[i] = 1;
  }

  do{
    cout<<endl<<"Iteration = " <<iteration<<endl;
    for(i=1 ; i<=n ; i++){
      temp = 0;
      for(j=1 ; j<=n ; j++){
        temp = temp + a[i][j] * x[j];
      }
      z[i] = temp;
    }
    cout<<"Matrix Mul: ";
    for(i=1 ; i<=n ; i++){
      cout<< z[i] << "\t";
    }
    cout<<endl;
    
    z_max = max_val(z,n);

    for(i=1 ; i<=n ; i++){
      y[i] = z[i] / z_max;
      D[i] = fabs(x[i] - y[i]);
    }

    for(i=1 ; i<=n ; i++){
      x[i] = y[i];
    }

    D_max = max_val(D,n);

    // if(D_max <= tol){
    //   break;
    // }

    iteration +=1;
  }while(D_max >= tol);

  cout << endl;
  cout<<"Eigen Value: "<<z_max<<endl;
  cout<<"Eigen Vector: "<<endl;
  for(i=1 ; i<=n ; i++){
    cout<<x[i]<<"\t";
  }

  return 0;
}
