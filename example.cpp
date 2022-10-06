#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class A{
public:
    A(const int& a){
        cout << "normal constructor\n";
    }

    A(const int&& a){
        cout << "move constructor\n";
    }
};

int main(){
    A(1);
}