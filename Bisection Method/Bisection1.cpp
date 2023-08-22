#include <iostream>
#include <cmath>
using namespace std;

double f(double x) {
    return ((x * x * x) - (3 * x) - 7);
}

double calc(double a, double b) {
    if (f(a) * f(b) > 0) {
        cout << "Root is not within the given range." << endl;
        return 0.0;
    } else if (f(a) == 0) {
        return a;
    } else if (f(b) == 0) {
        return b;
    }
    
    double c = a;
    while ((b - a) >= 0.001) {
        c = (a + b) / 2.0;
        
        if (f(c) == 0.0) {
            break;
        } else if (f(c) * f(a) < 0) {
            b = c;
        } else {
            a = c;
        }
    }
    return c;
}

int main() {
    double a, b;
    cout << "Enter the initial range [a, b]: ";
    cin >> a >> b;
    
    double x = calc(a, b);
    cout << "Root: " << fixed << x << endl;
    
    return 0;
}
