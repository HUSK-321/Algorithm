#include <iostream>
using namespace std;

int main(){
    int start, end;
    int arr[1000001];
    arr[1] = -1;

    cin >> start >> end;

    for(int i = 2; i <= end; i++){
        for(int j = 2; i*j <= end; j++)
            arr[i*j] = -1;
    }

    for(int k = start; k <= end; k++){
        if(arr[k] != -1)
            cout << k <<'\n';
    }
} 