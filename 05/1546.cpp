#include <iostream>
using namespace std;
int main(){
    int T;
    double arr[1001];
    double sum = 0;
    double max = 0;
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> arr[i];
        if(arr[i] > max)
            max = arr[i];
    }

    for(int i = 0; i < T; i++){
        arr[i] = arr[i]/max*100;
        sum += arr[i];
    }

    cout << fixed;
    cout.precision(2);
    cout << sum/T << '\n';
}