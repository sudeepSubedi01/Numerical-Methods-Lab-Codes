#include<iostream>
#include<cmath>
using namespace std;

// Define the function to integrate
double f(double x) {
    return 1 / (1 + x * x);  // Example: ∫ 1/(1 + x^2) dx = arctangent(x)
}

int main() {
    double a, b;  // Lower and upper limits
    int n;        // Number of intervals (must be multiple of 3)

    // Input values
    cout << "Enter lower limit a: ";
    cin >> a;
    cout << "Enter upper limit b: ";
    cin >> b;
    cout << "Enter number of intervals (multiple of 3): ";
    cin >> n;

    // Check if n is a multiple of 3
    if (n % 3 != 0) {
        cout << "Number of intervals must be a multiple of 3!" << endl;
        return 1;
    }

    double h = (b - a) / n;  // Step size
    double sum = f(a) + f(b);  // f(a) + f(b)

    // Apply Simpson's 3/8 Rule
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 3 == 0) {
            sum += 2 * f(x);
        } else {
            sum += 3 * f(x);
        }
    }

    double result = (3 * h / 8) * sum;

    // Output result
    cout << "Result using Simpson's 3/8 Rule = " << result << endl;

    return 0;
}
