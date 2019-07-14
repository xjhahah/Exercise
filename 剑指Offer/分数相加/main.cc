#include <cmath>
#include <iostream>
#include <cstdio>

using std::abs;
struct Num {
  long long up, down;
};

//最大公约数
long long Gcd(long long a, long long b) { return b == 0 ? a : Gcd(b, a % b); }

//化简
Num Simplification(Num& res) {
  if (res.down < 0) {
    res.up = -res.up;
    res.down = -res.down;
  } else if (res.up == 0) {
    res.down = 1;
  } else {
    //约分
    long long n = Gcd(abs(res.up), abs(res.down));
    res.up /= n;
    res.down /= n;
  }
  return res;
}

//实现 + - * /
Num Add(Num a, Num b) {
  Num res;
  res.up = a.up * b.down + b.up * a.down;
  res.down = a.down * b.down;
  return res;
}
Num Minu(Num a, Num b) {
  Num res;
  res.up = a.up * b.down - b.up * a.down;
  res.down = a.down * b.down;
  return res;
}
Num Mul(Num a, Num b) {
  Num res;
  res.up = a.up * b.up;
  res.down = a.down * b.down;
  return res;
}
Num Div(Num a, Num b) {
  Num res;
  res.up = a.up * b.down;
  res.down = a.down * b.up;
  return res;
}

void Print(Num n) {
  n = Simplification(n);  //化简一下
  if (n.up < 0) {
    std::cout << "(";
  }
  if (n.down == 1) {  //整数
    std::cout << n.up;
  } else if (abs(n.up) > abs(n.down))  //假分数
  {
    std::cout << n.up / n.down << " " << abs(n.up) % n.down << "/" << n.down;
  } else {
    std::cout << n.up << "/" << n.down;  //真分数
  }
  if (n.up < 0) {
    std::cout << ")";
  }
}

int main() {
  Num a, b;
  scanf("%lld/%lld %lld/%lld", &a.up, &a.down, &b.up, &b.down);

  Print(a);
  std::cout << " + ";
  Print(b);
  std::cout << " = ";
  Print(Add(a, b));
  std::cout << std::endl;

  Print(a);
  std::cout << " - ";
  Print(b);
  std::cout << " = ";
  Print(Minu(a, b));
  std::cout << std::endl;

  Print(a);
  std::cout << " * ";
  Print(b);
  std::cout << " = ";
  Print(Mul(a, b));
  std::cout << std::endl;

  Print(a);
  std::cout << " / ";
  Print(b);
  std::cout << " = ";
  if (b.up == 0) {
    std::cout << "Inf" << std::endl;
  } else {
    Print(Div(a, b));
    std::cout << std::endl;
  }
  return 0;
}
