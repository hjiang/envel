#include "envel/envel.hh"

#include <algorithm>

namespace envel {

void GenElStr(const std::vector<std::string>& vars, std::ostream& os,
              std::function<const char*(const char*)> getenv) {
  bool first = true;
  os << "(";
  std::ranges::for_each(vars, [&getenv, &os, &first](const auto& var) {
    auto value = getenv(var.c_str());
    if (!value) return;
    if (first) {
      first = false;
    } else {
      os << " ";
    }
    os << '"' << var << "=" << value << '"';
  });
  os << ")";
}

}  // namespace envel
