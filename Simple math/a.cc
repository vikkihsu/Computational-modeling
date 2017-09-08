#include <iostream>
#include "math.h"
using namespace std;

int main()
{
    double t, a, b;
    double dt;
    cout << "Length of t:";
    cin >> t;
    cout << "Enter a:";
    cin >> a;
    cout << "Enter b:";
    cin >> b;
    cout << "Increment of t:";
    cin >> dt;
    for (double i = 0; i < (t+dt); i += dt)
        cout << "i = " << i <<  "\ta * exp(-i/b) = " << a * exp(-i/b) << endl;
    return 0;
}

