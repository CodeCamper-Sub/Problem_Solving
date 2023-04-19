#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n;
vector<vector<ll>> dice;

ll next_idx(ll now) {
  if(now == 0) return 5;
  else if(now == 1) return 3;
  else if(now == 2) return 4;
  else if(now == 3) return 1;
  else if(now == 4) return 2;
  else return 0;
}

ll go(ll now, ll last) {
  if(now == n) return 0;
  ll last_idx;
  ll next_last_idx;
  for(ll i = 0; i < 6; i++) {
    if(dice[now][i] == last) {
      last_idx = i;
      next_last_idx = next_idx(i);
      break;
    }
  }
  ll maxi = -INF;
  for(ll i = 0; i < 6; i++) {
    if(i == next_last_idx || i == last_idx) continue;
    maxi = max(maxi, dice[now][i]);
  }

  return maxi + go(now + 1, dice[now][next_last_idx]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  if(n == 0) {
    cout << 0 << '\n';
    return 0;
  }
  dice.assign(n, vector<ll>(6));
  for(ll i = 0; i < n; i++) for(ll j = 0; j < 6; j++) cin >> dice[i][j];

  ll answer = 0;
  for(ll i = 0; i < 6; i++) {
    ll j = next_idx(i);
    ll maxi = -INF;
    for(ll k = 0; k < 6; k++) {
      if(k == i || k == j) continue;
      maxi = max(maxi, dice[0][k]);
    }
    answer = max(answer, maxi + go(1, dice[0][j]));
  }

  cout << answer << '\n';
  
  return 0;
}