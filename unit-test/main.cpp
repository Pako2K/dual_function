#include <dual_function.h>

#include <iostream>

int main() {
  using namespace utils;

  std::function<int(double, bool)> f1{ [](double d, bool b) {return static_cast<int>(d * b); } };
  std::function<int(double, bool)> f2{ [](double d, bool b) {return 0; } };

  DualFunction<int(double, bool)> myFn(f1, f2);

  std::cout << myFn(3.5, true) << std::endl;

  myFn.enableSecond();

  std::cout << myFn(3.5, true) << std::endl;
  std::cout << myFn.isFirstFn() << std::endl;

  myFn.switchFn();

  std::cout << myFn(31.5, true) << std::endl;
  std::cout << myFn.isFirstFn() << std::endl;

  std::function<int(double, bool)> f3{ [](double d, bool b) {return static_cast<int>(d * b); } };
  std::function<int(double, bool)> f4{ [](double d, bool b) {throw std::exception("Disabled!"); return 0; } };

  DualFunction<int(double, bool)> mySwitch(f3, f4);
  std::cout << mySwitch(3.5, true) << std::endl;

  mySwitch.enableSecond();
  try {
    std::cout << mySwitch(3.5, true) << std::endl;
  }
  catch (std::exception& e) {
    std::cout << e.what() << std::endl;
  }

}