#include <iostream>
#include <algorithm>
using namespace std;

int n;
long long res = 3000000001;
int first, second, third;
long long arr[5001];

void search(){
    for(int i = 0; i < n; i++){
        int l = i + 1;
        int r = n - 1;
        while(l < r){
            long long sum = arr[i] + arr[l] + arr[r];

            if(res > llabs(sum)){
                res = llabs(sum);
                first = i;
                second = l;
                third = r;
            }

            if(sum > 0)
                r--;
            else
                l++;
        }
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    
    sort(arr, arr + n);

    search();

    cout << arr[first] << " " << arr[second] << " " << arr[third] << '\n';
}