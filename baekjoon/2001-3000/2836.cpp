#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll N, M, a, b, sum;
vector<pair<ll, ll>> v;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M;
  for(ll i = 0; i < N; i++) {
    cin >> a >> b;
    if(a <= b) continue;
    v.push_back({b, a});
  }

  if(v.size() == 0) {
    cout << M << '\n';
    return 0;
  }

  sort(v.begin(), v.end());
  auto [left, right] = v[0];
  for(ll i = 1; i < v.size(); i++) {
    auto [x, y] = v[i];
    if(right < x) {
      sum += right - left;
      left = x;
      right = y;
    } else {
      right = max(right, y);
    }
  }
  sum += right - left;
  cout << M + 2 * sum << '\n';

  return 0;
}