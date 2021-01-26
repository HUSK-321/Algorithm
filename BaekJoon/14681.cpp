#include <iostream>
using namespace std;
int main(){
    int x, y;
    cin >> x >> y;
    if(x > 0 && y>0){
        printf("1\n");
    }else if(x < 0 && y>0){
        printf("2\n");
    }else if(x < 0 && y<0){
        printf("3\n");
    } else{
        printf("4\n");
    }
    return 0;
}