#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll N, A, B;
vector<ll> nodes, e[400400];
vector<pair<ll, ll>> ladders;
bool visited[400400];

void dfs(ll now) {
  for(ll next: e[now]) {
    if(!visited[next]) {
      visited[next] = true;
      dfs(next);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N;
  for(ll i = 0; i < N; i++) {
    cin >> A >> B;
    nodes.push_back(A);
    nodes.push_back(B);
    ladders.push_back({A, B});
  }

  sort(nodes.begin(), nodes.end());
  nodes.erase(unique(nodes.begin(), nodes.end()), nodes.end());
  if(nodes[0] != 1) {
    cout << 1 << '\n';
    return 0;
  }

  for(pair<ll, ll> ladder: ladders) {
    auto iter_a = lower_bound(nodes.begin(), nodes.end(), ladder.first);
    auto iter_b = lower_bound(nodes.begin(), nodes.end(), ladder.second);
    ll index_a = iter_a - nodes.begin();
    ll index_b = iter_b - nodes.begin();
    e[index_a].push_back(index_b);
    e[index_b].push_back(index_a);
  }

  visited[0] = true;
  dfs(0);
  ll answer = -INF;
  for(ll i = 0; i < nodes.size(); i++) {
    if(visited[i] == true) {
      answer = max(answer, nodes[i]);
    }
  }

  cout << answer << '\n';

  return 0;
}