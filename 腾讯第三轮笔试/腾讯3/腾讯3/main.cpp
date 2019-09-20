#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;


  /*
int main() {
  int t;
  while (cin >> t) {
    while (t--) {
      string s;
      int len;
      cin >> len;
      cin >> s;
      if (len < 11) {
        cout << "NO" << endl;
      } else {
        bool flag = false;
        for (int i = 0; i < len - 10; i++) {
          if (s[i] == '8') {
            flag = true;
            break;
          }
        }
        if (flag) {
          cout << "YES" << endl;
        } else {
          cout << "NO" << endl;
        }
      }
    }
    return 0;
  }
}


//两两配对
int main() {
  int n;
  while (std::cin >> n) {
    vector<std::pair<int, int>> v(n);
    for (int i = 0; i < n;++i) {
      std::cin >> v[i].second >> v[i].first;
    }
    std::sort(v.begin(), v.end(),
         [](const std::pair<int, int> p1, const std::pair<int, int> p2) {
           return p1.first < p2.first;
         });
    int begin = 0;
    int end = v.size() - 1;
    int minTime = 0;
    while (begin < end) {
      minTime = std::max(v[begin].first + v[end].first, minTime);
      v[begin].second--;
      v[end].second--;
      if (0 == v[begin].second) {
        begin++;
      }
      if (0 == v[end].second) {
        end--;
      }
    }
    std::cout << minTime << std::endl;
  }
  return 0;
}


//战力分组  --- 只能过部分
int main() {
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    vector<int> v(n, 0);
    int sum = 0;
    for (int i = 0; i < n; i++) {
      std::cin >> v[i];
      sum += v[i];
    }
    int m = sum / 2;
    vector<vector<int>> vv(n + 1, vector<int>(m + 1));
    for (int i = 0; i < vv[0].size(); i++) {
      vv[0][i] = 0;
    }
    for (int i = 0; i < v.size(); i++) {
      vv[i][0] = 0;
    }
    for (int i = 1; i < n + 1; i++) {
      for (int j = 1; j < m + 1; j++) {
        vv[i][j] = vv[i - 1][j];
        if (j - v[i - 1] >= 0 &&
            vv[i - 1][j - v[i - 1]] + v[i - 1] > vv[i][j]) {
          vv[i][j] = vv[i - 1][j - v[i - 1]] + v[i - 1];
        }
      }
    }
    std::cout << vv[n][m] << ' ' << sum - vv[n][m] << std::endl;
  }
  return 0;
}
*/

//第四题
#include <iostream>
#include <vector>

using std::vector;

int main() {
  int n, k;
  while (std::cin >> n >> k) {
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
      std::cin >> v[i];
    }
    sort(v.begin(), v.end());
    int t = 0;
    int num = 0;
    for (int i = 0; i < v.size(); i++) {
      if (v[i] - t <= 0) continue;
      std::cout << v[i] - t << std::endl;
      t += v[i] - t;
      num++;
      if (num == k) break;
    }
    while (num < k) {
      num++;
      std::cout << 0 << std::endl;
    }
  }
  return 0;
}
