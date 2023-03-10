#include <bits/stdc++.h>
#define INF 999999999999
typedef long long ll;
using namespace std;

ll n, k, a, cumulative_sum[1001000][26];
string s;
char c;
vector<Matrix> sparse;

struct Matrix {
  vector<vector<ll>> mat;
  ll row, col;
  Matrix(ll row, ll col): row(row), col(col) {
    while(row--) {
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
          result.mat[i][j] %= s.size();
        }
      }
    }
    return result;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  cin >> n >> s >> k;

  cumulative_sum[0][s[0]-'A'] = 1;
  for(ll i = 1; i < s.size(); i++) {
    for(ll j = 0; j < 26; j++) {
      if(s[i] - 'A' == j) {
        cumulative_sum[i][j] = cumulative_sum[i-1][j] + 1;
      } else {
        cumulative_sum[i][j] = cumulative_sum[i-1][j];
      }
    }
  }

  sparse.push_back(Matrix(3, 3));
  sparse[0].mat[0][0] = 1;
  sparse[0].mat[0][1] = 1;
  sparse[0].mat[1][1] = 1;
  sparse[0].mat[1][2] = 1;
  sparse[0].mat[2][2] = 1;

  for(ll i = 2; i <= 62; i++) {
    sparse[i] = sparse[i-1] * sparse[i-1];
  }

  for(ll i = 0; i < k; i++) {
    cin >> a >> c;
    Matrix iden(3, 3);
    for(ll i = 0; i < 3; i++) iden.mat[i][i] = 1;
    
    ll cnt = a - 1;
    for(ll i = 62; i >= 0; i--) {
      if(cnt >= (1ll << i)) {
        cnt -= (1ll << i);
        iden = iden * sparse[i];
      }
    }

    Matrix result(3, 1);
    result.mat[0][0] = 0;
    result.mat[0][1] = 1;
    result.mat[0][1] = 1;

    result = iden * result;

    ll start_index = result.mat[0][0];
    if(s.size() - start_index - 1 <= a) {
      
    }
  }
  
  return 0;
}