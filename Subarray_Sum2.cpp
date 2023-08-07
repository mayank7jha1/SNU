#include<bits/stdc++.h>
using namespace std;
// const int N = 0;

/*
     Given an array of integers nums and ,
     check if there is a subarray whose sum is zero.
*/

bool Subarray_Sum_Zero_Check(int a[], int n) {
	int pre[n + 1] = {0};

	pre[0] = a[0];
	for (int i = 1; i < n; i++) {
		pre[i] = pre[i - 1] + a[i];
	}

	int freq[100005] = {0};
	for (int i = 0; i < n; i++) {
		freq[pre[i]]++;
	}

	for (int i = 0; i < 100005; i++) {
		if (i == 0 and freq[i] > 0) {
			return true;
		} else {
			if (freq[i] > 1) {
				return true;
			}
		}
	}
	return false;
}



int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cout << Subarray_Sum_Zero_Check(a, n) << endl;
}