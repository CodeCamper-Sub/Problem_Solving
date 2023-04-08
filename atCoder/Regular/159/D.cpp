#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

struct SegTree {
  vector<ll> tree, lazy;
  ll root, start, end;
};

ll n, l, r;
set<ll> used_k;
unordered_map<ll, ll> comp;
vector<pair<ll, ll>> intervals;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  intervals.resize(n);
  for(ll i = 0; i < n; i++) {
    cin >> intervals[i].first >> intervals[i].second;
    used_k.insert(intervals[i].first);
    used_k.insert(intervals[i].second);
  }

  ll id = 0;
  for(ll k: used_k) {
    comp[k] = ++id;
  }

  

  
  return 0;
}