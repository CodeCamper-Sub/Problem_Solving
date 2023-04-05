#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll tt, fact[16], n, k;

ll factorial(ll n) {
  if(n == 0) return fact[0] = 1;
  else if(n < 16 && fact[n] != 0) return fact[n];
  else if(n < 16) return fact[n] = n * factorial(n - 1);
  else return factorial(n - 1);
}

// 1. 틀려야 하는 문제이고, 지목을 했으며, 아직 지목을 받지 못한 문제의 개수
// 2. 틀려야 하는 문제이고, 아직 지목을 하지 않고, 아직 지목을 받지도 못한 문제의 개수
// 3. 맞아야 하는 문제이고, 아직 지목을 받지 못한 문제의 개수
// 4. 현재까지 지목을 완료한 문제의 개수
// 5. 지목으로 온건지, 자동으로 온건지
ll go(ll a, ll b, ll c, ll t, bool is_auto) {
  if(t == k) return factorial(n - k);
  ll result = 0;

  if(a > 0) {
    if(is_auto) {
      result += a * go(a, b - 1, c, t + 1, true);
    } else {
      result += a * go(a - 1, b, c, t + 1, true);
    }
  }
  if(b > 0) {
    if(is_auto) {
      result += (b - 1) * go(a + 1, b - 2, c, t + 1, false);
    } else {
      result += b * go(a, b - 1, c, t + 1, false);
    }
  }
  if(c > 0) {
    if(is_auto) {
      result += c * go(a + 1, b - 1, c - 1, t + 1, true);
    } else {
      result += c * go(a, b, c - 1, t + 1, true);
    }
  }

  return result;
}

void init() { 
  ll t;
  cin >> t >> n >> k;
}

ll solve() {
  return go(0, k, n - k, 0, true);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> tt;
  for(ll T = 1; T <= tt; T++) {
    init();
    cout << T << ' ' << solve() << '\n';
  }
  return 0;
}