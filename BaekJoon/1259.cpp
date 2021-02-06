#include <iostream>
using namespace std;
int main(){
    int input;
    while(cin >> input && input){
        int count = 0, result = 0;
        int temp = input;
        while(temp){
            result = result*10 + temp%10;
            temp /= 10;
        }
        if(result == input)
            printf("yes\n");
        else
            printf("no\n");
    }
}