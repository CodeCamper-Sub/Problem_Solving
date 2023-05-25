#include <bits/stdc++.h>
#define INF (__LONG_LONG_MAX__ / 3)
typedef long long ll;
using namespace std;

ll n;

vector<ll> power_of_10;
vector<vector<ll>> possible_digits;
vector<vector<char>> grid;
vector<vector<char>> num[10];

vector<char> num_to_vec(ll n) {
  vector<char> result;
  while(n) {
    result.push_back(n % 2 ? '#' : '.');
    n /= 2;
  }
  while(result.size() < 3) result.push_back('.');
  reverse(result.begin(), result.end());
  return result;
}

void init() {
  for(ll i = 0; i < 10; i++) num[i].resize(5);

  // 0
  num[0][0] = num_to_vec(7); // {'#', '#', '#'};
  num[0][1] = num_to_vec(5); // {'#', '.', '#'};
  num[0][2] = num_to_vec(5);
  num[0][3] = num_to_vec(5);
  num[0][4] = num_to_vec(7);

  // 1
  num[1][0] = num_to_vec(1);
  num[1][1] = num_to_vec(1);
  num[1][2] = num_to_vec(1);
  num[1][3] = num_to_vec(1);
  num[1][4] = num_to_vec(1);

  // 2
  num[2][0] = num_to_vec(7);
  num[2][1] = num_to_vec(1);
  num[2][2] = num_to_vec(7);
  num[2][3] = num_to_vec(4);
  num[2][4] = num_to_vec(7);

  // 3
  num[3][0] = num_to_vec(7);
  num[3][1] = num_to_vec(1);
  num[3][2] = num_to_vec(7);
  num[3][3] = num_to_vec(1);
  num[3][4] = num_to_vec(7);

  // 4/
  num[4][0] = num_to_vec(5);
  num[4][1] = num_to_vec(5);
  num[4][2] = num_to_vec(7);
  num[4][3] = num_to_vec(1);
  num[4][4] = num_to_vec(1);

  // 5
  num[5][0] = num_to_vec(7);
  num[5][1] = num_to_vec(4);
  num[5][2] = num_to_vec(7);
  num[5][3] = num_to_vec(1);
  num[5][4] = num_to_vec(7);

  // 6
  num[6][0] = num_to_vec(7);
  num[6][1] = num_to_vec(4);
  num[6][2] = num_to_vec(7);
  num[6][3] = num_to_vec(5);
  num[6][4] = num_to_vec(7);

  // 7
  num[7][0] = num_to_vec(7);
  num[7][1] = num_to_vec(1);
  num[7][2] = num_to_vec(1);
  num[7][3] = num_to_vec(1);
  num[7][4] = num_to_vec(1);

  // 8
  num[8][0] = num_to_vec(7);
  num[8][1] = num_to_vec(5);
  num[8][2] = num_to_vec(7);
  num[8][3] = num_to_vec(5);
  num[8][4] = num_to_vec(7);

  // 9
  num[9][0] = num_to_vec(7);
  num[9][1] = num_to_vec(5);
  num[9][2] = num_to_vec(7);
  num[9][3] = num_to_vec(1);
  num[9][4] = num_to_vec(7);
}

bool is_possible(ll l, ll n) {
  for(ll i = 0; i < 5; i++) {
    for(ll j = 0; j < 3; j++) {
      if(num[n][i][j] == '.' && grid[i][4 * l + j] == '#') return false;
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  init();

  cin >> n;
  power_of_10.push_back(1);
  while(power_of_10.size() <= n) {
    power_of_10.push_back(power_of_10.back() * 10);
  }
  grid.assign(5, vector<char>(4 * n - 1));
  for(ll i = 0; i < 5; i++) {
    for(ll j = 0; j < 4 * n - 1; j++) {
      cin >> grid[i][j];
    }
  }

  possible_digits.resize(n);
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < 10; j++) {
      if(is_possible(i, j)) {
        possible_digits[i].push_back(j);
      }
    }
  }

  ll sum = 0;
  ll cnt = 0;
  for(ll i = 0; i < n; i++) {
    if(i == 0) cnt = possible_digits[i].size();
    else cnt *= possible_digits[i].size();
  }

  if(cnt == 0) {
    cout << -1 << '\n';
    return 0;
  }

  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < possible_digits[i].size(); j++) {
      sum += possible_digits[i][j] * (cnt / possible_digits[i].size()) * power_of_10[n - 1 - i];
    }
  }

  cout << fixed;
  cout.precision(8);

  cout << double(sum) / double(cnt) << '\n';
  
  return 0;
}