#include <bits/stdc++.h>
#define INF 999999999999
#define MAX 2002000
typedef long long ll;
using namespace std;

ll flatten(const ll[]);

struct Vertex {
  ll state[9];

  bool is_succeed() {
    for(ll i = 0; i < 9; i++) {
        if(state[i]) return false;
    }
    return true;
  }

  ll id() {
    return flatten(state);
  }
};

ll succeed[MAX], fail[MAX], visited[MAX];
vector<Vertex> e[MAX];
char card[9][4];

ll flatten(const ll state[]) {
    ll id = 0;
    ll k = 1;
    for(ll i = 8; i >= 0; i--) {
        id += state[i] * k;
        k *= 5;
    }
    return id;
}

void unflatten(ll id, ll state[]) {
    for(ll i = 8; i >= 0; i--) {
        state[i] = id % 5;
        id /= 5;
    }
}

void dfs(Vertex now) {
    ll id = flatten(now.state);
    if(e[id].size() == 0) {
        fail[id] = 1;
        if(now.is_succeed()) 
            succeed[id] = 1;
    }
    for(Vertex next: e[id]) {
        if(!visited[flatten(next.state)]) {
            visited[flatten(next.state)] = true;
            dfs(next);
        }
        succeed[id] += succeed[flatten(next.state)];
        fail[id] += fail[flatten(next.state)];
    }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  for(ll i = 0; i < 9; i++) {
    for(ll j = 0; j < 4; j++) {
        string s;
        cin >> s;
        card[i][j] = s[0];
    }
  }

  for(ll id = 0; id < 1953125; id++) {
    ll state[9];
    unflatten(id, state);
    for(ll i = 0; i < 9; i++) {
        if(state[i] == 0) continue;
        for(ll j = i + 1; j < 9; j++) {
            if(state[j] == 0) continue;
            if(card[i][state[i] - 1] == card[j][state[j] - 1]) {
                Vertex v;
                unflatten(id, v.state);
                v.state[i] -= 1;
                v.state[j] -= 1;
                e[id].push_back(v);
            }
        }
    }
  }

  Vertex root;
  for(ll i = 0; i < 9; i++) root.state[i] = 4;
  dfs(root);

  cout << succeed[root.id()] << '\n';
  cout << fail[root.id()] << '\n';
  
  return 0;
}