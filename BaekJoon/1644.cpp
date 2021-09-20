#include <iostream>
#include <vector>
using namespace std;

int n;
bool notPrime[4000001];
vector<int> primeNumber;


void FindPrime(){
    for(int i = 2; i * i <= n; i++){
        if(!notPrime[i]){
            for(int j = i * i; j <= n; j += i)
                notPrime[j] = true;
        }
    }

    for(int i = 2; i <= n; i++){
        if(!notPrime[i])
            primeNumber.push_back(i);
    }
}


int main(){
    cin >> n;

    if(n == 1 || n == 0){
        cout << 0 << '\n';
        return 0;
    }

    FindPrime();

    int left = 0, right = 0, res = 0;
    int sum = primeNumber[0];

    while (left <= right && right < primeNumber.size()){
        if(sum < n){
            sum += primeNumber[++right];
        }
        else if(sum > n){
            if(left == right)
                sum += primeNumber[++right];
            else
                sum -= primeNumber[left++];
        } 
        else if(sum == n){
            res++;
            sum += primeNumber[++right];
        }
    }
    
    cout << res << '\n';
    return 0;
}