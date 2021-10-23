#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, input;

int main(){
    scanf("%d", &n);
    vector<int> num;

    for(int i = 0; i < n; i++){
        scanf("%d", &input);

        if(num.empty() || num.back() < input)
            num.push_back(input);
        else {
            auto temp = lower_bound(num.begin(), num.end(), input);
            *temp = input;
        }
    }
    
    printf("%d\n", num.size());
}