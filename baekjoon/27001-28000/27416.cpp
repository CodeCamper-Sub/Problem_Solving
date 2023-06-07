#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n, k;
vector<tuple<ll, ll, ll>> v;
vector<ll> populated, answer;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> n >> k;
  v.resize(n);
  ll id = 0;
  for(auto& [a, b, c]: v) {
    cin >> a >> b;
    c = id++;
  }
  
  sort(v.begin(), v.end(), [](auto a, auto b) {
    auto [a1, b1, _] = a;
    auto [a2, b2, __] = b;
    return b1 != b2 ? b1 < b2 : a1 < a2;
  });

  populated.assign(32, 0);
  answer.assign(n, 0);

  for(auto [a, b, index]: v) {
    for(ll i = a; i <= b; i++) {
      if(populated[i] < k) {
        answer[index] = i;
        populated[i]++;
        break;
      }
    }
  }

  for(ll a: answer) {
    cout << a << '\n';
  }
  
  return 0;
}