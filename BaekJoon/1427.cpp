#include <iostream>
#include <algorithm>
using namespace std;
int arr[11];
int main(){
    int input;
    int count = 0;
    cin >> input;
    while(input != 0){
        arr[count] = input%10;
        count++;
        input /= 10;
    }
    sort(arr, arr+count);
    for(int i = count-1; i >= 0; i--){
        printf("%d", arr[i]);
    }
}