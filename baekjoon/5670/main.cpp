#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

struct Trie {
  ll child_cnt = 0;
  vector<ll> child_indexes;
  Trie* childs[30] = {NULL, };

  void insert(char* s) {
    if(s[0] == NULL) {
      child_cnt++;
      return;
    }
    ll key = s[0] - 'a';
    if(childs[key] == NULL) {
      childs[key] = new Trie();
      child_cnt++;
      child_indexes.push_back(key);
    }
    childs[key]->insert(s+1);
  }

  ll find(char *s) {
    if(s[0] == NULL) return 0;
    ll key = s[0] - 'a';
    if(child_cnt == 1) {
      return childs[key]->find(s+1);
    } else {
      return childs[key]->find(s+1) + 1;
    }
  }

  void release() {
    for(ll i = 0; i < child_indexes.size(); i++) {
      childs[child_indexes[i]]->release();
      delete(childs[child_indexes[i]]);
    }
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout << fixed;
  cout.precision(2);

  while(true) {
    ll N, answer;
    char* arr[100100];
    Trie root[30];

    cin >> N;
    if(cin.eof()) break;

    for(ll i = 0; i < N; i++) {
      char *s = new char[100]();
      cin >> s;
      arr[i] = s;
      root[s[0]-'a'].insert(s+1);
    }

    answer = 0;
    for(ll i = 0; i < N; i++) {
      answer += root[arr[i][0]-'a'].find(arr[i] + 1) + 1;
      delete(arr[i]);
    }

    for(ll i = 0; i < 26; i++) {
      root[i].release();
    }

    cout << double(answer) / double(N) << '\n';
  }

  return 0;
}