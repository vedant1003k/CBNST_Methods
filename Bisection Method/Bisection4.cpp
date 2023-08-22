#include <iostream>
#include <cmath>

using namespace std;

constexpr double e = 2.71828182846;

double f(double x) {
    return x*log10(x)-1.2;
}


double calc(double a, double b) {
    if (f(a) * f(b) > 0) {
        cout << "Root is out of bound" << endl;
        return 0.0;
    } else if (f(a) == 0) {
        return a;
    } else if (f(b) == 0) {
        return b;
    }
    
    double c = a;
    while ((b - a) >= 0.0001) {
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
    cout << x << endl;
    
    return 0;
}
