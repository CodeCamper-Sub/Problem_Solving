#include <bits/stdc++.h>
#define INF 999999999999
#define MOD ll(1e9 + 7)
typedef long long ll;
using namespace std;

struct Matrix {
  vector<vector<ll>> mat;
  ll row, col;

  Matrix(ll row, ll col): row(row), col(col) {
    mat.assign(row, vector<ll>(col, 0));
  }

  Matrix operator*(const Matrix& rhs) {
    Matrix result(row, rhs.col);
    for(ll i = 0; i < row; i++) {
      for(ll j = 0; j < rhs.col; j++) {
        for(ll k = 0; k < col; k++) {
          result.mat[i][j] += mat[i][k] * rhs.mat[k][j];
          result.mat[i][j] %= MOD;
        }
      }
    }
    return result;
  }
};

ll n;
vector<Matrix> sparse;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  sparse.push_back(Matrix(3, 3));
  sparse[0].mat[0][1] = 1;
  sparse[0].mat[0][2] = 1;
  sparse[0].mat[1][0] = 1;
  sparse[0].mat[1][2] = 1;
  sparse[0].mat[2][0] = 1;
  sparse[0].mat[2][1] = 1;
  sparse[0].mat[2][2] = 1;

  for(ll i = 1; i <= 62; i++) {
    sparse.push_back(sparse.back() * sparse.back());
  }

  cin >> n;
  n -= 1;
  Matrix result(3, 1);
  result.mat[0][0] = 1;
  result.mat[1][0] = 1;
  result.mat[2][0] = 1;

  for(ll i = 62; i >= 0; i--) {
    if(n >= (1ll << i)) {
      n -= (1ll << i);
      result = sparse[i] * result;
    }
  }

  ll answer = result.mat[0][0] + result.mat[1][0] + result.mat[2][0];
  answer %= MOD;
  
  cout << answer << '\n';
  
  return 0;
}