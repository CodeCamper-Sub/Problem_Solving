#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

struct SegTree {
  vector<ll> tree;
  ll root, start, end;

  SegTree(ll m) {
    // tree.assign(1ll << int(1 + ceil(log2(m))), INF);
    tree.assign(m * 4, INF);
    root = 1;
    start = 0;
    end = m;
  }

  void update(ll target, ll value) {
    update(root, start, end, target, value);
  }

  ll query(ll left, ll right) {
    return query(root, start, end, left, right);
  }

  ll value(ll target) {
    return value(root, start, end, target);
  }

  private:
  ll update(ll node, ll start, ll end, ll target, ll value) {
    if(target < start || end < target) return tree[node];
    else if(start == end) return tree[node] = min(tree[node], value);
    else {
      ll mid = (start + end) / 2;
      return tree[node] = min(update(node * 2, start, mid, target, value), update(node * 2 + 1, mid + 1, end, target, value));
    }
  }

  ll query(ll node, ll start, ll end, ll left, ll right) {
    if(right < start || end < left) return INF;
    else if(left <= start && end <= right) return tree[node];
    else {
      ll mid = (start + end) / 2;
      return min(query(node * 2, start, mid, left, right), query(node * 2 + 1, mid + 1, end, left, right));
    }
  }

  ll value(ll node, ll start, ll end, ll target) {
    if(start == end) return tree[node];
    ll mid = (start + end) / 2;
    if(target <= mid) return value(node * 2, start, mid, target);
    else return value(node * 2 + 1, mid + 1, end, target);
  }
};

ll n, m, k;
vector<vector<tuple<ll, ll, ll>>> e;
vector<SegTree> visited;
vector<vector<ll>> min_cost;
vector<vector<bool>> inQ;

void init() {
  cin >> n >> m >> k;
  e.assign(n + 1, vector<tuple<ll, ll, ll>>());
  visited.assign(n + 1, SegTree(m));
  min_cost.assign(n + 1, vector<ll>(n + 1, INF));
  inQ.assign(m + 1, vector<bool>(n + 1, false));
  for(ll i = 0; i < k; i++) {
    ll u, v, c, d;
    cin >> u >> v >> c >> d;
    e[u].push_back({v, c, d});
    min_cost[u][v] = min(min_cost[u][v], c);
  }
}

void floyd() {
  for(ll k = 1; k <= n; k++) {
    for(ll i = 1; i <= n; i++) {
      for(ll j = 1; j <= n; j++) {
        if(i == j) {
          min_cost[i][j] = 0;
          continue;
        }
        min_cost[i][j] = min(min_cost[i][j], min_cost[i][k] + min_cost[k][j]);
      }
    }
  }
}

void solve() {
  floyd();
  if(m < min_cost[1][n]) {
    cout << "Poor KCM\n";
    return;
  }
  queue<tuple<ll, ll>> q;
  visited[1].update(0, 0);
  q.push({0, 1});
  inQ[0][1] = true;
  while(q.size()) {
    auto [c, now] = q.front();
    q.pop();
    inQ[c][now] = false;
    for(auto [next, cost, dist]: e[now]) {
      if(c + cost + min_cost[next][n] > m) continue;
      ll next_dist = visited[now].value(c) + dist;
      if(visited[next].query(0, c + cost) > next_dist) {
        visited[next].update(c + cost, next_dist);
        if(!inQ[c + cost][next]) {
          q.push({c + cost, next});
          inQ[c + cost][next] = true;
        }
      }
    }
  }
  cout << visited[n].query(0, m) << '\n';
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  ll tt;
  cin >> tt;
  for(ll T = 1; T <= tt; T++) {
    init();
    solve();
  }
  return 0;
}