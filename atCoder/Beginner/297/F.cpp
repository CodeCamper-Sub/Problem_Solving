#include <bits/stdc++.h>
#define INF 999999999999
#define MOD 998244353
typedef long long ll;
using namespace std;

ll h, w, k;
vector<ll> fact;

ll power(ll a, ll b) {
  if(b == 0) return 1;
  else if(b == 1) return a;
  ll temp = power(a, b / 2);
  if(b % 2 == 0) {
    return temp * temp % MOD;
  } else {
    return temp * temp % MOD * a % MOD;
  }
}

ll mod_inv(ll a) {
  return power(a, MOD - 2);
}

ll combination(ll n, ll r) {
  return fact[n] * mod_inv(fact[n - r] * fact[r] % MOD) % MOD;
}

ll get_remainder_cnt(ll a, ll b) { //a가 세로, b가 가로
  ll result = 0;
  // 위 아래 한줄 빼고 고르기
  if(a * b - b >= k) {
    result += 2 * combination(a * b - b, k);
  }

  // 왼쪽 오른쪽 한줄 빼고 고르기
  if(a * b - a >= k) {
    result += 2 * combination(a * b - a, k);
  }

  // 가로 한줄 세로 한줄 빼고 고르
  if(a * b - a - b + 1 >= k) {
    result -= 4 * combination(a * b - a - b + 1, k);
  }

  // 가로 두 줄 빼고 고르기
  if(a * b - 2 * b >= k) {
    result -= combination(a * b - 2 * b, k);
  }

  // 세로 두 줄 빼고 고르기
  if(a * b - 2 * a >= k) {
    result -= combination(a * b - 2 * a, k);
  }

  // 가로 두 줄 세로 한 줄 빼고 고르기
  if(a * b - 2 * b - a + 2 >= k) {
    result += 2 * combination(a * b - 2 * b - a + 2, k);
  }

  // 세로 두 줄 가로 한 줄 빼고 고르기
  if(a * b - 2 * a - b + 2 >= k) {
    result += 2 * combination(a * b - 2 * a - b + 2, k);
  }

  // 가로 세로 두 줄 씩 다 빼고 고르기
  if(a * b - 2 * a - 2 * b + 4 >= k) {
    result -= combination(a * b - 2 * a - 2 * b + 4, k);
  }

  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  fact.push_back(1);
  for(ll i = 1; i <= 1000100; i++) {
    fact.push_back(fact[i - 1] * i % MOD);
  }

  cin >> h >> w >> k;
  if(k == 1) {
    cout << 1 << '\n';
    return 0;
  }
  ll divdend = 0;
  for(ll i = k; i <= h * w; i++) {
    // 넓이가 i인 사각형
    vector<ll> dividers; // i의 약수들
    for(ll j = 1; j * j <= i; j++) {
      if(i % j) continue;
      dividers.push_back(j);
      if(j != i / j) {
        dividers.push_back(i / j);
      }
    }
    for(ll a: dividers) {
      ll b = i / a;
      // a 높이 b 가로
      if(a > h || b > w) continue;
      ll s_cnt = (h - a + 1) * (w - b + 1);
      ll all = combination(i, k);
      // 포함 / 배제
      ll remainder_cnt = get_remainder_cnt(a, b);
      divdend += i * s_cnt % MOD * (all - remainder_cnt) % MOD;
      divdend %= MOD;
    }
  }

  ll divider = combination(h * w, k);
  cout << divdend * mod_inv(divider) % MOD << '\n';
  
  return 0;
}