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
