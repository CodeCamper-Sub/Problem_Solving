//
//  main.cpp
//  E
//
//  Created by 한경수 on 2022/07/05.
//

#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <tuple>
typedef long long ll;
using namespace std;

enum Orientation {
  NOT_DETERMINED,
  L,
  R
};

ll n, m, type, i, j;
vector<tuple<ll, ll, ll>> relationships;
vector<ll> no_oriented_edge[200200];
vector<ll> oriented_edge[200200];
Orientation orientation[200200];
ll location[200200];
int indegree[200200];
vector<ll> topological_sort_result;

string orientation_to_string(Orientation ori) {
  if(ori == L) {
    return "L";
  } else if(ori == R){
    return "R";
  } else {
    return "NOT_DETERMINED";
  }
}

bool create_bipartite_graph() {
  queue<ll> q;
  for(int l = 1; l <= n; l++) {
    if(orientation[l] == NOT_DETERMINED) {
      orientation[l] = L;
      q.push(l);
      while(!q.empty()) {
        ll now = q.front();
        q.pop();
        for(int k = 0; k < no_oriented_edge[now].size(); k++) {
          ll next = no_oriented_edge[now][k];
          if(orientation[next] == NOT_DETERMINED) {
            if(orientation[now] == L) {
              orientation[next] = R;
            } else {
              orientation[next] = L;
            }
            q.push(next);
          } else if(orientation[next] == orientation[now]) {
            return false;
          }
        }
      }
    }
  }
  return true;
}

void create_directional_graph() {
  for(int k = 0; k < relationships.size(); k++) {
    ll type = get<0>(relationships[k]);
    ll i = get<1>(relationships[k]);
    ll j = get<2>(relationships[k]);
    if(type == 1) {
      if(orientation[i] == L) {
        oriented_edge[i].push_back(j);
        indegree[j]++;
      } else {
        oriented_edge[j].push_back(i);
        indegree[i]++;
      }
    } else {
      if(orientation[i] == L) {
        oriented_edge[j].push_back(i);
        indegree[i]++;
      } else {
        oriented_edge[i].push_back(j);
        indegree[j]++;
      }
    }
  }
}

void topological_sort() {
  queue<ll> q;
  for(int k = 1; k <= n; k++) {
    if(indegree[k] == 0) {
      q.push(k);
    }
  }
  while(!q.empty()) {
    ll now = q.front();
    q.pop();
    topological_sort_result.push_back(now);
    for(int k = 0; k < oriented_edge[now].size(); k++) {
      ll next = oriented_edge[now][k];
      indegree[next]--;
      if(indegree[next] == 0) {
        q.push(next);
      }
    }
  }
}

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  
  for(int k = 0; k < m; k++) {
    cin >> type >> i >> j;
    relationships.push_back({type, i, j});
    no_oriented_edge[i].push_back(j);
    no_oriented_edge[j].push_back(i);
  }
  
  if(create_bipartite_graph()) {
    create_directional_graph();
    topological_sort();
    if(topological_sort_result.size() == n) {
      cout << "YES\n";
      for(int k = 0; k < topological_sort_result.size(); k++) {
        ll now = topological_sort_result[k];
        location[now] = k;
      }
      for(int k = 1; k <= n; k++) {
        if(orientation[k] == NOT_DETERMINED) {
          orientation[k] = L;
        }
      }
      for(int k = 1; k <= n; k++) {
        cout << orientation_to_string(orientation[k]) << " " << location[k] << '\n';
      }
    } else {
      cout << "NO";
    }
  } else {
    cout << "NO";
  }

  return 0;
}
