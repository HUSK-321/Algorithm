#include <iostream>
using namespace std;
int k;
int arr[13];
int lotto[13];
void Lotto(int start, int count){
    if(count == 6){
        for(int i = 0; i < 6; i++)
            cout << lotto[i] << " ";
        printf("\n");
        return;
    }
    for(int i = start; i < k; i++){
        lotto[count] = arr[i];
        Lotto(i+1, count+1);
    }
}

int main(){
    while (cin >> k && k){
        for(int i = 0; i < k; i++){
            cin >> arr[i];
        }
        Lotto(0, 0);
        printf("\n");
    }
    return 0;
}