#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll N;
  cin >> N;
  ll arr[200200], initialValue, adjustment[200200];
  set<ll>* clean = new set<ll>();
  initialValue = -1;
  for(ll i = 1; i <= N; i++) {
    cin >> arr[i];
    adjustment[i] = 0;
  }
  ll Q;
  cin >> Q;
  for(ll i = 0; i < Q; i++) {
    ll c, a, b;
    cin >> c;
    if(c == 1) {
      cin >> a;
      initialValue = a;
      delete(clean);
      clean = new set<ll>();
    } else if (c == 2) {
      cin >> a >> b;
      if(clean->find(a) == clean->end()) {
        adjustment[a] = 0;
        clean->insert(a);
      }
      adjustment[a] += b;
    } else {
      cin >> a;
      if(clean->find(a) == clean->end()) {
        adjustment[a] = 0;
        clean->insert(a);
      }
      if(initialValue == -1) {
        cout << arr[a] + adjustment[a] << '\n';
      } else {
        cout << initialValue + adjustment[a] << '\n';
      }
    }
  }

  return 0;
}