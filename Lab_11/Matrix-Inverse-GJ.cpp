// -2   1
// 1.5  -0.5


#include<iostream>
#include<conio.h>
#include<cmath>  // For mathematical functions like abs()
using namespace std;

int main() {
    float a[100][100], factor, tol;
    int i, j, k, n;

    cout<<"Enter size of square matrix: ";
    cin>>n;

    cout<<"Enter tolerance value: ";
    cin>>tol;

    cout << "Enter matrix elements: " << endl;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            cout<<"Enter element a["<<i<<"]["<<j<<"] : ";
            cin>>a[i][j];
        }
    }

    // Input the matrix a
    a[1][1] = 1;
    a[1][2] = 2;
    a[2][1] = 3;
    a[2][2] = 4;

    // Augmenting the matrix with the identity matrix
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            if(i == j) {
                a[i][j + n] = 1; // Identity matrix on the right side
            } else {
                a[i][j + n] = 0; // Other elements are zero
            }
        }
    }

    // Applying Gauss-Jordan elimination
    for(i = 1; i <= n; i++) {
        if(fabs(a[i][i]) <= tol) {
            cout << "Diagonal element is zero, can't proceed with Gauss-Jordan method!" << endl;
            return 1;  // Exit if diagonal element is zero
        }

        // Normalize the pivot row
        float pivot = a[i][i];
        for(k = 1; k <= 2 * n; k++) {
            a[i][k] /= pivot;  // Divide the entire row by the pivot element
        }

        // Eliminate other rows
        for(j = 1; j <= n; j++) {
            if(i != j) {
                factor = a[j][i] / a[i][i];  // Find the factor to eliminate the element
                for(k = 1; k <= 2 * n; k++) {
                    a[j][k] -= factor * a[i][k];  // Apply row operation
                }
            }
        }
    }

    // Printing the inverse matrix
    cout << "Inverse of matrix: " << endl;
    for(i = 1; i <= n; i++) {
        for(j = n + 1; j <= 2 * n; j++) {
            cout << a[i][j] << "\t";  // Print the right half of the augmented matrix
        }
        cout << endl;
    }

    return 0;
}