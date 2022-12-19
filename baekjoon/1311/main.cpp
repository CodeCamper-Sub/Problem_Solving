#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll N, D[30][30], visited[30][1<<21];
queue<tuple<ll, ll, ll>> q;  // person, status, cost

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  for(ll i = 0; i < N; i++) for(ll j = 0; j < N; j++) {
    cin >> D[i][j];
  }

  visited[0][0] = 0;
  q.push({0, 0, 0});
  while(!q.empty()) {
    ll person = get<0>(q.front());
    ll status = get<1>(q.front());
    ll cost = get<2>(q.front());
    q.pop();
    if(visited[person][status] != 0 && visited[person][status] < cost) continue;
    for(ll i = 0; i < N; i++) {
      if(status & (1 << i)) continue;
      if(visited[person+1][status | (1 << i)] == 0 || visited[person + 1][status | (1 << i)] > cost + D[person][i]) {
        visited[person + 1][status | (1 << i)] = cost + D[person][i];
        q.push({person + 1, status | (1 << i), cost + D[person][i]});
      }
    }
  }

  cout << visited[N][(1 << N)-1] << '\n';
  
  return 0;
}