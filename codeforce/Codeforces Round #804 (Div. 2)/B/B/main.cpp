//
//  main.cpp
//  B
//
//  Created by CodeCamper on 2022/07/06.
//

#include <iostream>
using namespace std;

int matrix[55][55];
int t, n, m;

void draw_matrix() {
  for(int i = 1; i <= 50; i++) {
    if(i % 4 == 1 || i % 4 == 0) {
      matrix[i][1] = 1;
      for(int j = 2; j <= 50; j += 4) {
        matrix[i][j] = 0;
        matrix[i][j+1] = 0;
        matrix[i][j+2] = 1;
        matrix[i][j+3] = 1;
      }
    } else {
      matrix[i][1] = 0;
      for(int j = 2; j <= 50; j += 4) {
        matrix[i][j] = 1;
        matrix[i][j+1] = 1;
        matrix[i][j+2] = 0;
        matrix[i][j+3] = 0;
      }
    }
  }
}

int main(int argc, const char * argv[]) {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  draw_matrix();
  cin >> t;
  while(t--) {
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
      for(int j = 1; j <= m; j++) {
        cout << matrix[i][j] << " ";
      }
      cout << '\n';
    }
  }
  return 0;
}
