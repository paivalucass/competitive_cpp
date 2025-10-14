#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--) {
        int n;
        long long x;
        cin >> n >> x;

        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];

        // Binary search on h
        long long low = 1, high = 1e18, ans = 1;
        while (low <= high) {
            long long mid = (low + high) / 2;

            // compute total water if tank height = mid
            long long total = 0;
            for (long long ai : a) {
                if (ai < mid)
                    total += (mid - ai);
                if (total > x) break; // optimization
            }

            if (total <= x) {
                ans = mid;
                low = mid + 1;  // try to go higher
            } else {
                high = mid - 1; // too much water
            }
        }

        cout << ans << "\n";
    }
}
