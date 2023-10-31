#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n;
vector<pair<ll, ll>> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  v.resize(n);
  for(auto& [x, y]: v) {
    cin >> x >> y;
    x *= 10;
    y *= 10;
  }

  sort(v.begin(), v.end());
  deque<pair<ll, ll>> MinQ, MaxQ;
  MinQ.push_back({v[0].second, 0});
  MaxQ.push_back({v[0].second, 0});
  for(ll i = 1; i < n; i++) {
    if(MinQ.front().first >= v[i].second) {
      while(MinQ.size() && MinQ.front().first >= v[i].second) MinQ.pop_front();
      MinQ.push_front({v[i].second, i});
    } else {
      while(MinQ.size() && MinQ.back().first >= v[i].second) MinQ.pop_back();
      MinQ.push_back({v[i].second, i});
    }

    if(MaxQ.front().first <= v[i].second) {
      while(MaxQ.size() && MaxQ.front().first <= v[i].second) MaxQ.pop_front();
      MaxQ.push_front({v[i].second, i});
    } else {
      while(MaxQ.size() && MaxQ.back().first <= v[i].second) MaxQ.pop_back();
      MaxQ.push_back({v[i].second, i});
    }
  }

  ll Left = 0, Right = ll(1e10);
  while(Left <= Right) {
    ll mid = (Left + Right) / 2;
    ll min_l = INF, max_l = -INF;
    deque<pair<ll, ll>> min_q = MinQ, max_q = MaxQ;
    
    ll l = 0, r = 0;
    bool is_possible = false;
    for(ll i = 0; i < n; i++) {
      if(i > 0) {
        min_l = min(min_l, v[i - 1].second);
        max_l = max(max_l, v[i - 1].second);
      }
      l = i;
      while(r < n - 1 && v[l].first + 2 * mid >= v[r + 1].first) {
        r++;
        if(min_q.size() && min_q.front().second == r) min_q.pop_front();
        if(max_q.size() && max_q.front().second == r) max_q.pop_front();
      }
      ll mini = min_l, maxi = max_l;
      if(min_q.size()) mini = min(mini, min_q.front().first);
      if(max_q.size()) maxi = max(maxi, max_q.front().first);
      if(maxi - mini <= 2 * mid) {
        is_possible = true;
        break;
      }
    }

    if(is_possible) {
      Right = mid - 1;
    } else {
      Left = mid + 1;
    }
  }

  cout << fixed;
  cout.precision(1);
  cout << double(Left) / 10.0 << '\n';

  
  return 0;
}