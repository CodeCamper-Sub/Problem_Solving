#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

ll n;
vector<pair<ll, ll>> x;
set<pair<ll, ll>> used;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  for(ll i = 0; i < n; i++) {
    ll b, l, r;
    cin >> b >> l >> r;
    if(used.find({l, r}) == used.end()) {
      x.push_back({l, r});
      used.insert({l, r});
    }
  }

  sort(x.begin(), x.end(), [](auto& a, auto& b) {
    return a.second != b.second ? a.second > b.second : a.first < b.first;
  });

  vector<ll> lis;
  for(ll i = 0; i < x.size(); i++) {
    if(lis.empty() || lis.back() <= x[i].first) {
      lis.push_back(x[i].first);
    } else {
      auto iter = upper_bound(lis.begin(), lis.end(), x[i].first);
      *iter = x[i].first;
    }
  }

  cout << lis.size() << '\n';
  
  return 0;
}