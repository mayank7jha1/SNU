// Created by Mayank

#include <bits/stdc++.h>
using namespace std;

#define ll long long

#define val 1000001000000

ll Hamburgers(char *in, int nb, int ns, int nc, int pb, int ps, int pc, ll r) {
	ll s = 0;
	ll e = val;

	ll ans = -1;

	int cb = 0, cs = 0, cc = 0;

	for (int i = 0; in[i] != '\0'; i++) {
		if (in[i] == 'B') cb++;
		else if (in[i] == 'S') cs++;
		else cc++;
	}

	while (s <= e) {

		ll mid = (s + e) / 2;

		ll bread = (cb * mid - nb) * pb < 0 ? 0 : (cb * mid - nb) * pb;
		ll sausage = (cs * mid - ns) * ps < 0 ? 0 : (cs * mid - ns) * ps;
		ll cheese = (cc * mid - nc) * pc < 0 ? 0 : (cc * mid - nc) * pc;

		ll price = bread + sausage + cheese;
		if (price == r) {
			return mid;
		} else if (price < r) {
			s = mid + 1;
			ans = mid;
		} else {
			e = mid - 1;
		}
	}
	return ans;

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	char in[10000];
	int nb, ns, nc, pb, ps, pc;
	ll r;
	cin >> in;
	cin >> nb >> ns >> nc;
	cin >> pb >> ps >> pc;
	cin >> r;


	cout << Hamburgers(in, nb, ns, nc, pb, ps, pc, r) << endl;

	return 0;
}