#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, l;
vector<pair<ll, ll>> x;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> l;
  x.resize(n);
  for(ll i = 0; i < n; i++) {
    cin >> x[i].first;
    x[i].second = i;
  }
  sort(x.begin(), x.end(), [](auto a, auto b) {
    return abs(a.first) < abs(b.first);
  });

  ll maxi = 0;
  ll k = 0;
  for(ll i = 0; i < n; i++) {
    if(x[i].first < 0 && maxi < -x[i].first) {
      maxi = -x[i].first;
      k = i;
    } else if(x[i].first > 0 && maxi < l - x[i].first) {
      maxi = l - x[i].first;
      k = i;
    }
  }
  
  if(x[k].first < 0) {
    deque<ll> q;
    for(ll i = k; i >= 0; i--) {
      if(x[i].first < 0) {
        q.push_front(x[i].second);
      } else if(q.size()) {
        q.push_front(x[i].second);
        q.pop_back();
      }
    }
    cout << q.back() + 1 << ' ' << maxi << '\n';
  } else {
    deque<ll> q;
    for(ll i = k; i < n; i++) {
      if(x[i].first > 0) {
        q.push_back(x[i].second);
      } else if(q.size()) {
        q.push_back(x[i].second);
        q.pop_front();
      }
    }
    cout << q.front() + 1 << ' ' << maxi << '\n';
  }
  return 0;
}