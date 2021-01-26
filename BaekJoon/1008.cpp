#include <iostream>
using namespace std;

int main(){
    double a, b;
    
    while(1){    
        cin>>a>>b;        
        if(a > 0 && b < 10 && b != 0)
            break;
        else
            continue;
    }
    
    cout.precision(15);
    cout<<a/b;    
}