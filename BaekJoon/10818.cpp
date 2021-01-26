#include <iostream>
using namespace std;
int main(){
    int n, max, min;
    max = -1000000;      min = 1000000;
    cin >> n;
    if(n>1000000 || n<1)
        return 0;
    int num[n];

    for (int i = 0; i < n; i++){
        cin >> num[i];
        if(num[i] > 1000000 || num[i] < -1000000)
            return 0;
        if (num[i] > max)
            max = num[i];
        if (num[i] < min)
            min = num[i];
    }

    cout << min << " " << max;
}