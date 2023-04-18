#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

string a, b, c;
vector<vector<ll>> dp;

void init() {
  cin >> a >> b >> c;
  dp.assign(a.size() + 1, vector<ll>(b.size() + 1, -1));
}

ll backtracking(ll a_now, ll b_now, ll c_now) {
  if(dp[a_now][b_now] != -1) return dp[a_now][b_now];
  if(a_now == a.size() && b_now == b.size()) {
    return dp[a_now][b_now] = 1;
  }
  dp[a_now][b_now] = 0;
  if(a_now < a.size() && a[a_now] == c[c_now]) {
    dp[a_now][b_now] |= backtracking(a_now + 1, b_now, c_now + 1);
  }
  if(b_now < b.size() && b[b_now] == c[c_now]) {
    dp[a_now][b_now] |= backtracking(a_now, b_now + 1, c_now + 1);
  }
  return dp[a_now][b_now];
}

void solve() {
  backtracking(0, 0, 0);
  if(dp[0][0] == 1) {
    cout << "yes";
  } else {
    cout << "no"; 
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll tt;
  cin >> tt;
  for(ll T = 1; T <= tt; T++) {
    cout << "Data set " << T << ": ";
    init();
    solve();
    cout << '\n';
  }
  return 0;
}