#include <iostream>
#include <cstring>
#define MOD 1000000
using namespace std;

int n;
int arr[1001][1001][2][3];

// 결석 연속 3번 불가 지각 2번 불가 (지각은 연속 아님)
int school(int day, int attend, int delay, int absent){
    if(delay == 2 || absent == 3)
        return 0;

    if(day == n)
        return 1;

    if(arr[day][attend][delay][absent] != -1)
        return arr[day][attend][delay][absent];
    
    arr[day][attend][delay][absent] = school(day + 1, attend + 1, delay ,0) + school(day + 1, attend, delay, absent + 1)+ school(day + 1, attend, delay + 1, 0);

    arr[day][attend][delay][absent] %= MOD;

    return arr[day][attend][delay][absent];
}

int main(){
    cin >> n;

    memset(arr, -1, sizeof(arr));

    cout << school(0, 0, 0, 0) % MOD << '\n';
}