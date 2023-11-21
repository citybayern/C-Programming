#include <iostream>
#include <cmath>

using namespace std;

float fxy(float x, float y) {
    return (x - 3) * (x - 3) + (y - 4) * (y - 4);
}

float dfxydx(float x, float y, float dx) {
    return (fxy(x + dx, y) - fxy(x, y)) / dx;
}

float dfxydy(float x, float y, float dy) {
    return (fxy(x, y + dy) - fxy(x, y)) / dy;
}

float EE(float x0, float x1, float y0, float y1) {
    return sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1));
}

int main() {
    float dx = 0.01;
    float dy = 0.01;
    float psi = 0.1;
    float x0 = 2;
    float x1 = 1;
    float y0 = 2;
    float y1 = 1;
    int iteration = 0;
    float acu = 0.01;

    while (EE(x0, x1, y0, y1) > acu && iteration < 100) {
        x0 = x1;
        y0 = y1;
        x1 -= psi * dfxydx(x0, y0, dx);
        y1 -= psi * dfxydy(x0, y0, dy);
        cout << x0 << " " << y0 << " " << fxy(x0, y0) << endl;
        iteration++;
    }

    return 0;
}
