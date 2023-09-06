#include "envel/envel.hh"

#include <cstring>
#include <sstream>
#include <string>
#include <vector>

#include "catch2/catch_test_macros.hpp"

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

TEST_CASE("Nonexistent env vars are not included", "[envel]") {
  std::vector<std::string> vars = {"HOME", "USER"};
  std::ostringstream ss;
  GenElStr(vars, ss, [](const char* var) -> const char* {
    if (std::strcmp("HOME", var) == 0) {
      return "/home";
    }
    return nullptr;
  });
  REQUIRE(ss.str() == "(\"HOME=/home\")");
}

TEST_CASE("Empty env vars are not included", "[envel]") {
  std::vector<std::string> vars = {"HOME", "USER"};
  std::ostringstream ss;
  GenElStr(vars, ss, [](const char* var) -> const char* {
    if (std::strcmp("HOME", var) == 0) {
      return "/home";
    }
    return "";
  });
  REQUIRE(ss.str() == "(\"HOME=/home\")");
}

}  // namespace envel
