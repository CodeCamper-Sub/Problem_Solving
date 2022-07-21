//
//  main.cpp
//
//  Created by CodeCamper on 2022/07/11.
//

#include <iostream>
#include <vector>
#define MODULO 1000000007
typedef long long ll;
using namespace std;

struct Matrix {
  ll n;
  vector<vector<ll>> mat;
  
  Matrix(ll n): n(n) {
    mat.resize(n, vector<ll>(n, 0));
  }
  
  Matrix operator*(Matrix &r) {
    Matrix res(n);
    for(ll i = 0; i < n; i++) {
      for(ll j = 0; j < n; j++) {
        for(ll k = 0; k < n; k++) {
          res.mat[i][j] += mat[i][k] * r.mat[k][j];
        }
        res.mat[i][j] %= MODULO;
      }
    }
    return res;
  }
};

Matrix exponentiation(Matrix m, ll power) {
  if(power == 0) {
    Matrix id(m.n);
    for(ll i = 0; i < m.n; i++) id.mat[i][i] = 1;
    return id;
  }
  Matrix half = exponentiation(m, power / 2);
  return power % 2 ? half * half * m : half * half;
}

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  ll n;
  cin >> n;
  Matrix m(2);
  m.mat[0][0] = 1;
  m.mat[0][1] = 1;
  m.mat[1][0] = 1;
  m.mat[1][1] = 0;
  cout << exponentiation(m, n).mat[1][0] << '\n';
  
  
  return 0;
}

