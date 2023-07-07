#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;

vector<ll> k;
ll n;

ll power(ll a, ll b) {
  if (b == 0)
    return 1;
  ll tmp = power(a, b / 2);
  if (b % 2)
    return tmp * tmp * a;
  else
    return tmp * tmp;
}

ll two_to_ten(const vector<ll> &k) {
  ll result = 0;
  ll pow_2 = 1;
  for (ll i = 0; i < k.size(); i++) {
    result += k[k.size() - 1 - i] * pow_2;
    pow_2 *= 2;
  }
  return result;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  ll _n = n;
  while (_n) {
    k.push_back(_n % 2);
    _n /= 2;
  }
  reverse(k.begin(), k.end());
  bool is_valid = false;
  for (ll i = 1; i < k.size(); i++) {
    if (k[k.size() - 1 - i] == 1 && k[k.size() - i] == 0) {
      is_valid = true;
      vector<ll> answer = k;
      answer[k.size() - i] = 1;
      answer[k.size() - 1 - i] = 0;
      while (true) {
        bool cant_move = true;
        for (ll j = k.size() - i; j < k.size() - 1; j++) {
          if (answer[j] == 0 && answer[j + 1] == 1) {
            swap(answer[j], answer[j + 1]);
            cant_move = false;
          }
        }
        if (cant_move)
          break;
      }

      cout << two_to_ten(answer) << ' ';
      break;
    }
  }
  if (!is_valid) {
    cout << 0 << ' ';
  }
  for (ll i = 0; i < k.size(); i++) {
    if (i == k.size() - 1 ||
        k[k.size() - 1 - i] == 1 && k[k.size() - 2 - i] == 0) {
      vector<ll> answer = k;
      if (i < k.size() - 1) {
        swap(answer[k.size() - 1 - i], answer[k.size() - 2 - i]);
        while (true) {
          bool cant_move = true;
          for (ll j = k.size() - 1; j > k.size() - 1 - i; j--) {
            if (answer[j] == 0 && answer[j - 1] == 1) {
              swap(answer[j], answer[j - 1]);
              cant_move = false;
            }
          }
          if (cant_move)
            break;
        }
      } else {
        answer[0] = 0;
        answer.insert(answer.begin(), 1);
        while (true) {
          bool cant_move = true;
          for (ll j = answer.size() - 1; j > 1; j--) {
            if (answer[j] == 0 && answer[j - 1] == 1) {
              swap(answer[j], answer[j - 1]);
              cant_move = false;
            }
          }
          if (cant_move)
            break;
        }
      }
      cout << two_to_ten(answer) << ' ';
      break;
    }
  }

  return 0;
}