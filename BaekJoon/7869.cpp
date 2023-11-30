#include <iostream>
#include <cmath>
using namespace std;

const double PI = 3.14159265358979f;

double GetDistance(double x1, double y1, double x2, double y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

int main()
{
    double x1, y1, r1;
    double x2, y2, r2;

    cin >> x1 >> y1 >> r1;
    cin >> x2 >> y2 >> r2;
    cout << fixed;
    cout.precision(3);

    double d = GetDistance(x1, y1, x2, y2);

    if(d >= r1 + r2)
    {
        cout << "0.000\n";
        return 0;
    }

    if(d + min(r1, r2) <= max(r1, r2))
    {
        double MinRadius = min(r1, r2);
        cout << MinRadius * MinRadius * PI << '\n';
        return 0;
    }

    double t1 = (acos((r1 * r1 - r2 * r2 + d * d) / (2 * r1 * d))) * 2;
    double t2 = (acos((r2 * r2 - r1 * r1 + d * d) / (2 * r2 * d))) * 2;

    double s1 = r1 * r1 * (t1 - sin(t1)) / 2;
    double s2 = r2 * r2 * (t2 - sin(t2)) / 2;

    cout << s1 + s2 << '\n';
}