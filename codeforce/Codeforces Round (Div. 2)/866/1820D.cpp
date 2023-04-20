#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

struct Cake {
  ll h, w;
};

ll tt, n;
vector<Cake> v, answers;
vector<vector<Cake*>> h, w;
map<ll, ll> used_h, used_w;
unordered_map<ll, ll> comp_h, comp_w;

void init() {
  cin >> n;
  v.resize(n);
  answers.clear();
  for(ll i = 0; i < n; i++) {
    cin >> v[i].h >> v[i].w;
    used_h[v[i].h]++;
    used_w[v[i].w]++;
  }
  h.assign(used_h.size(), vector<Cake*>());
  w.assign(used_w.size(), vector<Cake*>());

  ll id = 0;
  for(auto [k, _]: used_h) {
    comp_h[k] = id++;
  }
  id = 0;
  for(auto [k, _]: used_w) {
    comp_w[k] = id++;
  }
  for(ll i = 0; i < n; i++) {
    h[comp_h[v[i].h]].push_back(&v[i]);
    w[comp_w[v[i].w]].push_back(&v[i]);
  }
}

void backtracking(set<Cake*>& left, ll now_h, ll now_w) {
  if(left.size() == 0) {
    answers.push_back({now_h, now_w});
    return;
  }
  for(Cake* c: h[comp_h[now_h]]) {
    if(left.find(c) != left.end()) {
      left.erase(c);
      backtracking(left, now_h, now_w + c->w);
      left.insert(c);
    }
  }
  for(Cake* c: w[comp_w[now_w]]) {
    if(left.find(c) != left.end()) {
      left.erase(c);
      backtracking(left, now_h + c->h, now_w);
      left.insert(c);
    }
  }
}

void solve() {
  set<Cake*> left;
  for(ll i = 0; i < n; i++) {
    left.insert(&v[i]);
  }
  for(ll i = 0; i < n; i++) {
    left.erase(&v[i]);
    backtracking(left, v[i].h, v[i].w);
    left.insert(&v[i]);
  }

  cout << answers.size() << '\n';
  for(Cake a: answers) {
    cout << a.h << ' ' << a.w << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> tt;
  while(tt--) {
    init();
    solve();
  }
  return 0;
}