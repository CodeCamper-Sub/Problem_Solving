#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

struct Trie {
  bool is_leaf = false;
  Trie* childs[26];

  void insert(char* s) {
    if(*s == NULL) { 
      is_leaf = true;
      return;
    }
    ll key = s[0] - 'a';
    if(childs[key] == NULL) {
      childs[key] = new Trie();
    }
    childs[key]->insert(s+1);
  }

  bool find(char* s) {
    if(*s == NULL) return is_leaf;
    ll key = s[0] - 'a';
    if(childs[key] == NULL) {
      return false;
    } else {
      return childs[key]->find(s+1);
    }
  }
};

ll N, M, answer;
char s[550];
Trie root;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> N >> M;
  for(ll i = 0; i < N; i++) {
    cin >> s;
    root.insert(s);
  }

  for(ll i = 0; i < M; i++) {
    cin >> s;
    if(root.find(s)) answer++;
  }

  cout << answer << '\n';

  return 0;
}