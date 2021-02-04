#include <iostream>
#include <string>
using namespace std;
int main(){
    int v, a = 0, b = 0;
    string input;
    cin >> v >> input;
    for(int i = 0; i < v; i++){
        if(input[i] == 'A')
            a++;
        else
            b++;
    }

    if(a > b){
        printf("A\n");
    } else if(a < b){
        printf("B\n");
    } else{
        printf("Tie\n");
    }
    
}