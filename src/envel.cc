#include "envel/envel.hh"

#include <algorithm>

namespace envel {

void GenElStr(const std::vector<std::string>& vars, std::ostream& os,
              std::function<const char*(const char*)> getenv) {
  std::ranges::for_each(vars, [&getenv, &os](const auto& var) {
    os << '"' << var << "=" << getenv(var.c_str()) << '"';
  });
}

}  // namespace envel
