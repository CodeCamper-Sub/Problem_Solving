#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll N, M, i, j, k;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M;
  vector<ll> arr(N+1);
  fill(arr.begin(), arr.end(), 0);
  for(ll t = 0; t < M; t++) {
    cin >> i >> j >> k;
    for(ll u = i; u <= j; u++) {
      arr[u] = k;
    }
  }

  for(ll t = 1; t <= N; t++) {
    cout << arr[t] << ' ';
  }

  return 0;
}