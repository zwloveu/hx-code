// clang-format -i 0004.cpp
// clang++ --std=c++23 -g 0004.cpp -o cpp_0004 && ./cpp_0004

#include <cstdlib>
#include <iostream>

class LambdaNoCapture
{
public:
  int operator()(int a, int b) { return a + b; }
};

class LambdaCaptureRef
{
private:
  int &captured;

public:
  LambdaCaptureRef(int &x) : captured{x} {}

  void operator()(int new_value) { captured = new_value; }
};

struct Test
{
  int a;
  int b;
};

int main()
{

  Test a{};
  std::cout << a.a << std::endl;

  LambdaNoCapture adder;
  int adder_result = adder(5, 3);
  std::cout << "5 + 3 = " << adder_result << std::endl;

  auto add_lambda = [](int a, int b) -> int
  { return a + b; };
  std::cout << "5 + 3 = " << add_lambda(5, 3) << std::endl;

  int old_value = 5;
  int &ref_old_value = old_value;
  LambdaCaptureRef updater(ref_old_value);
  updater(15);
  std::cout << old_value << std::endl;

  old_value = 5;
  auto update_lambda = [&ref_old_value](int new_value)
  {
    ref_old_value = new_value;
  };
  update_lambda(15);
  std::cout << old_value << std::endl;

  return 0;
}
