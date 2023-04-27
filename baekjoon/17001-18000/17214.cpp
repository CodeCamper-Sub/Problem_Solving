#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

string s;

void solve() {
  ll k = s.size() - 1;
  while (k >= 0 && s[k] != '+' && s[k] != '-')
    k--;
  if(k > 0) {
    string left = s.substr(0, k);
    string right = s.substr(k + 1);
    if (left.find('x') != string::npos) {
      ll coefficient = stoi(left.substr(0, left.find('x')));
      ll cst = stoi(right);
      coefficient /= 2;
      if (coefficient == -1) {
        cout << '-';
      } else if (coefficient != 1) {
        cout << coefficient;
      }
      cout << "xx";

      if (cst != 0) {
        cout << s[k];

        if (cst == -1) {
          cout << '-';
        } else if (cst != 1) {
          cout << cst;
        }
        cout << 'x';
      }
    } else {
      ll coefficient = stoi(right.substr(0, right.find('x')));
      ll cst = stoi(left);

      if (cst != 0) {
        if (cst == -1) {
          cout << '-';
        } else if (cst != 1) {
          cout << cst;
        }
        cout << 'x';
      }

      if (cst != 0 || s[k] != '+') {
        cout << s[k];
      }

      coefficient /= 2;
      if (coefficient == -1) {
        cout << '-';
      } else if (coefficient != 1) {
        cout << coefficient;
      }
      cout << "xx";
    }

    cout << "+W\n";
  } else {
    if(s.find('x') != string::npos) {
      // 4x, -2x 등
      ll coefficient = stoi(s.substr(0, s.find('x')));

      coefficient /= 2;
      if (coefficient == -1) {
        cout << '-';
      } else if (coefficient != 1) {
        cout << coefficient;
      }
      cout << "xx";

      cout << "+W\n";
    } else {
      // 3, -2, 9 등
      ll cst = stoi(s);
      if (cst != 0) {
        if (cst == -1) {
          cout << '-';
        } else if (cst != 1) {
          cout << cst;
        }
        cout << 'x';

        cout << "+W\n";
      } else {
        cout << "W\n";
      }
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> s;
  solve();
}