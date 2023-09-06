#include "envel/envel.hh"

#include <algorithm>

namespace envel {

void GenElStr(const std::vector<std::string>& vars, std::ostream& os,
              std::function<const char*(const char*)> getenv) {
  size_t i = 0;
  size_t size = vars.size();
  os << "(";
  std::ranges::for_each(vars, [&getenv, &os, &i, size](const auto& var) {
    os << '"' << var << "=" << getenv(var.c_str()) << '"';
    if (i++ < size - 1) {
      os << " ";
    }
  });
  os << ")";
}

}  // namespace envel
