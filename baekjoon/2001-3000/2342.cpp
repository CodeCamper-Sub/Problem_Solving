#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

vector<ll> v;
vector<vector<vector<ll>>> dp;

ll cost(ll from, ll to) {
  if(from == 0) {
    return 2;
  } else if(from == 1) {
    if(to == 1) return 1;
    else if(to == 2 || to == 4) return 3;
    else return 4;
  } else if(from == 2) {
    if(to == 2) return 1;
    else if(to == 1 || to == 3) return 3;
    else return 4;
  } else if(from == 3) {
    if(to == 3) return 1;
    else if(to == 2 || to == 4) return 3;
    else return 4;
  } else {
    if(to == 4) return 1;
    else if(to == 1 || to == 3) return 3;
    else return 4;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  while(true) {
    ll a; cin >> a;
    if(a == 0) break;
    v.push_back(a);
  }

  dp.resize(5);
  for_each(dp.begin(), dp.end(), [](auto& layer) {
    layer.assign(5, vector<ll>(v.size() + 1, INF));
  });

  dp[0][0][0] = 0;
  for(ll i = 0; i < v.size(); i++) {
    for(ll j = 0; j < 5; j++) {
      for(ll k = 0; k < 5; k++) {
        if(dp[j][k][i] == INF) continue;
        if(j == v[i]) {
          dp[j][k][i + 1] = min(dp[j][k][i + 1], dp[j][k][i] + cost(j, j));
        } else if(k == v[i]) {
          dp[j][k][i + 1] = min(dp[j][k][i + 1], dp[j][k][i] + cost(k, k));
        } else {
          dp[v[i]][k][i + 1] = min(dp[v[i]][k][i + 1], dp[j][k][i] + cost(j, v[i]));
          dp[j][v[i]][i + 1] = min(dp[j][v[i]][i + 1], dp[j][k][i] + cost(k, v[i]));
        }
      }
    }
  }

  ll answer = INF;
  for(ll i = 0; i < 5; i++) {
    for(ll j = 0; j < 5; j++) {
      answer = min(answer, dp[i][j][v.size()]);
    }
  }

  cout << answer << '\n';


  
  return 0;
}