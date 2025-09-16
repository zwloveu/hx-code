// clang-format -i 0003.cpp
// clang++ --std=c++23 -g 0003.cpp -o cpp_0003 && ./cpp_0003

#include <iostream>
#include <string_view>

std::string extract_extension(std::string_view);

int main() {

  const std::string filename{R"(c:\temp\my file.ext)"};
  auto ext = extract_extension(filename);
  std::cout << ext << std::endl;

  const char *const c_str{R"(c:\temp\my file.ext)"};
  std::string ext1 = extract_extension(c_str);
  std::cout << ext1 << std::endl;

  return 0;
}

std::string extract_extension(std::string_view filename) {
  return std::string{filename.substr(filename.rfind('.'))};
}
