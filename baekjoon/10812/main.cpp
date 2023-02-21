#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll N, M, i, j, k;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M;
  vector<ll> v(N+1);
  iota(v.begin(), v.end(), 0);

  while(M--) {
    cin >> i >> j >> k;
    vector<ll> temp;
    for(ll t = k; t <= j; t++) {
      temp.push_back(v[t]);
    }
    for(ll t = i; t < k; t++) {
      temp.push_back(v[t]);
    }
    for(ll t = 0; t < temp.size(); t++) {
      v[i+t] = temp[t];
    }
  }

  for(ll i = 1; i <= N; i++) {
    cout << v[i] << ' ';
  }

  return 0;
}