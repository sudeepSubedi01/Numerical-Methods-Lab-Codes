#include<stdio.h>
#include<conio.h>
#include<math.h>

int main() {
  float x[100],y[100],sum_x=0,sum_Y=0,sum_x2=0,sum_x_Y=0,a,b,Y[100],A,B; 
  int i,n;
  printf("Enter the number of data points:");
  scanf("%d",&n);
  printf ("Input x and y data alternatively:");
  for(i=0;i<n;i++){
    scanf("%f",&x[i]);

    scanf("%f",&y[i]);

    Y[i] = log(y[i]);

    sum_x = sum_x + x[i];

    sum_Y = sum_Y + Y[i];

    sum_x2= sum_x2 + x[i] * x[i];

    sum_x_Y = sum_x_Y + x[i] * Y[i];
  }

  A = (sum_Y * sum_x2 - sum_x * sum_x_Y)/(n * sum_x2 - sum_x * sum_x );

  B = (n * sum_x_Y - sum_x * sum_Y)/(n * sum_x2 - sum_x * sum_x);

  a = exp(A);
  b = B;

  printf("----------------------------------------------------------------");

  printf("\nFindings from the data\n");

  printf("Initial Value(Scaling Factor)=%f",b);

  printf("\nRate Constant(Growth Rate)=%f",a);

  if(b<0){
    printf("\nRegression Line: y = %f exp(-%f x) ",a,-b);
  }
  else{
    printf("\nRegression Line: y = %f exp(%f x) ",a,b);
  }
}



//Pseudo Code For the Program
/*
START

    DECLARE arrays x[100], y[100], Y[100] (to store data points and log-transformed y values)
    DECLARE sum_x, sum_Y, sum_x2, sum_x_Y, a, b, A, B (all initialized to 0)
    DECLARE integer i, n (for number of data points and loop index)

    PRINT "Enter the number of data points:"
    READ n (number of data points)

    PRINT "Input x and y data alternatively:"
    
    FOR i = 0 TO n-1 DO
        READ x[i] (input x data point)
        READ y[i] (input y data point)
        
        Y[i] = log(y[i]) 

        sum_x = sum_x + x[i]
        sum_Y = sum_Y + Y[i]
        sum_x2 = sum_x2 + x[i] * x[i]
        sum_x_Y = sum_x_Y + x[i] * Y[i]
    END FOR

    A = (sum_Y * sum_x2 - sum_x * sum_x_Y) / (n * sum_x2 - sum_x * sum_x)
    B = (n * sum_x_Y - sum_x * sum_Y) / (n * sum_x2 - sum_x * sum_x)

    a = exp(A) 
    b = B      

    PRINT "--------------------------------------------------------------"
    PRINT "Findings from the data"
    PRINT "Slope = ", b
    PRINT "Intercept = ", a

    IF b < 0 THEN
        PRINT "Regression Line: y = ", a, " exp(-", -b, " x)"
    ELSE
        PRINT "Regression Line: y = ", a, " exp(", b, " x)"
    END IF

END

*/