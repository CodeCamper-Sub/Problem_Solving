#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll w, h, n, A, B;
vector<pair<ll, ll>> s;
vector<ll> a, b;
vector<map<ll, ll>> m;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> w >> h;
  cin >> n;
  s.resize(n);
  for(ll i = 0; i < n; i++) {
    cin >> s[i].first >> s[i].second;
  }
  cin >> A;
  a.resize(A + 1);
  for(ll i = 0; i < A; i++) {
    cin >> a[i];
  }
  a[A] = w;
  cin >> B;
  b.resize(B + 1);
  for(ll i = 0; i < B; i++) {
    cin >> b[i];
  }
  b[B] = h;

  sort(s.begin(), s.end());
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());
  m.resize(a.size());
  ll now = 0;
  queue<ll> q;
  for(ll i = 0; i < s.size(); i++) {
    if(s[i].first > a[now]) {
      while(q.size()) {
        auto iter = upper_bound(b.begin(), b.end(), q.front());
        q.pop();
        m[now][iter - b.begin()]++;
      }
      while(s[i].first > a[now]) now++;
    }
    q.push(s[i].second);
  }
  while(q.size()) {
    auto iter = upper_bound(b.begin(), b.end(), q.front());
    q.pop();
    m[now][iter - b.begin()]++;
  }
  now++;

  ll mini = n;
  ll maxi = 0;
  for(ll i = 0; i < a.size(); i++) {
    if(m[i].size() < b.size()) {
      mini = 0;
    }
    for(auto [_, v]: m[i]) {
      mini = min(mini, v);
      maxi = max(maxi, v);
    }
  }

  cout << mini << ' ' << maxi << '\n';
  
  return 0;
}