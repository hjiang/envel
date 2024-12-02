#include "envel/envel.hh"

#include <algorithm>
#include <cstring>

namespace envel {

void GenElStr(const std::vector<std::string>& vars, std::ostream& os,
              std::function<const char*(const char*)> getenv) {
  os << "(";
  std::ranges::for_each(vars, [&getenv, &os](const auto& var) {
    auto value = getenv(var.c_str());
    if (!value || std::strlen(value) == 0) return;
    os << "\n\"" << var << "=" << value << '"';
  });
  os << "\n)\n";
}

}  // namespace envel
