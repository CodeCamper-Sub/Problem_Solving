#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, answer;
ll dist[22][22], breakable[22][22];
bool is_impossible = false;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  for(ll i = 1; i <= n; i++) {
    for(ll j = 1; j <= n; j++) {
      cin >> dist[i][j];
      answer += dist[i][j];
    }
  }

  for(ll i = 1; i <= n; i++) {
    for(ll j = 1; j <= n; j++) {
      if(i == j) continue;
      for(ll k = 1; k <= n; k++) {
        if(k == i || k == j) continue;
        if(dist[i][j] == dist[i][k] + dist[k][j]) {
          breakable[i][j] = 1;
        } else if(dist[i][j] > dist[i][k] + dist[k][j]) {
          is_impossible = true;
        }
      }
    }
  }

  if(is_impossible) {
    cout << -1 << '\n';
    return 0;
  }

  for(ll i = 1; i <= n; i++) {
    for(ll j = 1; j <= n; j++) {
      if(breakable[i][j]) {
        answer -= dist[i][j];
      }
    }
  }

  cout << answer / 2 << '\n';
  
  return 0;
}