#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll l, w, h, n;
map<ll, ll> cubes;

ll divide_conquer(ll length, ll width, ll height) {
  if(length == 0 || width == 0 || height == 0) return 0;
  // 가능한 가장 큰 큐브 넣기
  for(auto iter = cubes.rbegin(); iter != cubes.rend(); iter++) {
    if(iter->second == 0 || iter->first > length || iter->first > width || iter->first > height) continue;
    ll s = iter->first;
    iter->second -= 1;

    if(iter->second == 0) {
      cubes.erase(s);
    }

    vector<ll> results;
    ll partial_result, result = 1;
    partial_result = divide_conquer(length - s, s, height);
    if(partial_result == -1) return -1;
    result += partial_result;

    partial_result = divide_conquer(s, width - s, height);
    if(partial_result == -1) return -1;
    result += partial_result;

    partial_result = divide_conquer(s, s, height - s);
    if(partial_result == -1) return -1;
    result += partial_result;

    partial_result = divide_conquer(length - s, width - s, height);
    if(partial_result == -1) return -1;
    result += partial_result;

    return result;
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  cin >> l >> w >> h >> n;
  for(ll i = 0; i < n; i++) {
    ll a, b;
    cin >> a >> b;
    cubes[ll(pow(2, a) + 0.0005)] = b;
  }

  cout << divide_conquer(l, w, h) << '\n';

  
  return 0;
}