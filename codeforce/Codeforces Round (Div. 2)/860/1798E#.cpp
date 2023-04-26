#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n;
vector<ll> a, is_good, dp, answer, maxi;
// dp[i]: i, i + a[i] + 1, ... 중 하나를 바꿨을 때 얻을 수 있는 최대 길이

void init() {
  cin >> n;
  a.resize(n);
  for(ll& a: a) cin >> a;
  is_good.assign(n, -1);
  dp.assign(n, -1);
  maxi.assign(n, -1);
  answer.clear();
}

ll dfs(ll now) {
  if(dp[now] != -1) return dp[now]; 
  if(now + a[now] + 1 < n) {
    return dp[now] = max(maxi[now + 1] + 1, dfs(now + a[now] + 1) + 1);
  } else if(now < n - 1 && maxi[now + 1] > 0) {
    return dp[now] = maxi[now + 1] + 1;
  } else {
    return dp[now] = 1;
  }
}

void solve() {
  for(ll i = n - 2; i >= 0; i--) {
    if(i + a[i] + 1 == n) {
      is_good[i] = 1;
    } else if(i + a[i] + 1 < n && is_good[i + a[i] + 1] != -1) {
      is_good[i] = is_good[i + a[i] + 1] + 1;
    }
    maxi[i] = max(maxi[i + 1], is_good[i]);
    dfs(i);
  }

  answer.resize(n - 1);
  for(ll i = n - 2; i >= 0; i--) {
    if(a[i] == is_good[i + 1]) {
      answer[i] = 0;
    } else if(is_good[i + 1] != -1) {
      answer[i] = 1;
    } else if(a[i] <= dp[i + 1] || a[i] == 1) {
      answer[i] = 1;
    } else {
      answer[i] = 2;
    }
  }

  for(ll i = 0; i < answer.size(); i++) {
    cout << answer[i] << ' ';
  }
  cout << '\n';

  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll tt;
  cin >> tt;
  for(ll T = 1; T <= tt; T++) {
    init();
    solve();
  }
  return 0;
}