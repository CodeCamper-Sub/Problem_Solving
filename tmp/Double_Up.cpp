#include <bits/stdc++.h>
#define MAX (LLONG_MAX / 3)
using namespace std;
using ll = long long;
using ld = long double;
using uint = unsigned int;

int dp[1010][1010];
vector<int> arr;

int sol(int s, int e) {
  if (s == e) return arr[s];
  int &ret = dp[s][e];
  if (ret != -1) return ret;
  ret = 0;

  for (int i = s; i < e; ++i) {
    int ss = sol(s, i);
    int ee = sol(i + 1, e);
    if (ss == ee)
      ret = max(ret, ss + 1);
    else
      ret = max(ret, max(ss, ee));
  }

  return ret;
}

void input() {
  int N;
  cin >> N;
  string tmp;
  ll total = 0;

  int nMax = 0;
  for (int i = 0; i < N; ++i) {
    cin >> tmp;

    ll now = 0;
    __int128_t nTmp = 0;
    for (char j : tmp) {
      nTmp *= (__int128_t)10;
      nTmp += (__int128_t)(j - '0');
    }

    while (nTmp) {
      ++now;
      nTmp /= (__int128_t)2;
    }

    now -= 1;
    arr.push_back(now);
    nMax = max((int)now, nMax);
  }
  memset(dp, -1, sizeof(dp));
  int ans = sol(0, N - 1);
  __int128_t ca = 1;
  __int128_t dv = 1;
  for (int i = 0; i < 17; ++i) {
    dv *= (__int128_t)10;
  }

  for (int i = 0; i < ans; ++i) {
    ca *= (__int128_t)2;
  }

  ll f = ca / dv;
  ll b = ca % dv;
  if (f) cout << f;
  cout << b;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  input();

  return 0;
}