#include<stdio.h>
#include<conio.h>

int main() {
  float x[100],y[100],sum_x=0,sum_y=0,sum_x2=0,sum_x_y=0,a,b; 
  int i,n;
  printf("Enter the number of data points:");
  scanf("%d",&n);
  printf ("Input x and y data alternatively:");
  for(i=0;i<n;i++){
    scanf("%f",&x[i]);

    scanf("%f",&y[i]);

    sum_x = sum_x + x[i];

    sum_y = sum_y + y[i];

    sum_x2= sum_x2 + x[i] * x[i];

    sum_x_y = sum_x_y + x[i] * y[i];
  }

  a= (sum_y * sum_x2 - sum_x * sum_x_y)/(n * sum_x2 - sum_x * sum_x );

  b = (n * sum_x_y - sum_x * sum_y)/(n * sum_x2 - sum_x * sum_x);

  printf("----------------------------------------------------------------");

  printf("\nFindings from the data\n");

  printf("Slope=%f",b);

  printf("\nIntercept=%f",a);

  if(b<0){
    printf("\nRegression Line: y = %f - %f x ",a,-b);
  }
  else{
    printf("\nRegression Line: y = %f + %f x ",a,b);
  }
}



//Pseudo Code For the Program
/*
START

    DECLARE arrays x[100], y[100] (to store data points)
    DECLARE sum_x, sum_y, sum_x2, sum_x_y, a, b (all initialized to 0)
    DECLARE integer i, n (for number of data points and loop index)

    PRINT "Enter the number of data points:"
    READ n (number of data points)

    PRINT "Input x and y data alternatively:"
    
    FOR i = 0 TO n-1 DO
        READ x[i] (input x data point)
        READ y[i] (input y data point)
        
        sum_x = sum_x + x[i]
        sum_y = sum_y + y[i]
        sum_x2 = sum_x2 + x[i] * x[i]
        sum_x_y = sum_x_y + x[i] * y[i]
    END FOR

    a = (sum_y * sum_x2 - sum_x * sum_x_y) / (n * sum_x2 - sum_x * sum_x)
    b = (n * sum_x_y - sum_x * sum_y) / (n * sum_x2 - sum_x * sum_x)

    PRINT "--------------------------------------------------------------"
    PRINT "Findings from the data"
    PRINT "Slope = ", b
    PRINT "Intercept = ", a

    IF b < 0 THEN
        PRINT "Regression Line: y = ", a, " - ", -b, "x"
    ELSE
        PRINT "Regression Line: y = ", a, " + ", b, "x"
    END IF

END
*/