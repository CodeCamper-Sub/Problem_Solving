#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

vector<vector<ll>> lamps;
ll n, m, k, answer;

void backtracking(ll now, vector<ll>& on_rows, ll partial_k, ll on_cnt) {
  if(k < partial_k || on_cnt < answer) return;
  if(now == m) {
    if((k - partial_k) % 2) return;
    answer = max(answer, on_cnt);
    return;
  }

  // 그대로 가기
  ll next_on_cnt = on_cnt;
  vector<ll> next_on_rows(on_rows);
  for(ll i = 0; i < n; i++) {
    if(next_on_rows[i] == 1 && lamps[i][now] == 0) next_on_cnt--;
    next_on_rows[i] &= lamps[i][now];
  }
  if(next_on_cnt > 0) {
    backtracking(now + 1, next_on_rows, partial_k, next_on_cnt);
  }

  // 바꿔서 가기
  next_on_cnt = on_cnt;
  next_on_rows = vector<ll>(on_rows);
  for(ll i = 0; i < n; i++) {
    if(next_on_rows[i] == 1 && lamps[i][now] == 1) next_on_cnt--;
    next_on_rows[i] &= !lamps[i][now];
  }
  if(next_on_cnt > 0) {
    backtracking(now + 1, next_on_rows, partial_k + 1, next_on_cnt);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  lamps.assign(n, vector<ll>(m));
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < m; j++) {
      char c;
      cin >> c;
      lamps[i][j] = c - '0';
    }
  }
  cin >> k;
  vector<ll> on_rows(n, 1);
  backtracking(0, on_rows, 0, n);

  cout << answer << '\n';
  
  return 0;
}