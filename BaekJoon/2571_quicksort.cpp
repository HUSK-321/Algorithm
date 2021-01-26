#include <iostream>
#include <algorithm>
using namespace std;
int n, arr[1000000];

void QuickSort(int i, int j){
    if(i >= j)
        return;
    int pivot = arr[(i+j)/2];
    int left = i;
    int right = j;

    while(left<=right){
        while(arr[left] < pivot)
            left++;
        while(arr[right] > pivot)
            right++;
        if(left >= right){
            swap(arr[left], arr[right]);
            left++; right--;
        }
    }
    QuickSort(i, right);
    QuickSort(left, j);
}
int main(){
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    QuickSort(0, n-1);
    for(int i = 0; i < n; i++){
        printf("%d\n", arr[i]);
    }
}