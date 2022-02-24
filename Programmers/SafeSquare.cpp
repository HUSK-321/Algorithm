using namespace std;

long long gcd(long long x, long long y){
    long long temp;
    while(y){
        temp = x%y;
        x = y;
        y = temp;
    }
    return x;
}

long long solution(int w,int h) {
    long long answer = 0;
    long long totalSquare = static_cast<long long>(w) * static_cast<long long>(h);

    long long commonDigit = gcd(w, h);

    long long wrongSquare = w + h - commonDigit;

    return answer = totalSquare - wrongSquare;
}