#include <iostream>
using namespace std;

int main() {
    double velocity = 0;   // m/s
    double altitude = 0;   // meters
    double thrust = 20;    // m/s²
    double gravity = 9.8;  // m/s²

    for (int t = 0; t < 10; t++) {
        velocity += (thrust - gravity); // net acceleration
        altitude += velocity;
        cout << "Time: " << t << "s, Altitude: " << altitude << " m\n";
    }
}
