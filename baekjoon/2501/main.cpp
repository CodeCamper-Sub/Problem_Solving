#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll N, K;
vector<ll> dividers;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> K;
  for(ll i = 1; i <= N; i++) {
    if(N % i == 0) dividers.push_back(i);
  }

  if(dividers.size() > K - 1) {
    cout << dividers[K - 1] << '\n';
  } else {
    cout << 0 << '\n';
  }

  return 0;
}