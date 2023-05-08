#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n;
vector<ll> a;
vector<pair<ll, ll>> even_one, even_minus, odd_one, odd_minus, all;

void init() {
  cin >> n;
  a.resize(n);
  for(ll& a: a) {
    cin >> a;
  }
  even_one.clear();
  even_minus.clear();
  odd_one.clear();
  odd_minus.clear();
  all.clear();
}

void solve() {
  if(n % 2) {
    cout << -1 << '\n';
    return;
  }
  ll previous = 0;
  for(ll i = 1; i <= n; i++) {
    if(i == n || a[i] != a[i - 1]) {
      if(a[i - 1] == 1) {
        if((i - previous) % 2) {
          odd_one.push_back({previous, i - 1});
        } else {
          even_one.push_back({previous, i - 1});
        }
      } else {
        if((i - previous) % 2) {
          odd_minus.push_back({previous, i - 1});
        } else {
          even_minus.push_back({previous, i - 1});
        }
      }
      previous = i;
    }
  }
  if(odd_one.size() == odd_minus.size()) {
    
  } else if(odd_one.size() < odd_minus.size()) {
    // even_one을 쪼개서 odd_one.size를 늘리기
    while(odd_one.size() < odd_minus.size()) {
      auto [start, end] = even_one.back();
      even_one.pop_back();
      odd_one.push_back({end - 1, end - 1});
      odd_one.push_back({end, end});
      if(start + 1 < end) {
        even_one.push_back({start, end - 2});
      }
    }
  } else if(odd_one.size() > odd_minus.size()) {
    // even_minus를 쪼개서 odd_minus를 늘리기
    while(odd_one.size() > odd_minus.size()) {
      auto [start, end] = even_minus.back();
      even_minus.pop_back();
      odd_minus.push_back({end - 1, end - 1});
      odd_minus.push_back({end, end});
      if(start + 1 < end) {
        even_minus.push_back({start, end - 2});
      }
    }
  }
  for(ll i = 0; i < even_one.size(); i++) {
    all.push_back(even_one[i]);
  }
  for(ll i = 0; i < even_minus.size(); i++) {
    all.push_back(even_minus[i]);
  }
  for(ll i = 0; i < odd_one.size(); i++) {
    all.push_back(odd_one[i]);
  }
  for(ll i = 0; i < odd_minus.size(); i++) { 
    all.push_back(odd_minus[i]);
  }
  sort(all.begin(), all.end());
  cout << all.size() << '\n';
  for(auto [start, end]: all) {
    cout << start + 1 << ' ' << end + 1 << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll tt;
  cin >> tt;
  for(ll T = 1; T <= tt; T++) {
    init();
    solve();
  }
  return 0;
}