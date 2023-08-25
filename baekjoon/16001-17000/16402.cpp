#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll n, m;
vector<ll> parent;
map<string, ll> mp;
map<ll, string> inv;

ll Find(ll a) {
  if(parent[a] == a) return a;
  else return parent[a] = Find(parent[a]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> m;
  parent.resize(n);
  iota(parent.begin(), parent.end(), 0);

  cin.ignore();
  for(ll i = 0; i < n; i++) {
    string s;
    getline(cin, s, '\n');
    mp[s] = i;
    inv[i] = s;
  }

  for(ll i = 0; i < m; i++) {
    string _a, _b, c;
    getline(cin, _a, ',');
    getline(cin, _b, ',');
    getline(cin, c);

    ll a = mp[_a], b = mp[_b];
    if(c == "1") {
      if(Find(a) == b) {
        // 자신의 종주국과 전쟁한 경우
        parent[a] = a;
        parent[b] = a;
      } else {
        parent[Find(b)] = a;
      }
    } else { // c == "2"
      if(Find(b) == a) {
        parent[b] = b;
        parent[a] = b;
      } else {
        parent[Find(a)] = b;
      }
    }
  }

  set<string> answer;
  for(ll i = 0; i < n; i++) {
    if(parent[i] == i) {
      answer.insert(inv[i]);
    }
  }

  cout << answer.size() << '\n';
  for(string ans: answer) {
    cout << ans << '\n';
  }


  
  return 0;
}