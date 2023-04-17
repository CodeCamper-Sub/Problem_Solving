#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll N, x, y, answer;
vector<pair<ll, ll>> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  for(ll i = 0; i < N; i++) {
    cin >> x >> y;
    v.push_back({x, y});
  }
  sort(v.begin(), v.end());
  auto [start, end] = v[0];
  for(ll i = 1; i < v.size(); i++) {
    auto [x, y] = v[i];
    if(end < x) {
      answer += end - start;
      start = x;
      end = y;
    } else {
      end = max(end, y);
    }
  }
  answer += end - start;

  cout << answer << '\n';

  return 0;
}