#include <iostream>

using namespace std;

int numbers[10];

void MakeEndNumZero(int number, int nod){
    while (number > 0){
        numbers[number % 10] += nod;
        number /= 10;
    }
    
}

int main(){
    // input
    int bookPage;
    cin >> bookPage;

    // solve
    int curNOD = 1;
    int curStart = 1;

    while(curStart <= bookPage){
        while (bookPage % 10 != 9 && curStart <= bookPage){
            MakeEndNumZero(bookPage, curNOD);
            bookPage--;
        }
        
        if(bookPage < curStart) break;

        while (curStart % 10 != 0 && curStart <= bookPage){
            MakeEndNumZero(curStart, curNOD);
            curStart++;
        }
        
        curStart /= 10;
        bookPage /= 10;

        for(int i = 0; i < 10; i++){
            numbers[i] += (bookPage - curStart + 1) * curNOD;
        }

        curNOD *= 10;
    }

    // output
    for(int i = 0; i <= 9; i++)
        cout << numbers[i] << " ";
}