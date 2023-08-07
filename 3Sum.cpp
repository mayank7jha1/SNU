#include<bits/stdc++.h>
using namespace std;
#define ll long long
int cnt[10];

int main() {
	int t;
	cin >> t;
	while (t--) {
		ll n;
		cin >> n;
		for (int i = 0; i < 10; i++) {
			cnt[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			int x;
			cin >> x;
			x = x % 10;
			cnt[x]++;
		}

		//vector<int>v;
		int ans[100005] = {0};
		int k = 0;
		for (int i = 0; i <= 9; i++) {
			for (int j = 0; j < min(cnt[i], 3); j++) {
				//v.push_back(i);
				ans[k] = i;
				k++;
			}
		}

		int flag = 0;
		//int len = v.size();
		int len1 = k;
		for (int i = 0; i < len1; i++) {
			for (int j = i + 1; j < len1; j++) {
				for (int k = j + 1; k < len1; k++) {
					if ((ans[i] + ans[j] + ans[k]) % 10 == 3) {
						flag = 1;
						break;
					}
				}
			}
		}

		if (flag == 1) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}