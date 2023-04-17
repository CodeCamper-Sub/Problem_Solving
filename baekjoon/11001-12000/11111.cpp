#include <bits/stdc++.h>
#define INF 999999999999
#define MAXN 55
#define MAX 55 * 55
typedef long long ll;
using namespace std;

ll n, m, score[5][5], grid[MAXN][MAXN], source, sink, cost[MAX][MAX], capacity[MAX][MAX], flow[MAX][MAX], dist[MAX], visited[MAX], inQ[MAX];
char c;
vector<ll> e[MAX];
ll dy[4] = {0, 0, 1, -1};
ll dx[4] = {1, -1, 0, 0};

void init() {
  score[0][0] = 10;
  score[0][1] = 8;
  score[0][2] = 7;
  score[0][3] = 5;
  score[0][4] = 1;
  
  score[1][1] = 6;
  score[1][2] = 4;
  score[1][3] = 3;
  score[1][4] = 1;

  score[2][2] = 3;
  score[2][3] = 2;
  score[2][4] = 1;

  score[3][3] = 2;
  score[3][4] = 1;

  score[4][4] = 0;

  for(ll i = 0; i < 5; i++) {
    for(ll j = 0; j < i; j++) {
      score[i][j] = score[j][i];
    }
  }
}

ll flatten(ll y, ll x) {
  return y * m + x;
}

void make_edge(ll now, ll next, ll _capacity, ll _cost) {
  e[now].push_back(next);
  e[next].push_back(now);
  capacity[now][next] += _capacity;
  cost[now][next] = _cost;
  cost[next][now] = -_cost;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  init();

  cin >> n >> m;

  source = MAX - 1;
  sink = MAX - 2;

  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < m; j++) {
      cin >> c;
      grid[i][j] = c == 'F' ? 4 : c - 'A';
    }
  }

  for(ll y = 0; y < n; y++) {
    for(ll x = 0; x < m; x++) {
      make_edge(source, flatten(y, x), 1, 0);
    }
  }

  for(ll y = 0; y < n; y++) {
    for(ll x = y % 2; x < m; x += 2) {
      for(ll k = 0; k < 4; k++) {
        ll ny = y + dy[k], nx = x + dx[k];
        if(ny < n && ny >= 0 && nx < m && nx >= 0) {
          make_edge(flatten(y, x), flatten(ny, nx), 1, -score[grid[y][x]][grid[ny][nx]]);
        }
      }
    }

    for(ll x = y % 2 ^ 0 ^ 1; x < m; x += 2) {
      make_edge(flatten(y, x), sink, 1, 0);
    }
  }

  ll total_cost = 0;
  while(true) {
    // dist[MAX], visited[MAX], inQ[MAX];
    fill(dist, dist + MAX, INF);
    fill(visited, visited + MAX, -1);
    fill(inQ, inQ + MAX, false);
    queue<ll> q;
    dist[source] = 0;
    inQ[source] = true;
    q.push(source);
    while(q.size()) {
      ll now = q.front();
      q.pop();
      inQ[now] = false;
      for(ll next: e[now]) {
        if(dist[next] > dist[now] + cost[now][next] && capacity[now][next] - flow[now][next] > 0) {
          dist[next] = dist[now] + cost[now][next];
          visited[next] = now;
          if(!inQ[next]) {
            inQ[next] = true;
            q.push(next);
          }
        }
      }
    }
    if(visited[sink] == -1) break;
    ll min_flow = INF;
    ll dest = sink;
    while(dest != source) {
      ll origin = visited[dest];
      min_flow = min(min_flow, capacity[origin][dest] - flow[origin][dest]);
      dest = origin;
    }

    dest = sink;
    while(dest != source) {
      ll origin = visited[dest];
      flow[origin][dest] += min_flow;
      flow[dest][origin] -= min_flow;
      total_cost += min_flow * cost[origin][dest];
      dest = origin;
    }
  }

  cout << -total_cost << '\n';
  
  return 0;
}