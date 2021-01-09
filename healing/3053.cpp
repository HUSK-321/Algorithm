#include <iostream>
#include <cmath>
using namespace std;
int main(){
    double R;
    cin >> R;

    // 소수점 여섯째자리까지 출력 
	cout << fixed;
	cout.precision(6);
    
    cout << R * R * M_PI << '\n';
    cout << R * R * 2 << '\n';
}