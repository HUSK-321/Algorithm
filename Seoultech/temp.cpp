#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

vector<pair<int, int>> dots;

int Partition(vector<pair<int, int>> &arr, int _left, int _right) {
   int pivotIndex = _left;
   int storeIndex = pivotIndex;

   for (int i = _left + 1; i <= _right; i++) {
      if (arr[pivotIndex] > arr[i]) {
         storeIndex++;
         swap(arr[i], arr[storeIndex]);
      }
   }
   swap(arr[pivotIndex], arr[storeIndex]);
   pivotIndex = storeIndex;

   return pivotIndex;
}

void QuickSort(vector<pair<int, int>> &arr, int _left, int _right) {
   if (_left < _right) {
      int pivot = Partition(arr, _left, _right);
      QuickSort(arr, _left, pivot - 1);
      QuickSort(arr, pivot + 1, _right);
   }
}

long long Distance(int _low, int _high) {
   int lowX = dots[_low].first, lowY = dots[_low].second;
   int highX = dots[_high].first, highY = dots[_high].second;

   int disX = highX - lowX, disY = highY - lowY;

   return (long long)disX * disX + (long long)disY * disY;
}

long long BinarySearch(int _low, int _high) {
   if (_low == _high)
      return 2000000000;
   if (_low + 1 >= _high)
      return Distance(_low, _high);

   long long disMin = Distance(_low, _high);
   long long tempDis = 0, mid = (_low + _high) / 2;

   if ((tempDis = BinarySearch(_low, mid)) < disMin) {
      disMin = tempDis;
   }
   if ((tempDis = BinarySearch(mid + 1, _high)) < disMin) {
      disMin = tempDis;
   }

   vector<pair<int, int>> inner;
   
   int lineX = dots[mid].first;
   for (int i = mid; i >= _low; i--) {
      int x = dots[i].first, dist = lineX - x;
      if (disMin <= (long long)dist * dist) break;
      inner.push_back({ dots[i].second, dots[i].first });
   }
   for (int i = mid + 1; i <= _high; i++) {
      int x = dots[i].first, dist = lineX - x;
      if (disMin <= (long long)dist * dist) break;
      inner.push_back({ dots[i].second, dots[i].first });
   }

   int len = inner.size();
   if (len == 0) return disMin;
   QuickSort(inner, 0, inner.size()-1);

   for (int i = 0; i < len; i++) {
      int iX = inner[i].second, iY = inner[i].first;
      for (int j = i + 1; j < len; j++) {
         int jX = inner[j].second, jY = inner[j].first;
         int distX = jX - iX, distY = jY - iY;
         if (disMin <= (long long)distY * distY) 
            break;
         if (disMin <= (long long)distX * distX) 
            continue;

         long long dist = (long long)distX * distX + (long long)distY * distY;
         if (dist < disMin)
            disMin = dist;
      }
   }

   return disMin;
}

int main() {
   int N;
   char temp;
   cin >> N;
   dots = vector<pair<int, int>>(N);

   for (int i = 0; i < N; i++) {
      cin >> dots[i].first >> temp >> dots[i].second;
   }

   QuickSort(dots, 0, N - 1);

   cout << fixed;
   cout.precision(6);

   cout << sqrt(BinarySearch( 0, N - 1));
}