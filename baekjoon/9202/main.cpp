#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

struct Node {
  ll depth;
  map<char, Node*> childs;
  set<char> keys;
  vector<ll> ends;

  void insert(char* s, ll idx) {
    if(s[0] == '\0') {
      ends.push_back(idx);
    } else {
      if(childs[s[0]] == NULL) {
        keys.insert(s[0]);
        childs[s[0]] = new Node();
        childs[s[0]]->depth = depth + 1;
      }
      childs[s[0]]->insert(s + 1, idx);
    }
  }
};

struct Trie {
  map<char, Node*> roots;

  Trie() {
    for(ll i = 0; i < 26; i++) {
      roots['A' + i] = new Node();
      roots['A' + i]->depth = 1;
    }
  }

  void insert(char* s, ll idx) {
    roots[s[0]]->insert(s + 1, idx);
  }
};

ll w, p;
Trie trie;
char grid[10][10];
bool visited[10][10];
vector<string> v;

bool is_ok(ll y, ll x, Node* now) {
  if(y < 0 || y > 3) return false;
  if(x < 0 || x > 3) return false;
  if(visited[y][x]) return false;
  if(now->keys.find(grid[y][x]) == now->keys.end()) return false;
  return true;
}

void dfs(ll y, ll x, Node* now, set<ll>* found) {
  if(!now->ends.empty()) {
    for(ll end: now->ends) {
      found->insert(end);
    }
  }
  if(now->depth >= 8) return;
  ll dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
  ll dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
  for(ll k = 0; k < 8; k++) {
    ll ny = y + dy[k];
    ll nx = x + dx[k];
    if(is_ok(ny, nx, now)) {
      visited[ny][nx] = true;
      dfs(ny, nx, now->childs[grid[ny][nx]], found);
      visited[ny][nx] = false;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> w;
  for(ll i = 0; i < w; i++) {
    char s[10];
    cin >> s;
    trie.insert(s, i);
    v.push_back(string(s));
  }
  cin >> p;
  while(p--) {
    set<ll> found;
    for(ll i = 0; i < 4; i++) {
      for(ll j = 0; j < 4; j++) {
        cin >> grid[i][j];
        visited[i][j] = false;
      }
    }
    for(ll i = 0; i < 4; i++) {
      for(ll j = 0; j < 4; j++) {
        visited[i][j] = true;
        dfs(i, j, trie.roots[grid[i][j]], &found);
        visited[i][j] = false;
      }
    }
    ll score = 0;
    string longest = "";
    for(ll idx: found) {
      string now = v[idx];
      if(now.size() <= 2) score += 0;
      else if(now.size() <= 4) score += 1;
      else if(now.size() == 5) score += 2;
      else if(now.size() == 6) score += 3;
      else if(now.size() == 7) score += 5;
      else if(now.size() == 8) score += 11;

      if(longest.size() < now.size()) {
        longest = now;
      } else if(longest.size() == now.size() && longest.compare(now) > 0) {
        longest = now;
      }
    }
    cout << score << " " << longest << " " << found.size() << '\n';
  }

  return 0;
}