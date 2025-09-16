// clang-format -i 0001.cpp
// clang++ --std=c++23 -g 0001.cpp -o cpp_0001 && ./cpp_0001

#include <compare>
#include <cstring>
#include <iostream>
#include <string>

char *copy_string(const char *str) {
  char *result{new char[strlen(str) + 1]};

  strcpy(result, str);

  return result;
}

char *append_string(const char *str1, const char *str2, const char *str3) {
  char *result{new char[strlen(str1) + strlen(str2) + strlen(str3) + 1]};

  strcpy(result, str1);
  strcat(result, str2);
  strcat(result, str3);

  return result;
}

int main() {
  auto *dest = copy_string("hello world");

  std::cout << dest << std::endl;

  delete[] dest;

  dest = append_string("hello", " world", " helix");

  std::cout << dest << std::endl;

  delete[] dest;

  std::string my_string{"hello world"};
  std::string my_other_string{my_string};
  my_other_string[0] = 'H';

  auto result{my_string <=> my_other_string};
  if (is_gt(result)) {
    std::cout << "greater" << std::endl;
  }
  if (is_lt(result)) {
    std::cout << "less" << std::endl;
  }
  if (is_eq(result)) {
    std::cout << "equal" << std::endl;
  }
  auto result1{my_string.compare(my_other_string)};
  if (result1 > 0) {
    std::cout << "greater" << std::endl;
  }
  if (result1 < 0) {
    std::cout << "less" << std::endl;
  }
  if (result1 == 0) {
    std::cout << "equal" << std::endl;
  }

  return 0;
}
