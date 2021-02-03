#include <iostream>
using namespace std;
int main(){
    bool num[2001] = {false};
    int n, input;
    cin >> n;

    while(n--){
        cin >> input;
        num[input + 1000] = true;
    }

    for(int i = 0; i <= 2000; i++){
        if(num[i] == true)
            cout << i - 1000 << " ";
    }
    cout << "\n";
}