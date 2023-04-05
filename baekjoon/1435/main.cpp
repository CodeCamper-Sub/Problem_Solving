#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll dist[4][4];
vector<ll> v = {0, 1, 1, 1};

bool validate(ll a, ll b, ll c, ll d, ll e) {
  if((e * ((d + e) * (d + e) + c * c - a * a)) % (d + e) != 0) return false;
  return c * c + e * e - (e * ((d + e) * (d + e) + c * c - a * a)) / (d + e) == b * b;
}

bool validate() {
  for(ll i = 0; i < 4; i++) {
    for(ll j = i + 1; j < 4; j++) {
      for(ll k = j + 1; k < 4; k++) {
        vector<ll> len;
        len.push_back(dist[i][j]);
        len.push_back(dist[j][k]);
        len.push_back(dist[k][i]);
        sort(len.begin(), len.end());
        if(len[0] + len[1] == len[2]) {
          // 한 직선 위에 있지 않은 나머지 한 점
          ll A = i ^ j ^ k ^ 0 ^ 1 ^ 2 ^ 3;
          ll B, C, D;
          if(len[2] == dist[i][j]) {
            B = i;
            C = k;
            D = j;
          } else if(len[2] == dist[j][k]) {
            B = j;
            C = i;
            D = k;
          } else {
            B = k;
            C = j;
            D = i;
          }
          return validate(dist[A][B], dist[A][C], dist[A][D], dist[B][C], dist[C][D]);
        }
      }
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  for(ll i = 0; i < 4; i++) {
    for(ll j = 0; j < 4; j++) {
      cin >> dist[i][j];
    }
  }
  
  bool is_valid = true;
  ll zero_cnt = 0;
  for(ll i = 0; i < 4; i++) {
    for(ll j = i + 1; j < 4; j++) {
      for(ll k = j + 1; k < 4; k++) {
        vector<ll> len;
        len.push_back(dist[i][j]);
        len.push_back(dist[j][k]);
        len.push_back(dist[k][i]);
        sort(len.begin(), len.end());
        if(len[0] + len[1] < len[2]) is_valid = false; 
        if(len[0] + len[1] == len[2]) zero_cnt++;
      }
    }
  }

  if(!is_valid) {
    cout << "NO" << '\n';
  } else {
    if(zero_cnt == 0 || zero_cnt == 4) {
      cout << "YES" << '\n';
    } else if(zero_cnt == 1) {
      cout << (validate() ? "YES" : "NO") << '\n';
    } else {
      assert(false);
    }
  }

  return 0;
}