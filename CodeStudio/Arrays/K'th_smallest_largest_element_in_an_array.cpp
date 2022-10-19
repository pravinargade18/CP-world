#include <bits/stdc++.h>

using namespace std;

void kthSmallestLargest(int arr[], int n, int k) {
    //Write your code here
    set <int> s(arr, arr + n);
    vector <int> v(s.begin(), s.end());
    if (v.size() < k) cout << -1 << ' ' << -1 << '\n';
    else {
        cout << v[v.size() - k] << ' ' << v[k - 1] << '\n';
    }
}

int main() {
    int t;
    cin >> t;

    while (t > 0) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        kthSmallestLargest(arr, n, k);
        t--;
    }
    return 0;
}
