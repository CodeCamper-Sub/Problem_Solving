#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, sieve[2020], arr[60], cnt, occupied[60], visited[60];
vector<ll> e[60], answer, sorted_answer;

bool dfs(ll now) {
  if(now == 0 || occupied[0] == now) return false;
  visited[now] = true;
  for(ll next: e[now]) {
    if(visited[next]) continue;
    visited[next] = true;
    if(occupied[next] == -1 || dfs(occupied[next])) {
      occupied[next] = now;
      occupied[now] = next;
      return true;
    }
  }

  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  sieve[1] = 1;
  for(ll i = 2; i < 2020; i++) {
    if(sieve[i] == 0) {
      for(ll j = 1; i * j < 2020; j++) {
        sieve[i * j] = i;
      }
    }
  }

  cin >> n;
  for(ll i = 0; i < n; i++) {
    cin >> arr[i];
  }

  for(ll i = 0; i < n; i++) {
    for(ll j = i + 1; j < n; j++) {
      if(sieve[arr[i] + arr[j]] == arr[i] + arr[j]) {
        e[i].push_back(j);
        e[j].push_back(i);
      }
    }
  }

  for(ll i = 0; i < e[0].size(); i++) {
    cnt = 1;
    fill(occupied, occupied + 60, -1);
    occupied[e[0][i]] = 0;
    occupied[0] = e[0][i];
    
    for(ll j = 1; j < n; j++) {
      if(occupied[j] != -1) continue;
      fill(visited, visited + 60, 0);
      if(dfs(j)) cnt++;
    }

    if(cnt == n / 2) {
      answer.push_back(e[0][i]);
    }
  }

  if(answer.size() == 0) {
    cout << -1 << '\n';
  } else {
    for(ll i = 0; i < answer.size(); i++) {
      sorted_answer.push_back(arr[answer[i]]);
    }

    sort(sorted_answer.begin(), sorted_answer.end());

    for(ll i = 0; i < sorted_answer.size(); i++) {
      cout << sorted_answer[i] << ' ';
    }
  }
  
  return 0;
}