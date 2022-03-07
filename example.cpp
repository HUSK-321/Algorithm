#include <vector>

std::pair<int, int> p;

int main(){
    p = {1, 2};

    // if(p ==std::pair{1, 2}){
    //     // C++ 17
    // }
    if(p == std::make_pair(1, 2)){
        // C++ 14
    }
}