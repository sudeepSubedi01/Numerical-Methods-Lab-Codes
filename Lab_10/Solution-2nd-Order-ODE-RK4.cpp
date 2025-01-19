#include <iostream>
#include <cmath>
using namespace std;

float f(float x, float y, float z) {
    return z;
}

float g(float x, float y, float z) {
    return sin(x) - x * z - y * y;
}

int main() {
    // Initial conditions
    float x0 = 0, y0 = 1, z0 = 1;
    float xx = 0.5;  // Final value of x
    float h = 0.25;  // Step size

    // Variables for RK4 method
    float x = x0, y = y0, z = z0;
    float k1, k2, k3, k4, k;
    float l1, l2, l3, l4, l;

    int i = 0;

    // RK4 loop
    while (x < xx + h / 2) {  // Adjust for floating-point precision
        cout << "Step " << i << ":\n";
        cout << "x = " << x << "\n";
        cout << "y = " << y << "\n";
        cout << "z = " << z << "\n\n";

        // Compute RK4 increments for y and z
        k1 = h * f(x, y, z);
        l1 = h * g(x, y, z);

        k2 = h * f(x + h / 2, y + k1 / 2, z + l1 / 2);
        l2 = h * g(x + h / 2, y + k1 / 2, z + l1 / 2);

        k3 = h * f(x + h / 2, y + k2 / 2, z + l2 / 2);
        l3 = h * g(x + h / 2, y + k2 / 2, z + l2 / 2);

        k4 = h * f(x + h, y + k3, z + l3);
        l4 = h * g(x + h, y + k3, z + l3);

        // Update y and z
        k = (k1 + 2 * k2 + 2 * k3 + k4) / 6;
        l = (l1 + 2 * l2 + 2 * l3 + l4) / 6;

        y = y + k;
        z = z + l;

        // Update x
        x = x + h;
        i++;
    }

    // Final output
    cout << "Final Results:\n";
    cout << "x = " << x << "\n";
    cout << "y = " << y << "\n";
    cout << "z = " << z << "\n";

    return 0;
}
