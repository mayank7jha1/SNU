#include<bits/stdc++.h>
using namespace std;
const int N = 0;

/*
     Given an array of integers nums and an integer k,
     return the total number of subarrays whose sum equals to k.
*/

int Solve(int* arr, int n, int k) {

     int ans = 0, sum = 0;
     unordered_map<int, int> m;
     m[0]++;

     for (int i = 0; i < n; i++) {
          sum += arr[i];
          if (m[sum - k])
               ans += m[sum - k];

          m[sum]++;
     }
     return ans;
}

int main() {
     int n;
     cin >> n;
     int a[n];
     for (int i = 0; i < n; i++) {
          cin >> a[i];
     }
     int k;
     cin >> k;

     cout << Solve(a, n, k) << endl;
}
