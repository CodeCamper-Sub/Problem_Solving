#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
#define MAX 40040
#define mk make_pair
typedef long long ll;
using namespace std;

ll n, k;
vector<vector<pair<ll, ll>>> v; // 행별로 수평 성분의 배열을 저장
map<pair<ll, ll>, bool> holes;

// 구멍이 있는지, 총 물의 양
pair<bool, ll> recursion(ll start, ll end, ll y) {
  if(start >= end) return {false, 0};
  bool has_hole = false;
  ll water = 0;
  for(ll h = 0; true; h++) {
    auto lower = lower_bound(v[y + h].begin(), v[y + h].end(), mk(start, start));
    auto upper = upper_bound(v[y + h].begin(), v[y + h].end(), mk(end, end));
    if(lower == upper) continue;
    for(auto iter = lower; iter != upper; iter++) {
      has_hole |= (holes.count({iter->first, iter->second}) != 0);
      if(iter == lower) {
        auto [partial_has_hole, partial_water] = recursion(start, iter->first, y + h);
        has_hole |= partial_has_hole;
        water += partial_water;
      } else {
        auto previous_iter = iter; previous_iter--;
        auto [partial_has_hole, partial_water] = recursion(previous_iter->second, iter->first, y + h);
        has_hole |= partial_has_hole;
        water += partial_water;
      }
    }
    auto [partial_has_hole, partial_water] = recursion((upper - 1)->second, end, y + h);
    has_hole |= partial_has_hole;
    water += partial_water;
    if(!has_hole) {
      water += (end - start) * h;
    }
    break;
  }
  return {has_hole, water};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  v.resize(MAX);
  cin >> n;
  ll width = 0;
  for(ll i = 0; i < n; i++) {
    ll x1, y1, x2, y2;
    cin >> x1 >> y1;
    if(i == 0) continue;
    else if(i == n - 1) {
      width = x1;
      continue;
    }
    i++;
    cin >> x2 >> y2;
    v[y1].push_back({x1, x2});
  }

  cin >> k;
  for(ll i = 0; i < k; i++) {
    ll x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    holes[{x1, x2}] = true;
  }
  
  for(ll i = 0; i < MAX; i++) {
    sort(v[i].begin(), v[i].end());
  }

  auto [_, answer] = recursion(0, width, 0);
  cout << answer << '\n';
  
  return 0;
}