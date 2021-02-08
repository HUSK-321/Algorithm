#include <iostream>
#include <string.h>
#include <string>
using namespace std;
bool prime[2000000];
int n;

bool palin(int num){
    string s = to_string(num);
    for(int i = 0; i < s.size()/2; i++){
        if(s[i] != s[s.size() - i - 1])
            return false;
    }
    return true;
}
void era(){
    // 에라토스 가라시대
    memset(prime, true, sizeof(prime));
    prime[1] = false;
    for(int i = 2; i*i < 2000000; i++){
        for(int j = i*i; j < 2000000; j += i){
            prime[j] = false;
        }
    }
}
int main(){
    cin >> n;
    era();

    int result = n;
    for(int i = n;; i++){
        if(prime[i]){
            if(palin(i)){
                printf("%d\n", i);
                break;
            }
        }
    }
    
}