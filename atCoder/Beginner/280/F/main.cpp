#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll find(ll a, ll parent[]) {
  if(parent[a] == -1) {
    return a;
  } else {
    return parent[a] = find(parent[a], parent);
  }
}

bool dfs(ll now, vector<pair<ll, ll>> e[], bool cycle_checker[], bool visited[], ll parent[]) {
  bool has_cycle = false;
  vector<pair<ll, ll>> visited_next;
  for(ll i = 0; i < e[now].size(); i++) {
    ll next = e[now][i].first;
    ll cost = e[now][i].second;

    if(!has_cycle) {
      // 다음 점으로 가는 가중치가 다른 간선이 2개 이상 있는 경우도 사이클로 간주
      if(visited_next.size() == 0) {
        visited_next.push_back(e[now][i]);
      } else {
        auto iter = lower_bound(visited_next.begin(), visited_next.end(), e[now][i]);
        if(iter == visited_next.begin()) {
          if((*iter).first == next) {
            if((*iter).second != cost) has_cycle = true;
          } else {
            visited_next.push_back(e[now][i]);
          }
        } else if(iter == visited_next.end()) {
          iter--;
          if((*iter).first == next) {
            if((*iter).second != cost) has_cycle = true;
          } else {
            visited_next.push_back(e[now][i]);
          }
        } else {
          if((*iter).first == next) {
            if((*iter).second != cost) has_cycle = true;
          } else if ((*(iter-1)).first == next) {
            iter -= 1;
            if((*iter).second != cost) has_cycle = true;
          } else {
            visited_next.push_back(e[now][i]);
          }
        }
      }
    }

    if(!visited[next]) {
      cycle_checker[next] = true;
      visited[next] = true;
      parent[next] = now;
      has_cycle |= dfs(next, e, visited, cycle_checker, parent);
      cycle_checker[next] = false;
    } else if(cycle_checker[next]) {
      has_cycle = true;
    }
  }
  return has_cycle;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll N, M, Q;
  vector<pair<ll, ll>> e[100100]; //<Destination, Cost>
  ll parent[100100];
  bool visited[100100];
  bool cycle_checker[100100];
  ll ind[100100];
  bool cycle_included[100100];
  cin >> N >> M >> Q;

  for(ll i = 1; i <= N; i++) {
    parent[i] = -1;
    visited[i] = false;
    ind[i] = 0;
    cycle_included[i] = false;
  }
  for(ll i = 0; i < M; i++) {
    ll A, B, C;
    cin >> A >> B >> C;
    e[A].push_back({B, C});
    ind[B]++;
  }
  for(ll i = 1; i <= N; i++) {
    if(ind[i] == 0) {
      cycle_checker[i] = true;
      visited[i] = true;
      parent[i] = -1;
      cycle_included[i] = dfs(i, e, cycle_checker, visited, parent);
      cycle_checker[i] = false;
    }
  }
  for(ll i = 1; i <= N; i++) {
    if(!visited[i]) {
      cycle_checker[i] = true;
      visited[i] = true;
      parent[i] = -1;
      cycle_included[i] = dfs(i, e, cycle_checker, visited, parent);
      cycle_checker[i] = false;
    }
  }

  for(ll i = 0; i < Q; i++) {
    ll X, Y;
    cin >> X >> Y;
    X = find(X, parent);
    Y = find(Y, parent);
    if(X != Y) {
      cout << "nan" << '\n';
    } else if (cycle_included[X]) {
      cout << "inf" << '\n';
    } else {
      cout << "두 점 사이의 거리\n";
    }
  }

  return 0;
}