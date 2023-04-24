#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

list<ll> l;
vector<list<ll>::iterator> v;
vector<ll> visited;

ll m, n, a;

int main() {  
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  v.resize(m + 1);
  visited.assign(m + 1, false);
  for(ll i = 1; i <= n; i++) {
    cin >> a;
    if(!visited[a]) {
      visited[a] = true;
      l.push_back(a);
      auto iter = l.end();
      iter--;
      v[a] = iter;
    } else {
      v[a]++;
      if(v[a] == l.end()) {
        v[a]--;
        continue;
      }
      if(a > *(v[a])) {
        v[a]--;
        l.erase(v[a]);
        l.push_back(a);
        auto iter = l.end();
        iter--;
        v[a] = iter;
      } else {
        v[a]--;
        continue;
      }
    }
  }
  for(auto iter = l.begin(); iter != l.end(); iter++) {
    cout << *iter << ' ';
  }
  
  return 0;
}