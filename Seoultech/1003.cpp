#include <iostream>
using namespace std;

int F1(int n) {
   if (n == 0 || n == 1)
      return n;
   int f0 = 0, f1 = 1, f2 = 1;
   while (f2 <= n) {
      f0 = f1;
      f1 = f2;
      f2 = f0 + f1;
   }
   return f1;
}

int F2(int n) {
   if (n == 0 || n == 1)
      return n;
   int f0 = 0, f1 = 1, f2 = 1;
   while (f2 < n) {
      f0 = f1;
      f1 = f2;
      f2 = f0 + f1;
   }
   return f1;
}

int PrintChick(int n) {
   int chickSum = 0;
   while (n > 0) {
      int f = F1(n);
      chickSum += F2(f);
      n = n - f;
   }
   return chickSum;
}
int main() {
   int n;
   cin >> n;
   cout << PrintChick(n);
}