#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

struct Shark {
  ll a, b, c;

  bool operator<=(const Shark& rhs) {
    return a <= rhs.a && b <= rhs.b && c <= rhs.c;
  }

  bool operator==(const Shark& rhs) {
    return a == rhs.a && b == rhs.b && c == rhs.c;
  }

  bool operator!=(const Shark& rhs) {
    return !(*this == rhs);
  }
};

ll n, a, b, c, visited[60], occupied[60], dead_cnt;

vector<Shark> sharks;
vector<ll> e[110];

bool dfs(ll now) {
  for(ll next: e[now]) {
    if(visited[next]) continue;
    visited[next] = true;
    if(occupied[next] == -1 || dfs(occupied[next])) {
      occupied[next] = now;
      return true;
    }
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  for(ll i = 0; i < n; i++) {
    cin >> a >> b >> c;
    sharks.push_back({a, b, c});
  }

  for(ll i = 0; i < n; i++) {
    for(ll j = i + 1; j < n; j++) {
      if(sharks[i] == sharks[j]) {
        e[i].push_back(j);
        e[n + i].push_back(j);
      } else if(sharks[i] <= sharks[j]) {
        e[j].push_back(i);
        e[n + j].push_back(i);
      } else if(sharks[j] <= sharks[i]) {
        e[i].push_back(j);
        e[n + i].push_back(j);
      }
    }
  }

  fill(occupied, occupied + n, -1);
  for(ll i = 0; i < 2 * n; i++) {
    fill(visited, visited + n, false);
    if(dfs(i)) dead_cnt++;
  }

  cout << n - dead_cnt << '\n';
  
  return 0;
}