
#include <iostream>
#include <iomanip>

template<int x, int y> struct mul {
  static void print() {
    std::cout << x << " * " << y << " = " << std::setw(2) << x * y << ", ";
    mul<x, y + 1>::print();
  }
};

template<int x> struct mul<x, 9> {
  static void print() {
    std::cout << x << " * 9" << " = " << std::setw(2) << x * 9 << '\n';
  }
};

template<int x> struct mul2 {
  static void print() {
    mul<x, x>::print();
    mul2<x + 1>::print();
  }
};

template<> struct mul2<9> {
  static void print() {
    mul<9, 9>::print();
  }
};

int main() {
  mul2<1>::print();
  return 0;
}



