#include <bits/stdc++.h>
#define INF 999999999999
#define MOD ll(1e6)
typedef long long ll;
using namespace std;

struct Matrix {
  vector<vector<ll>> mat;
  ll row, col;

  Matrix(ll r, ll c): row(r), col(c) {
    mat.assign(r, vector<ll>(c, 0));
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
  
  cin >> n;
  if(n == 1) {
    cout << 1 << '\n';
    return 0;
  }

  sparse.push_back(Matrix(2, 2));
  sparse[0].mat[0][0] = 1;
  sparse[0].mat[0][1] = 1;
  sparse[0].mat[1][0] = 1;
  while(sparse.size() <= 62) {
    sparse.push_back(sparse.back() * sparse.back());
  }

  Matrix result(2, 1);
  result.mat[0][0] = 1;
  result.mat[1][0] = 0;

  for(ll i = 62; i >= 0; i--) {
    if(n >= (1ll << i)) {
      n -= (1ll << i);
      result = sparse[i] * result;
    }
  }

  cout << result.mat[1][0] << '\n';
  
  return 0;
}