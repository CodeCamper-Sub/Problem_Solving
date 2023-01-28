#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n;
string s[500500];
vector<pair<string, ll>> v;
ll answer[500500];

void divide_conquer(ll index, ll start, ll end) {
    if(start == end) {
        answer[v[start].second] = index - 1;
        return;
    }
    ll next_start = start;
    for(ll i = start; i <= end; i++) {
        if(v[i].first.size() <= index) {
            divide_conquer(index + 1, i, i);
            next_start = i + 1;
        } else if (i == end) {
            divide_conquer(index + 1, next_start, i);
        } else if (v[i].first[index] != v[i+1].first[index]) {
            divide_conquer(index + 1, next_start, i);
            next_start = i + 1;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;

    for(ll i = 0; i < n; i++) {
        cin >> s[i];
        v.push_back({s[i], i});
    }

    sort(v.begin(), v.end());
    divide_conquer(0, 0, v.size() - 1);
    for(ll i = 0; i < n; i++) {
        cout << answer[i] << '\n';
    }
    return 0;
}