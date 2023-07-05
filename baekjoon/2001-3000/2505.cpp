#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

ll n, a, b, c, d;
vector<ll> v;
vector<pair<ll, ll>> segments;

bool check(vector<pair<ll, ll>>& segments) {
  if(segments[0].first != 1 || segments.back().second != n) return false;
  for(ll i = 0; i < segments.size() - 1; i++) {
    if(segments[i].second + 1 != segments[i + 1].first) return false;
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  v.resize(n);
  for(ll& v: v) cin >> v;
  deque<ll> q;
  for(ll i = 0; i < n; i++) {
    if(q.empty()) {
      q.push_back(v[i]);
    } else if(abs(q.back() - v[i]) > 1) {
      segments.push_back({q.front(), q.back()});
      while(q.size()) q.pop_front();
      q.push_back(v[i]);
    } else {
      if(q.size() >= 2) {
        if((q.front() < q.back() && q.back() < v[i]) || (q.front() > q.back() && q.back() > v[i])) {
          q.push_back(v[i]);
        } else {
          segments.push_back({q.front(), q.back()});
          while(q.size()) q.pop_front();
          q.push_back(v[i]);
        }
      } else {
        q.push_back(v[i]);
      }
    }
  }

  segments.push_back({q.front(), q.back()});

  if(check(segments)) {
    cout << "1 1\n 1 1\n";
    return 0;
  }

  for(ll i = 0; i < segments.size(); i++) {
    for(ll j = i; j < segments.size(); j++) {
      a = 1;
      for(ll k = 0; k < i; k++) a += abs(segments[k].second - segments[k].first) + 1;
      b = 0;
      for(ll k = 0; k <= j; k++) b += abs(segments[k].second - segments[k].first) + 1;

      vector<pair<ll, ll>> target = segments;
      for(ll k = i; k <= j; k++) swap(target[k].first, target[k].second);
      reverse(target.begin() + i, target.begin() + j + 1);

      if(check(target)) {
        c = 1; d = 1;
        cout << a << ' ' << b << '\n';
        cout << c << ' ' << d << '\n';
        return 0;
      } else {
        for(ll u = 0; u < target.size(); u++) {
          for(ll v = u; v < target.size(); v++) {
            vector<pair<ll, ll>> next_target = target;
            c = 1;
            for(ll k = 0; k < u; k++) c += abs(target[k].second - target[k].first) + 1;
            d = 0;
            for(ll k = 0; k <= v; k++) d += abs(target[k].second - target[k].first) + 1;

            for(ll k = u; k <= v; k++) swap(next_target[k].first, next_target[k].second);
            reverse(next_target.begin() + u, next_target.begin() + v + 1);

            if(check(next_target)) {
              cout << a << ' ' << b << '\n';
              cout << c << ' ' << d << '\n';
              return 0;
            }
          }
        }
      }
    }
  }

  for(ll i = 0; i < segments.size() - 1; i++) {
    if(abs(segments[i].second - segments[i].first) != 1 && abs(segments[i + 1].second - segments[i + 1].first) != 1) continue;
    vector<pair<ll, ll>> target = segments;
    swap(target[i], target[i + 1]);
    if(!check(target)) continue;
    if(abs(segments[i].second - segments[i].first) == 1) {
      a = 2;
      for(ll k = 0; k < i; k++) a += abs(segments[k].second - segments[k].first) + 1;
      b = 0;
      for(ll k = 0; k <= i + 1; k++) b += abs(segments[k].second - segments[k].first) + 1;
      c = a - 1; d = b - 1;
      cout << a << ' ' << b << '\n';
      cout << c << ' ' << d << '\n';
    } else {
      a = 1;
      for(ll k = 0; k < i; k++) a += abs(segments[k].second - segments[k].first) + 1;
      b = -1;
      for(ll k = 0; k <= i + 1; k++) b += abs(segments[k].second - segments[k].first) + 1;
      c = a + 1; d = b + 1;
      cout << a << ' ' << b << '\n';
      cout << c << ' ' << d << '\n';
    }
    return 0;
  }
  
  return 0;
}