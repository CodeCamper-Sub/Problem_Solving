#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

ll N;
vector<tuple<ll,ll, ll>> v;
int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cin >> N;
  for(ll i = 1; i <= N; i++){
    ll a, b,c,d;
    cin >> a >> b >> c >> d;
    v.push_back({b*c*d,b+c+d,a});
  }
  sort(v.begin(), v.end());
  cout << get<2>(v[0]) << " " << get<2>(v[1]) << " " << get<2>(v[2]) << " ";
  
  
  return 0;
}