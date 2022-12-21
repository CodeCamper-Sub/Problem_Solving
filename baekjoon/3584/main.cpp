#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll T;
  cin >> T;
  while(T--) {
    ll N, A, B, root, a, b;
    ll parent[10100];
    ll visited[10100];
    
    cin >> N;
    if(cin.eof()) break;

    for(ll i = 0; i < N; i++) {
      parent[i] = -1;
      visited[i] = 0;
    }

    for(ll i = 0; i < N-1; i++) {
      cin >> A >> B;
      parent[B] = A;
    }
    cin >> a >> b;
    visited[a] = 1;
    while(parent[a] != -1) {
      a = parent[a];
      visited[a] = 1;
    }


    while(parent[b] != -1 && visited[b] == 0) {
      b = parent[b];
    }

    cout << b << '\n';
  }

  return 0;
}