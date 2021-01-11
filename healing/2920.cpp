#include <iostream>
using namespace std;
int main(){
    int input[8];
    int up = 0, down = 0;
    for(int i = 0; i < 8; i++)
        cin >> input[i];
    
    for(int i = 0; i < 4; i++){
        if(input[i] == i+1 && input[i] + input[7-i] == 9)// 차순이 맞나
            up++;
        else if(input[i] == 8 - i && input[i] + input[7-i] == 9)
            down++;
    }
    if(up == 4)
        cout << "ascending" << '\n';
    else if(down == 4)
        cout << "descending" << '\n';
    else
        cout << "mixed" << '\n';
}