#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX_LENGTH = 10000001;
vector<int> numbers;

int main(){
    numbers.resize(MAX_LENGTH);

    for(int i = 0; i < MAX_LENGTH; i++){
        numbers[i] = i;
    }

    random_shuffle(numbers.begin(), numbers.end());

    for(int i = 100000; i < 100005; i++){
        cout << numbers[i] << " ";
    }
}