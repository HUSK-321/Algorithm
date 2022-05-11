#include <iostream>
#include <algorithm>
using namespace std;

const int MAXDAYS = 30;

long long medicien[31][31]; // w, h
int days;

int main(){
    // init
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // make array
    for(int i = 0; i <= MAXDAYS; i++)
        medicien[0][i] = 1;
    
    for(int w = 1; w <= MAXDAYS; w++){
        for(int h = 0; h <= MAXDAYS; h++){
            if(h == 0){  
                medicien[w][h] = medicien[w-1][1];
                continue;
            }
            medicien[w][h] = medicien[w-1][h+1] + medicien[w][h-1];
        }
    }

    // input
    while (true){
        cin >> days;

        if(days == 0)   break;

        cout << medicien[days-1][1] << '\n';
    }
    
}