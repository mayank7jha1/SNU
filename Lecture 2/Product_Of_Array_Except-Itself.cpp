#include <bits/stdc++.h>
using namespace std;
int *product;

void Solve(int* a, int n) {
    int prefix[n];
    prefix[0] = 1;
    for (int i = 1; i < n; i++) {
        prefix[i] = prefix[i - 1] * a[i - 1];
    }
    int suffix[n];
    suffix[n - 1] = 1;
    for (int i = n - 2; i >= 0; i--) {
        suffix[i] = suffix[i + 1] * a[i + 1];
    }

    for (int i = 0; i < n; i++)
    {
        product[i] = prefix[i] * suffix[i];
    }
}


int main() {
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    product = new int[n];
    Solve(a, n);

    for (int i = 0; i < n; i++)
    {
        cout << product[i] << " ";
    }
    cout << endl;
    return 0;
}