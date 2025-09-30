#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    string text;
    int n;

    // CIN COUT

    cin >> text;
    cout << text;

    // GETLINE
    
    getline(cin, text);

    // VECTOR

    vector<int> v(n , 0);

    // SORT

    sort(v.begin(), v.end());

    // LOWER BOUND UPPER BOUND
    auto it = lower_bound(v.begin(), v.end(), n);
    auto it = upper_bound(v.begin(), v.end(), n);

    // SET (STORE UNIQUE ELEMENTS IN SORTED ORDER) -> USES TREES

    set<int> s;

    // UNORDERED_SET (STORE UNIQUE ELEMENTS IN AN UNORDERED ORDER) -> USES HASHING

    unordered_set<int> us;

    // MAP (STORE DATA AS SORTED PAIRS OR KEYS AND VALUES) -> USES TREES 

    map<int, string> m = {{1, "A"},
              {2, "B"}, {3, "C"}};

    // UNORDERED_MAP (STORE DATA AS PAIRS OF KEYS AND VALUES IN AN UNORDERED ORDER) -> USES HASHING

    unordered_map<int, string> um = {{1, "A"},
              {2, "B"}, {3, "C"}};

    // PRIORITY_QUEUE adds and removes elements according to priority. (ASCENT OR DESCENT) -> USES HEAP

    priority_queue<int> pq;
    priority_queue<int,vector<int>,greater<int>>pq;

    // MULTISET Multiset is an associative container similar to the set, but it can store multiple elements with same value.

    multiset<int> ms1;
    
    multiset<int> ms2 = {5, 3, 3, 1};

    // OUTPUT: 1 3 3 5 
    return 0;
}