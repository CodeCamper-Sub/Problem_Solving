#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

vector<ll> visited;

const ll random_length = 50;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  visited.resize(random_length * 2);

  // 길이가 100 이하인지 확인
  cin >> visited[0];
  for(ll i = 1; i < random_length * 2; i++) {
    cout << "? right" << endl;
    cin >> visited[i];
  }
  cout << "? flip" << endl;
  cin >> visited[random_length * 2 - 1];
  for(ll i = random_length * 2 - 2; i >= 0; i--) {
    cout << "? left" << endl;
    ll now;
    cin >> now;
    if(visited[i] != now) {
      cout << "! " << random_length * 2 - 1 - i << endl;
      return 0;
    }
  }
  
  srand(time(NULL));
  ll target = visited[0];
  for(ll i = 1; i < random_length; i++) {
    visited[i] = rand() % 2;
    if(visited[i]) target |= (1ll << i);
  }
  for(ll i = 1; i < random_length; i++) {
    cout << "? right" << endl;
    ll status;
    cin >> status;
    if(visited[i] != status) {
      cout << "? flip" << endl;
      cin >> status;
    }
  }
  ll now = 0;
  for(ll i = 0; i < random_length; i++) {
    cout << "? right" << endl;
    ll status;
    cin >> status;
    now >>= 1;
    if(status) now |= (1ll << (random_length - 1));
  }
  for(ll i = 1; i < 30000; i++) {
    cout << "? right" << endl;
    ll status;
    cin >> status;
    now >>= 1;
    if(status) now |= (1ll << (random_length - 1));
    if(now == target) {
      cout << "! " << i + random_length << endl;
      return 0;
    }
  }

  assert(false);
  
  return 0;
}