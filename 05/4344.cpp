#include <iostream>
using namespace std;
int main(){
    int C;
    cin >> C;
    while(C--){
        int sum = 0, count = 0;
        double avg;
        int N;
        cin >> N;
        int arr[N];
        for(int i = 0; i < N; i++){
            cin >> arr[i];
            sum += arr[i];
        }
        avg = sum / N;
        for(int j = 0; j < N; j++){
            if(arr[j] > avg)
                count++;
        }
        cout << fixed;
        cout.precision(3);
        cout << (float)count/N*100 << "%" << '\n';
    }
}