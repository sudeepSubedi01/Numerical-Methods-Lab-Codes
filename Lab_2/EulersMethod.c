#include <stdio.h>

float f(float x, float y){
    // return x*x+y;               // y(0)=2, y=-x^2 -2x + 4e^x -2 
    return x+y;                 // y(0)=1, y=2e^x - x -1 
    // return x*x+2*x-y;          // y(1)=2, y=x^2+e^(1-x)
    // return x*cos(x);
}

int main(){
    float xo,yo,xn,h,m;

    printf("Enter the value of xo,yo: \n");
    scanf("%f %f",&xo,&yo);

    printf("Enter the value of xn: \n");
    scanf("%f",&xn);

    printf("Enter the value of step size: ");
    scanf("%f", &h);

    do{
        m = f(xo,yo);
        yo = yo + h*m;
        xo = xo + h;
        printf("x=%f, y=%f\n",xo,yo);
    }while(xo < xn);

    printf("The value is %.4f at x = %f",yo,xn);
}
