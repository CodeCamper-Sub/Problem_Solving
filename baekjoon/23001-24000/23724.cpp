#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

struct Node {
  char op;
  ll num;
  bool is_leaf;
  vector<Node*> connect;
  vector<ll> memo_mini, memo_maxi;

  Node(char op): op(op) {
    num = -1;
    is_leaf = false;
    memo_mini.assign(3, -INF);
    memo_maxi.assign(3, INF);
  }
  
  Node(ll num): num(num) {
    op = '@';
    is_leaf = true;
  }

  ll maximize(ll exclude) {
    if(is_leaf) return num;
    if(memo_maxi[exclude] != INF) return memo_maxi[exclude];
    vector<pair<ll, ll>> v;
    for(ll i = 0; i < 3; i++) {
      if(i == exclude) continue;
      if(connect[i]->is_leaf) {
        v.push_back({connect[i]->num, connect[i]->num});
      } else {
        for(ll j = 0; j < 3; j++) {
          if(connect[i]->connect[j] == this) {
            v.push_back({connect[i]->minimize(j), connect[i]->maximize(j)});
            break;
          }
        }
      }
    }
    if(op == '+') {
      return memo_maxi[exclude] = v[0].second + v[1].second;
    } else { // op == '-'
      return memo_maxi[exclude] = max(v[0].second - v[1].first, v[1].second - v[0].first);
    }
  }

  ll minimize(ll exclude) {
    if(is_leaf) return num;
    if(memo_mini[exclude] != -INF) return memo_mini[exclude];
    vector<pair<ll, ll>> v;
    for(ll i = 0; i < 3; i++) {
      if(i == exclude) continue;
      if(connect[i]->is_leaf) {
        v.push_back({connect[i]->num, connect[i]->num});
      } else {
        for(ll j = 0; j < 3; j++) {
          if(connect[i]->connect[j] == this) {
            v.push_back({connect[i]->minimize(j), connect[i]->maximize(j)});
            break;
          }
        }
      }
    }
    if(op == '+') {
      return memo_mini[exclude] = v[0].first + v[1].first;
    } else { // op == '-'
      return memo_mini[exclude] = min(v[0].first - v[1].second, v[1].first - v[0].second);
    }
  }

  ll maximize_as_root() {
    vector<pair<ll, ll>> v;
    for(ll i = 0; i < 3; i++) {
      if(connect[i]->is_leaf) {
        v.push_back({connect[i]->num, connect[i]->num});
      } else {
        for(ll j = 0; j < 3; j++) {
          if(connect[i]->connect[j] == this) {
            v.push_back({connect[i]->minimize(j), connect[i]->maximize(j)});
            break;
          }
        }
      }
    }
    if(op == '+') {
      return v[0].second + v[1].second + v[2].second;
    } else { // op == '-'
      return max(
        v[0].second - v[1].first - v[2].first,
        max(
          v[1].second - v[0].first - v[2].first,
          v[2].second - v[0].first - v[1].first
        )
      );
    }
  }
};

string s;
vector<Node*> nodes;

void make_tree(Node* parent, ll from, ll to, bool is_root) {
  if(!is_root) {
    if(from < to && s[from] == '(' && s[to] == ')') {
      from++; to--;
    }
  }
  if(from == to) {
    Node* now = new Node(ll(s[from] - '0'));
    nodes.push_back(now);
    now->connect.push_back(parent);
    parent->connect.push_back(now);
    return;
  }
  ll depth = 0;
  ll pivot_a = -1, pivot_b = -1;
  for(ll i = from; i <= to; i++) {
    if(s[i] == '(') depth++;
    else if(s[i] == ')') depth--;
    else if(depth == 0 && (s[i] == '-' || s[i] == '+')) {
      if(pivot_a == -1) pivot_a = i;
      else pivot_b = i;
    }
  }
  if(is_root) {
    Node* now = new Node(s[pivot_a]);
    nodes.push_back(now);
    make_tree(now, from, pivot_a - 1, false);
    make_tree(now, pivot_a + 1, pivot_b - 1, false);
    make_tree(now, pivot_b + 1, to, false);
  } else {
    Node* now = new Node(s[pivot_a]);
    nodes.push_back(now);
    now->connect.push_back(parent);
    parent->connect.push_back(now);
    make_tree(now, from, pivot_a - 1, false);
    make_tree(now, pivot_a + 1, to, false);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  while(true) {
    while(nodes.size()) {
      nodes.back()->connect.clear();
      delete nodes.back();
      nodes.pop_back();
    }
    cin >> s;
    if(s == "-1") break;
    make_tree(NULL, 0, s.size() - 1, true);
    ll answer = -INF;
    for(ll i = 0; i < nodes.size(); i++) {
      if(nodes[i]->is_leaf) continue;
      answer = max(answer, nodes[i]->maximize_as_root());
    }
    cout << answer << '\n';
  }
  
  return 0;
}