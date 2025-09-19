#include<iostream>
#include<cmath>
using namespace std;

// Define the function to integrate
double f(double x) {
    return 1 / (1 + x * x);  // Example: ∫ 1/(1 + x^2) dx = arctangent(x)
}

int main() {
    double a, b;  // Lower and upper limits
    int n;        // Number of intervals (must be even)

    // Input values
    cout << "Enter lower limit a: ";
    cin >> a;
    cout << "Enter upper limit b: ";
    cin >> b;
    cout << "Enter number of intervals (even number): ";
    cin >> n;

    // Check if n is even
    if (n % 2 != 0) {
        cout << "Number of intervals must be even!" << endl;
        return 1;
    }

    double h = (b - a) / n;  // Step size
    double sum = f(a) + f(b);  // f(a) + f(b)

    // Apply Simpson's 1/3 Rule
    for (int i = 1; i < n; i++) {
        double x = a + i * h;
        if (i % 2 == 0) {
            sum += 2 * f(x);
        } else {
            sum += 4 * f(x);
        }
    }

    double result = (h / 3) * sum;

    // Output result
    cout << "Result using Simpson's 1/3rd Rule = " << result << endl;

    return 0;
}
