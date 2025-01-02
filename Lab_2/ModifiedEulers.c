#include <stdio.h>
#include <math.h> // For fabs()

float f(float x, float y) {
    return x + y; // Define the differential equation dy/dx = x + y
}

int main() {
    float xo, yo, xn, h, m, mavg, yold, mold, temp;

    printf("Enter the value of xo and yo: \n");
    scanf("%f %f", &xo, &yo);

    printf("Enter the value of xn: \n");
    scanf("%f", &xn);

    printf("Enter the value of step size: ");
    scanf("%f", &h);

    while (xo <= xn + h / 2) { // Ensure the loop runs up to xn
        yold = yo;               // Store old y value
        m = f(xo, yo);           // Calculate slope at current point
        mold = m;                // Store initial slope
        yo = yo + m * h;         // First Euler approximation for y

        do {
            m = f(xo + h, yo);   // Recalculate slope at next point
            mavg = (m + mold) / 2; // Average slope for refinement
            temp = yo;           // Temporarily store current y
            yo = yold + mavg * h; // Refined y value
        } while (fabs(yo - temp) >= 0.0001); // Continue until convergence

        xo = xo + h; // Update x after convergence
    }

    printf("The value of y is %.4f at x = %.4f\n", yo, xn);
    return 0;
}
