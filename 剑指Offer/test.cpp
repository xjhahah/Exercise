#include <iostream>
#include <cmath>

int monthofDay[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main() {
  int from_year, from_month, from_day;
  int to_year, to_month, to_day;
  while (std::cin >> from_year >> from_month >> from_day >> to_year >> to_month >> to_day) {
    int sum = 0;
    //for (int i = from_year,int j=from_month,int k=from_day; i <= to_year,j<=to_month,k<=to_day; ++i,++j,++k) {
    for (int i = from_year; i <= to_year - 1; ++i) {
      if ((i % 4 == 0 && i % 100 != 0) || (i % 400 == 0))
        sum += 580;
      else
        sum += 579;
    }
      for (int i = 0; i <= from_month - 1; ++i) {
        int temp = 0;
        if (i == from_month - 1)
          temp = from_day - 1;
        else
          temp = monthofDay[i];
        if (i != 1 && i != 2 && i != 4 && i != 6 && i != 10) {
          sum -= temp * 2;
        } else
          sum -= temp;
      }

      for (int i = 0; i <= to_month - 1; ++i) {
        int temp = 0;
        if (i == to_month - 1)
          temp = to_day;
        else
          temp = monthofDay[i];
        if (i != 1 && i != 2 && i != 4 && i != 6 && i != 10) {
          sum += temp * 2;
        } else
          sum += temp;
      }
    std::cout << sum << std::endl;
  }
  return 0;
}
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
/**
  蔡勒公式
  0-星期日，1-星期一，2-星期二，3-星期三，4-星期四，5-星期五，6-星期六
**/

int getDayOfWeek(int year, int month, int day) {
  if (month == 1 || month == 2)  //判断month是否为1或2　
  {
    year--;
    month += 12;
  }
  int c = year / 100;
  int y = year - c * 100;
  int week = (c / 4) - 2 * c + (y + y / 4) + (13 * (month + 1) / 5) + day - 1;
  while (week < 0) {
    week += 7;
  }
  week %= 7;
  return week;
}

int main() {
  int Days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int year, month, day, days;
  while (scanf("%d%d", &year, &month) != EOF) {
    days = Days[month];
    int weeks[6][7] = {0};
    int weekI = 0;
    for (int i = 1; i < days + 1; i++) {
      day = i;
      int week = getDayOfWeek(year, month, day);
      weeks[weekI][week] = i;
      if (week == 0) weekI++;
    }
    printf("星期一\t星期二\t星期三\t星期四\t星期五\t星期六\t星期日\n");
    for (int l = 0; l < 6; l++) {
      for (int m = 0; m < 7; m++) {
        if (weeks[l][(m + 1) % 7] > 0)
          printf("%d\t", weeks[l][(m + 1) % 7]);
        else
          printf("\t");
      }
      printf("\n");
    }
    printf("\n");
  }
  return 0;
}
#include <cstdio>
#include <iostream>

int day_of_week(int year, int month, int day) {
  if (month == 1 || month == 2) {
    month += 12;
    year -= 1;
  }
  int century = year / 100;
  year = year % 100;
  int week = year + (year / 4) + (century / 4) - 2 * century + 26 * (month + 1) / 10 + day - 1;
  week = (week % 7 + 7) % 7;
  if (week == 0) {
    week = 7;
  }
  return week;
}
int main() {
  int Days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  int year = 0, month = 0, day = 0, days = 0;
  while (scanf_s("%d%d", &year, &month) != EOF) {
    days = Days[month];
    int weeks[6][7] = {0};
    int weekI = 0;
    for (int i = 1; i < days + 1; i++) {
      day = i;
      int week = day_of_week(year, month, day);
      weeks[weekI][week] = i;
      if (week == 0) weekI++;
    }
    printf("星期一\t星期二\t星期三\t星期四\t星期五\t星期六\t星期日\n");
    for (int l = 0; l < 6; l++) {
      for (int m = 0; m < 7; m++) {
        if (weeks[l][(m + 1) % 7] > 0)
          printf("%d\t", weeks[l][(m + 1) % 7]);
        else
          printf("\t");
      }
      printf("\n");
    }
    printf("\n");
  }
  return 0;
}

int getFirstUnFormedNum(vector<int> arr, int len) {
  int i, j;
  int min = arr[0], max = 0;

  for (auto& e : arr) {
    if (e < min) min = e;
    max += e;
  }
  vector<int> dp(max + 1, 0);
  for (i = 0; i < len; i++)
    for (j = max; j >= arr[i]; j--) {
      if (dp[j - arr[i]] + arr[i] > dp[j])
        dp[j] = dp[j - arr[i]] + arr[i];
      else
        dp[j] = dp[j];
    }
  for (i = min; i <= max; i++) {
    if (i != dp[i]) return i;
  }
  return i;
}

class Solution {
 public:
  /**
   *  奇数位上都是奇数或者偶数位上都是偶数
   *  输入：数组arr，长度大于2
   *  len：arr的长度
   *  将arr调整成奇数位上都是奇数或者偶数位上都是偶数
   */
  void oddInOddEvenInEven(std::vector<int>& arr, int len) {
    int i = 0;
    int j = 1;
    while (i < len && j < len) {
      if (!(arr[i] & 1)) {
        i += 2;
      } else if (arr[j] & j) {
        j += 2;
      } else {
        std::swap(arr[i], arr[j]);
      }
    }
  }
};

// 以下用于测试
void print_vector(std::vector<int>& v) {
  std::for_each(v.begin(), v.end(), [](int i) { std::cout << i << ' '; });
  std::cout << std::endl;
}
int main() 
{
  Solution s;
  std::vector<int> v1{1, 2, 3, 4};
  s.oddInOddEvenInEven(v1, v1.size());
  print_vector(v1);
  std::vector<int> v2{7, 7, 9, 5, 1, 6, 7, 9, 3, 2, 6};
  s.oddInOddEvenInEven(v2, v2.size());
  print_vector(v2);
  return 0;
}
#endif