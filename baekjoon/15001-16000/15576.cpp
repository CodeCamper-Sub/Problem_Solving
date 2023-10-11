#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

const double PI = acos(-1);
typedef complex<double> cpx;

void FFT(vector<cpx> &v, bool inv) {
  ll S = v.size();

  for(ll i = 1, j = 0; i < S; i++) {
    ll bit = S / 2;

    while(j >= bit) {
      j -= bit;
      bit /= 2;
    }
    j += bit;

    if(i < j)
      swap(v[i], v[j]);
  }

  for(ll k = 1; k < S; k *= 2) {
    double angle = (inv ? PI / k : -PI / k);
    cpx w(cos(angle), sin(angle));

    for(ll i = 0; i < S; i += k * 2) {
      cpx z(1, 0);

      for(ll j = 0; j < k; j++) {
        cpx even = v[i + j];
        cpx odd = v[i + j + k];

        v[i + j] = even + z * odd;
        v[i + j + k] = even - z * odd;

        z *= w;
      }
    }
  }

  if(inv) {
    for(ll i = 0; i < S; i++)
      v[i] /= S;
  }
}

vector<ll> mul(vector<ll> &v, vector<ll> &u) {
  vector<cpx> vc(v.begin(), v.end());
  vector<cpx> uc(u.begin(), u.end());

  ll S = 2;
  while (S < v.size() + u.size())
    S *= 2;

  vc.resize(S);
  FFT(vc, false);

  uc.resize(S);
  FFT(uc, false);

  for(ll i = 0; i < S; i++)
    vc[i] *= uc[i];
  FFT(vc, true);

  vector<ll> w(S);
  for(ll i = 0; i < S; i++) {
    w[i] = round(vc[i].real());
  }
  return w;
}

string sa, sb;
vector<ll> a, b;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> sa >> sb;
  if(sa == "0" || sb == "0") {
    cout << 0 << '\n';
    return 0;
  }
  for(char c: sa) {
    a.push_back(c - '0');
  }
  for(char c: sb) {
    b.push_back(c - '0');
  }
  
  // reverse(a.begin(), a.end());
  // reverse(b.begin(), b.end());
  vector<ll> result = mul(a, b);

  for(ll i = 0; i < result.size(); i++) {
    if(result[i] > 9) {
      if(i < ll(result.size()) - 1) {
        result[i + 1] += result[i] / 10;
        result[i] %= 10;
      } else {
        result.push_back(result[i] / 10);
        result[i] %= 10;
      }
    }
  }

  while(result.size() && result.back() == 0) result.pop_back();

  while(result.size()) {
    cout << result.back();
    result.pop_back();
  }
  
  
  return 0;
}