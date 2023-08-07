#include<bits/stdc++.h>
using namespace std;
// const int N = 0;

int main() {
	int n;
	cin >> n;
	int a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int maximum = INT_MIN;
	int minimum = INT_MAX;

	for (int i = 0; i < n; i++) {
		//Iterate over the initial array
		maximum = max(maximum, a[i]);
		minimum = min(minimum, a[i]);
	}

	int freq[maximum - minimum + 1] = {0};

	//Iterate over the initial array a;
	for (int i = 0; i < n; i++) {
		//Update the frequency of ind. element
		freq[a[i] - minimum] = freq[a[i] - minimum] + 1;
		//Shifting ka kaam kar rahe ho
	}


	for (int i = 0; i < maximum - minimum + 1; i++) {
		if (freq[i] > 0) {
			cout << i + minimum << "-->" << freq[i] << endl;
		}
	}
}

