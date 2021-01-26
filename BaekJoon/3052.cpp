#include <iostream>
using namespace std;
int main(){
    bool arr[44];
    fill_n(arr, 44, false);
    int input, count = 0;
    for(int i = 0; i < 10; i++){
        scanf("%d", &input);
        int left = input%42;
        if(arr[left] == false){
            arr[left] = true;
            count++;
        }
    }
    printf("%d\n", count);
}