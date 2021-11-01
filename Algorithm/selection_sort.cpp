#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    // Input
    int n;
    cin >> n;
    vector<int> array(n);

    for(int i = 0; i < n; i++)
        cin >> array[i];
    

    // Sort

    for(int i = 0; i < n; i++){
        int smallest = i;

        for(int j = i+1; j < n; j++){
            if(array[j] < array[smallest]){
                smallest = j;
            }
        }

        swap(array[smallest], array[i]);
    }

    // Print

    for(int i = 0; i < n; i++){
        cout << array[i] << " ";
    }
}