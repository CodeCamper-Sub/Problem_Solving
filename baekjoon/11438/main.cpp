#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

void dfs(ll now, ll* depth, vector<ll>* e, ll* parent) {
  for(ll i = 0; i < e[now].size(); i++) {
    ll next = e[now][i];
    if(depth[next] == -1) {
      depth[next] = depth[now] + 1;
      parent[next] = now;
      dfs(next, depth, e, parent);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll N, A, B, parent[100100], depth[100100];
  vector<ll> e[100100];
  cin >> N;
  for(ll i = 1; i <= N-1; i++) {
    cin >> A >> B;
    e[A].push_back(B);
    e[B].push_back(A);
  }
  for(ll i = 1; i <= N; i++) {
    depth[i] = -1;
  }
  depth[1] = 0;
  parent[1] = -1;
  dfs(1, depth, e, parent);

  ll sparse[20][100100];
  for(ll i = 1; i <= N; i++) {
    sparse[0][i] = parent[i];
  }
  for(ll k = 1; k < 20; k++) {
    for(ll i = 1; i <= N; i++) {
      if(sparse[k-1][i] >= 0) {
        sparse[k][i] = sparse[k-1][sparse[k-1][i]];
      } else {
        sparse[k][i] = -1;
      }
    }
  }

  return 0;
}