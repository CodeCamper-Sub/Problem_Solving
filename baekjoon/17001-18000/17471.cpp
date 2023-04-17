#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, answer, t, v;
vector<vector<ll>> e;
vector<ll> population;
vector<ll> color, visited;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  e.resize(n);
  population.resize(n);
  color.resize(n);
  visited.resize(n);
  answer = INF;
  for(ll i = 0; i < n; i++) cin >> population[i];
  for(ll i = 0; i < n; i++) {
    cin >> t;
    while(t--) {
      cin >> v;
      e[i].push_back(v - 1);
    }
  }

  for(ll i = 1; i < n; i++) {
    for(ll j = 0; j < i; j++) {
      color[j] = 0;
    }
    for(ll j = i; j < n; j++) {
      color[j] = 1;
    }
    do {
      fill(visited.begin(), visited.end(), false);
      ll z_index = -1, o_index = -1;
      for(ll j = 0; j < n; j++) {
        if(z_index == -1 && color[j] == 0) z_index = j;
        else if(o_index == -1 && color[j] == 1) o_index = j;
        else if(z_index != -1 && o_index != -1) break;
      }
      queue<ll> q;
      visited[z_index] = true;
      visited[o_index] = true;
      q.push(z_index);
      q.push(o_index);
      while(q.size()) {
        ll now = q.front();
        q.pop();
        for(ll next: e[now]) {
          if(!visited[next] && color[next] == color[now]) {
            visited[next] = true;
            q.push(next);
          }
        }
      }
      bool is_valid = true;
      for(ll j = 0; j < n; j++) {
        if(!visited[j]) {
          is_valid = false;
          break;
        }
      }
      if(!is_valid) continue;
      ll z_sum = 0, o_sum = 0;
      for(ll j = 0; j < n; j++) {
        if(color[j] == 0) {
          z_sum += population[j];
        } else {
          o_sum += population[j];
        }
      }
      answer = min(answer, abs(z_sum - o_sum));
    } while(next_permutation(color.begin(), color.end()));
  }
  
  if(answer == INF) {
    cout << -1 << '\n';
  } else {
    cout << answer << '\n';
  }

  return 0;
}