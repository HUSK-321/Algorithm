#include <iostream>
#include <string>
using namespace std;
int main(){
    int month[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
    string day[7] = { "SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT" };
    int M,D;
    int count, dayCount;
    cin >> M >> D;

    if(M<1 || M>12 || D<1 || D>31)
        return 0;

    count += D;
    for(int i = 1; i < M; i++){
        count += month[i-1];
    }
    dayCount = count % 7;
    cout << day[dayCount] << endl;

    return 0;
}