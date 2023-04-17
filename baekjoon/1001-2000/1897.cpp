#include <bits/stdc++.h>
#define INF 999999999999
#define MAX 1010
typedef long long ll;
using namespace std;

ll d, visited[MAX];
vector<string> v;
vector<ll> e[MAX];
string answer;

bool connectable(string a, string b) {
  ll i = 0, j = 0;
  while(i < a.size() && j < b.size() && j <= i + 1) {
    if(a[i] == b[j]) {
      i++;
    }
    j++;
  }
  return j <= i + 1;
}

void dfs(ll now) {
  if(answer.size() < v[now].size()) answer = v[now];
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

  cin >> d;
  v.resize(d + 1);
  cin >> v[0];
  
  for(ll i = 1; i <= d; i++) {
    cin >> v[i];
  }

  sort(v.begin() + 1, v.end(), [](string a, string b) {
    return a.size() < b.size();
  });

  for(ll i = 0; i < v.size(); i++) {
    for(ll j = i + 1; j < v.size(); j++) {
      if(v[i].size() + 1 != v[j].size()) continue;
      if(connectable(v[i], v[j])) {
        e[i].push_back(j);
      }
    }
  }

  visited[0] = true;
  dfs(0);

  cout << answer << '\n';
  
  return 0;
}