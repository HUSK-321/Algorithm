#include <iostream>
using namespace std;

int testcase[3] = {2, 7, 61};
int n;


long long PowerNumber(long long x, long long y, long long p){
    // PowerNumber(target, d, number)
    // result = x^y mod p
    long long result = 1;

    x = x % p;

    while (y > 0){
        // if odd number
        if(y & 1)
            result = (result * x) % p;
        
        y  = y >> 1;
        x = (x * x) % p;
    }

    return result;
}

bool Miller(long long number, long long target){
    // number is odd number (= maybe prime)
    // number - 1 = d * 2^exponent (d is odd number)
    long long exponent = 0;
    long long d = number - 1;

    // find smallest exponent
    while (d % 2 == 0){
        exponent++;
        d = d >> 1;
    }

    long long x = PowerNumber(target, d, number);

    if(x == 1 || x == number - 1)
        return true;
    
    for(int i = 0; i < exponent-1; i++){
        x = PowerNumber(x, 2, n);

        if(x == n-1)
            return true;
    }
    return false;  
}


bool IsPrime(long long number){
    // just prime
    if(number < 2)
        return false;

    if(number == 2 || number == 3)
        return true;
    
    // even number is not prime
    if(number % 2 == 0)
        return false;

    // miller-rabin primary test
    for(int i = 0; i < 3; i++){
        // testcase number is prime
        if(number == testcase[i])
            return true;
        
        // not allowed in miller-rabin, it's not prime number
        if(!Miller(number, testcase[i]))
            return false;
    }
    return true;
}

int main(){
    cin >> n;

    if(IsPrime(n))
        cout << "1\n";
    else
        cout << "0\n"; 
}