#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, answer, me;
vector<ll> r, dead;
vector<vector<ll>> grid;

void kill(ll p, bool by_mafia) {
  if(by_mafia) {
    for(ll i = 0; i < n; i++) {
      r[i] += grid[p][i];
    }
  }
  dead[p] = true;
}

void revive(ll p, bool by_mafia) {
  if(by_mafia) {
    for(ll i = 0; i < n; i++) {
      r[i] -= grid[p][i];
    }
  }
  dead[p] = false;
}

ll notorious() {
  ll p = 0;
  ll maxi = -INF;
  for(ll i = 0; i < n; i++) {
    if(dead[i]) continue;
    if(r[i] > maxi) {
      maxi = r[i];
      p = i;
    }
  }
  assert(maxi != -INF);
  return p;
}

void backtracking(ll now) {
  if((n - now) % 2 == 0) {
    // 밤
    if((n - now) == 2) {
      // 게임이 끝남
      answer = max(answer, n / 2);
    } else {
      for(ll i = 0; i < n; i++) {
        if(i == me || dead[i]) continue;
        kill(i, true);
        backtracking(now + 1);
        revive(i, true);
      }
    }
  } else {
    // 낮
    ll nt = notorious();
    if(nt == me) {
      // 게임이 끝남
      answer = max(answer, (now + 1) / 2);
    } else {
      kill(nt, false);
      backtracking(now + 1);
      revive(nt, false);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  r.resize(n);
  dead.resize(n);
  grid.assign(n, vector<ll>(n));
  for(ll i = 0; i < n; i++) {
    cin >> r[i];
  }
  
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < n; j++) {
      cin >> grid[i][j];
    }
  }

  cin >> me;
  backtracking(0);

  cout << answer << '\n';
  
  return 0;
}