#include <bits/stdc++.h>
#define INF 999999999999
#define MOD 1000000007
typedef long long ll;
using namespace std;

struct Matrix {
  ll m, n;
  vector<vector<ll>> grid;

  Matrix(ll m, ll n) {
    for(ll i = 0; i < m; i++) {
      vector<ll> row = vector<ll>(n);
      fill(row.begin(), row.end(), 0);
      grid.push_back(row);
    }
    this->m = m;
    this->n = n;
  }

  Matrix operator*(const Matrix& rhs) const {
    Matrix result(this->m, rhs.n);
    for(ll i = 0; i < result.m; i++) {
      for(ll j = 0; j < result.n; j++) {
        result.grid[i][j] = 0;
        for(ll k = 0; k < this->n; k++) {
          result.grid[i][j] += this->grid[i][k] * rhs.grid[k][j];
          result.grid[i][j] %= MOD;
        }
      }
    }
    return result;
  }
};

ll n;
vector<Matrix> memo;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;

  if(n % 2) {
    cout << 0 << '\n';
    return 0;
  } else if (n == 2) {
    cout << 3 << '\n';
    return 0;
  } else if (n == 4) {
    cout << 11 << '\n';
    return 0;
  }

  n = (n - 2) / 2;

  memo.push_back(Matrix(4, 4));
  memo[0].grid[0][0] = 3;
  memo[0].grid[0][2] = 2;
  memo[0].grid[1][0] = 1;
  memo[0].grid[2][0] = 1;
  memo[0].grid[2][2] = 1;
  memo[0].grid[3][3] = 1;
  for(ll i = 1; i <= 60; i++) {
    memo.push_back(memo[i-1] * memo[i-1]);
  }

  Matrix result(4, 4);
  result.grid[0][0] = 1;
  result.grid[1][1] = 1;
  result.grid[2][2] = 1;
  result.grid[3][3] = 1;

  for(ll i = 60; i >= 0; i--) {
    if(n >= (1ll << i)) {
      n -= (1ll << i);
      result = result * memo[i];
    }
  }

  Matrix initial(4, 1);
  initial.grid[0][0] = 3;
  initial.grid[1][0] = 1;
  initial.grid[2][0] = 1;
  initial.grid[3][0] = 1;

  Matrix answer = result * initial;

  cout << answer.grid[0][0] << '\n';

  return 0;
}