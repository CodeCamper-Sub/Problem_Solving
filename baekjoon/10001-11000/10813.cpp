#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll N, M;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N >> M;

  vector<ll> v(N+1);

  iota(v.begin(), v.end(), 0);

  for(ll i = 0; i < M; i++) {
    ll a, b;
    cin >> a >> b;
    swap(v[a], v[b]);
  }

  for(ll i = 1; i <= N; i++) {
    cout << v[i] << ' ';
  }

  return 0;
}