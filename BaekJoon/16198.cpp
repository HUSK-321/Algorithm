#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[11];
bool check[11];

int search(){
    int output = 0;

    for(int i = 1; i < n-1; i++){ // 처음과 끝값은 제외한다
        if(check[i])
            continue;
        check[i] = true;
        
        int left = i-1, right = i+1;
        while(check[left])
            left--;
        while(check[right])
            right++;
        
        output = max(output, search() + (arr[left]*arr[right]));
        check[i] = false;
    }
    return output;

    printf("%d", output);
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    
    printf("%d\n", search());
}