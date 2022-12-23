#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

string find(string node, unordered_map<string, string> parent) {
  if(parent[node] == node) {
    return node;
  } else {
    return parent[node] = find(parent[node], parent);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  unordered_map<string, string> parent;
  set<string> keys;
  ll N, Q;
  cin >> N >> Q;
  for(ll i = 0; i < Q; i++) {
    ll c;
    string x, y;
    cin >> c;
    if(c == 1) {
      cin >> x >> y;
      if(keys.find(x) == keys.end()) {
        keys.insert(x);
        parent[x] = x;
      }
      if(keys.find(y) == keys.end()) {
        keys.insert(y);
        parent[y] = y;
      }
      x = find(x, parent);
      y = find(y, parent);
      parent[y] = x;
    } else if(c == 2) {
      cin >> x;
      string key = to_string(++N);
      keys.insert(key);
      parent[key] = x;
    } else {
      cin >> x;
      if(keys.find(x) == keys.end()) {
        keys.insert(x);
        parent[x] = x;
      }
      x = find(x, parent);
      cout << x << '\n';
    }
  }

  return 0;
}