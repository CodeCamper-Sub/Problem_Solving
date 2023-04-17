#include <bits/stdc++.h>
#define INF 999999999999
#define MAX 220
typedef long long ll;
using namespace std;

ll n, capacity[MAX][MAX], flow[MAX][MAX], source, sink, level[MAX], work[MAX], max_flow, sum;
vector<ll> e[MAX];

void make_edge(ll now, ll next, ll c) {
  e[now].push_back(next);
  e[next].push_back(now);
  capacity[now][next] += c;
}

bool get_level_graph() {
  fill(level, level + MAX, -1);
  queue<ll> q;
  level[source] = 0;
  q.push(source);
  while(q.size()) {
    ll now = q.front();
    q.pop();
    for(ll next: e[now]) {
      if(level[next] == -1 && capacity[now][next] - flow[now][next] > 0) {
        level[next] = level[now] + 1;
        q.push(next);
      }
    }
  }
  
  return level[sink] != -1;
}

ll send_flow(ll now, ll min_flow) {
  if(now == sink) return min_flow;
  for(ll &i = work[now]; i < e[now].size(); i++) {
    ll next = e[now][i];
    if(level[now] + 1 == level[next] && capacity[now][next] - flow[now][next]) {
      ll result = send_flow(next, min(min_flow, capacity[now][next] - flow[now][next]));
      if (result > 0) {
        flow[now][next] += result;
        flow[next][now] -= result;
        return result;
      }
    }
  }

  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  source = MAX - 1;
  sink = MAX - 2;
  sum = 0;
  ll row_sum = 0;
  for(ll i = 0; i < n; i++) {
    ll c;
    cin >> c;
    row_sum += c;
    make_edge(source, i, c);
  }

  ll col_sum = 0;
  for(ll i = 0; i < n; i++) {
    ll c;
    cin >> c;
    col_sum += c;
    make_edge(n + i, sink, c);
  }

  sum = min(row_sum, col_sum);

  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < n; j++) {
      make_edge(i, n + j, INF);
    }
  }

  ll left = 0, right = 10000;
  while(left <= right) {
    ll mid = (left + right) / 2;
    for(ll i = 0; i < n; i++) {
      for(ll j = 0; j < n; j++) {
        capacity[i][n + j] = mid;
      }
    }
    fill(&flow[0][0], &flow[MAX - 1][MAX], 0);

    max_flow = 0;
    while(get_level_graph()) {
      fill(work, work + MAX, 0);
      while(true) {
        ll result = send_flow(source, INF);
        if(result == 0) break;
        max_flow += result;
      }
    }

    if(max_flow == sum) {
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }

  if(max_flow != sum) {
    for(ll i = 0; i < n; i++) {
      for(ll j = 0; j < n; j++) {
        capacity[i][n + j] = left;
      }
    }
    fill(&flow[0][0], &flow[MAX - 1][MAX], 0);

    while(get_level_graph()) {
      fill(work, work + MAX, 0);
      while(true) {
        ll result = send_flow(source, INF);
        if(result == 0) break;
      }
    }
  }

  cout << left << '\n';
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < n; j++) {
      cout << flow[i][n + j] << ' ';
    }
    cout << '\n';
  }
  
  return 0;
}