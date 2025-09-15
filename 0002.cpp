// clang-format -i 0002.cpp
// clang++ --std=c++23 -g 0002.cpp -o cpp_0002 && ./cpp_0002

#include <charconv>
#include <cstddef>
#include <iostream>
#include <string>
#include <system_error>
#include <vector>

int main() {
  std::vector<std::string> names{"John", "Sam", "Joe"};
  for (const auto &name : names) {
    std::cout << name << " ";
  }
  std::cout << std::endl;

  long double d{3.14L};
  std::string s{std::to_string(d)};
  std::cout << s << std::endl;

  const std::string to_parse{"   123USD"};
  std::size_t index{0};
  int int_value{std::stoi(to_parse, &index)};
  std::cout << int_value << std::endl;
  std::cout << "First non-parsed character: " << to_parse[index] << std::endl;

  // funcs in charconv
  const std::size_t buffer_size{50};
  double value1{0.314};
  std::string out(buffer_size, ' ');
  auto [ptr1,
        error1]{std::to_chars(out.data(), out.data() + out.size(), value1)};
  if (error1 == std::errc{}) {
    std::cout << out << std::endl;
  }
  double value2;
  auto [ptr2,
        error2]{std::from_chars(out.data(), out.data() + out.size(), value2)};
  if (error2 == std::errc{}) {
    if (value1 == value2) {
      std::cout << "perfect roundtrip" << std::endl;
    } else {
      std::cout << "not perfect roundtrip" << std::endl;
    }
  }

  return 0;
}
