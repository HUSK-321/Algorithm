#include <iostream>
using namespace std;
int arr[21];
int n, s, count = 0;
void Search(int index, int sum){
    // finish
    if(index == n)
        return;
    // count
    if(sum + arr[index] == s)
        count++;
    // Recursive
    Search(index + 1, sum);     // 1개인 경우
    Search(index + 1, sum + arr[index]);
}
int main(){
    // input
    scanf("%d %d", &n, &s);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    // function
    Search(0, 0);
    // output
    printf("%d\n", count);
}