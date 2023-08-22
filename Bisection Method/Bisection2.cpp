#include <iostream>

using namespace std;

double f(double x) {
    return ((x * x) + (8 * x) - 3);
}

double calc(double a, double b) {
    if ((f(a) > 0 && f(b) > 0) || (f(a) < 0 && f(b) < 0)) {
        cout << "Root is out of bound" << endl;
        return 0.0;
    }
    if (f(a) == 0) {
        cout << "a is root " << a << endl;
        return 0.0;
    } else if (f(b) == 0) {
        cout << "b is root " << b << endl;
        return 0.0;
    }
    double c = a;
    while ((b - a) >= 0.01) {
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
