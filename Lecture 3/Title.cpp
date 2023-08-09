// Created by Mayank

#include <bits/stdc++.h>
using namespace std;

bool map1[30] = {0};

void Title(char *a, int k) {
	int i = 0;
	int j = strlen(a) - 1;

	while (i < j) {
		if (a[i] == '?' and a[j] == '?') {
			i++; j--;
			continue;
		} else if (a[i] != '?' and a[j] == '?') {
			a[j] = a[i];
			map1[a[i] - 'a' + 1] = true; i++; j--;
		} else if (a[j] != '?' and a[i] == '?') {
			a[i] = a[j];
			map1[a[i] - 'a' + 1] = true; i++; j--;
		} else if (a[i] == a[j]) {
			map1[a[i] - 'a' + 1] = true;
			i++; j--;

		} else {
			cout << "IMPOSSIBLE" << endl;
			return;
		}
	}


//a?a?a
	//i==j
	if (i == j and a[i] != '?') {
		map1[a[i] - 'a' + 1] = true;
	}

	while (i >= 0) {
		while (k > 1 and map1[k] == 1) {
			k--;
		}
		if (a[i] == '?' and a[j] == '?') {
			a[i] = a[j] = 'a' + k - 1;
			map1[k] = true;
			j++;
			i--;
		} else {
			i--;
			j++;
		}
	}
	if (k == 1 and map1[k] == true) {
		cout << a << endl;
	} else {
		cout << "IMPOSSIBLE" << endl;
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int k;
	cin >> k;
	char a[2001];
	cin >> a;
	Title(a, k);
	return 0;
}