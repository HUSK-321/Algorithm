#include <iostream>
#include <math.h>
using namespace std;

int t;
pair<double, double> spot[100001];

double CCW(double x1, double y1, double x2, double y2){
    double rVal = (spot[0].first * y1) + (x1 * y2) + (x2 * spot[0].second);
    rVal += (-spot[0].second * x1) - (y1 * x2) - (y2 * spot[0].first);
    rVal /= 2;
    return rVal;
}

int main(){
    double res = 0;
    scanf("%d", &t);

    for(int i = 0; i < t; i++)
        scanf("%lf %lf", &spot[i].first, &spot[i].second);

    for(int i = 1; i < t; i++)
        res += CCW(spot[i-1].first, spot[i-1].second, spot[i].first, spot[i].second);
    
    printf("%.1lf\n", abs(res));
    return 0;
}