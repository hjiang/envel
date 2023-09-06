#include "envel/envel.hh"

#include <catch2/catch_test_macros.hpp>
#include <cstring>
#include <sstream>
#include <string>
#include <vector>

namespace envel {

TEST_CASE("Existent env vars are included", "[envel]") {
  std::vector<std::string> vars = {"HOME", "USER"};
  std::ostringstream ss;
  GenElStr(vars, ss, [](const char* var) -> const char* {
    if (std::strcmp("HOME", var) == 0) {
      return "/home";
    } else if (std::strcmp("USER", var) == 0) {
      return "user";
    }
    return nullptr;
  });
  REQUIRE(ss.str() == "(\"HOME=/home\" \"USER=user\")");
}

}  // namespace envel
