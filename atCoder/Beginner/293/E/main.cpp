#include <bits/stdc++.h>
#define INF 999999999999

typedef long long ll;
using namespace std;

ll a, x, m;

struct Matrix {
    vector<vector<ll>> mat;
    ll row, col;
    Matrix(ll row, ll col): row(row), col(col) {
        for(ll i = 0; i < row; i++) {
            mat.push_back(vector<ll>(col));
            fill(mat.back().begin(), mat.back().end(), 0);
        }
    }

    Matrix operator*(const Matrix& rhs) {
        Matrix result(row, rhs.col);
        for(ll i = 0; i < row; i++) {
            for(ll j = 0; j < rhs.col; j++) {
                for(ll k = 0; k < col; k++) {
                    result.mat[i][j] += mat[i][k] * rhs.mat[k][j];
                    result.mat[i][j] %= m;
                }
            }
        }

        return result;
    }
};

vector<Matrix> sparse;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> a >> x >> m;

  sparse.push_back(Matrix(2, 2));
  sparse[0].mat[0][0] = 1;
  sparse[0].mat[0][1] = a;
  sparse[0].mat[1][1] = a;

  for(ll i = 1; i <= 62; i++) {
    sparse.push_back(sparse[i - 1] * sparse[i - 1]);
  }

  Matrix iden(2, 2);
  for(ll i = 0; i < 2; i++) iden.mat[i][i] = 1;

  ll cnt = x - 1;
  for(ll i = 62; i >= 0; i--) {
    if(cnt >= (1ll << i)) {
        cnt -= (1ll << i);
        iden = sparse[i] * iden;
    }
  }

  Matrix result(2, 1);
  result.mat[0][0] = 1;
  result.mat[1][0] = 1;

  result = iden * result;

  cout << result.mat[0][0] << '\n';
  
  return 0;
}