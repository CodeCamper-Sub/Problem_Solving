#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
#define MOD ll(1e9+7)
using ll = long long;
using namespace std;
template<class T>
using min_heap = priority_queue<T, vector<T>, greater<T>>;

struct Matrix {
  ll row, col;
  vector<vector<ll>> mat;
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

ll d;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> d;
  
  Matrix ori(1, 8);
  ori.mat[0][0] = 1;

  vector<Matrix> v;
  v.push_back(Matrix(8, 8));
  v[0].mat[0] = {0, 1, 1, 0, 0, 0, 0, 0};
  v[0].mat[1] = {1, 0, 1, 1, 0, 0, 0, 0};
  v[0].mat[2] = {1, 1, 0, 1, 1, 0, 0, 0};
  v[0].mat[3] = {0, 1, 1, 0, 1, 1, 0, 0};
  v[0].mat[4] = {0, 0, 1, 1, 0, 1, 0, 1};
  v[0].mat[5] = {0, 0, 0, 1, 1, 0, 1, 0};
  v[0].mat[6] = {0, 0, 0, 0, 0, 1, 0, 1};
  v[0].mat[7] = {0, 0, 0, 0, 1, 0, 1, 0};
  while(v.size() < 70) v.push_back(v.back() * v.back());

  for(ll i = 62; i >= 0; i--) {
    if(d >= (1ll << i)) {
      d -= (1ll << i);
      ori = ori * v[i];
    }
  }

  cout << ori.mat[0][0] << '\n';
  
  return 0;
}