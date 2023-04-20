#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, q, c, i, j;
vector<multiset<ll>> boxes;
vector<set<ll>> cards;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n;
  boxes.assign(200200, multiset<ll>());
  cards.assign(200200, set<ll>());

  cin >> q;
  while(q--) {
    cin >> c;
    if(c == 1) {
      cin >> i >> j;
      boxes[j].insert(i);
      cards[i].insert(j);
    } else if(c == 2) {
      cin >> i;
      for(ll card: boxes[i]) {
        cout << card << ' ';
      }
      cout << '\n';
    } else {
      cin >> i;
      for(ll box: cards[i]) {
        cout << box << ' ';
      }
      cout << '\n';
    }
  }
  
  return 0;
}