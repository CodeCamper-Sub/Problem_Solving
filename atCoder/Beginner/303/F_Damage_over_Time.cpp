#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef __int128_t ll;
using namespace std;

ll n, h;
vector<pair<ll, ll>> s;

struct Compare {
  bool operator()(pair<ll, ll> left, pair<ll, ll> right) {
    return left.first * left.second < right.first * right.second;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  long long nn, hh;
  cin >> nn >> hh;
  n = nn;
  h = hh;
  s.resize(n);
  for(ll i = 0; i < n; i++) {
    long long t, d;
    cin >> t >> d;
    s[i] = {t, d};
  }
  sort(s.begin(), s.end(), [](auto a, auto b) {
    if(a.first * a.second != b.first * b.second) return a.first * a.second > b.first * b.second;
    else return a.first < b.first;
  });
  ll left = 0;
  ll right = ll(1e18);
  while(left <= right) {
    ll mid = (left + right) / 2;
    ll nh = h;
    ll now = 0;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, Compare> q;
    for(ll i = 0; i < s.size(); i++) {
      q.push(s[i]);
    }
    while(q.size() && now < mid && nh > 0) {
      auto [t, d] = q.top();
      q.pop();
      if(t <= mid - now) {
        nh -= (mid - t - now + 1) * (t * d);
        now = mid - t + 1;
      } else {
        q.push({mid - now, d});
      }
    }

    if(nh <= 0) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  long long answer = left;
  cout << answer << '\n';
  
  return 0;
}