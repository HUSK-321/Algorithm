#include <iostream>
using namespace std;
int prime[120];
int main(){
    for(int i = 2; i*i < 1000; i++){
        if(prime[i]){
            for(int j = i*i; j < 1000; j += i)
                prime[j] = false; 
        } 
    }
}
