#include "envel/envel.hh"

#include <algorithm>

namespace envel {

void GenElStr(const std::vector<std::string>& vars, std::ostream& os,
              std::function<const char*(const char*)> getenv) {
  // bool first = true;
  os << "(";
  std::ranges::for_each(vars, [&getenv, &os](const auto& var) {
    auto value = getenv(var.c_str());
    if (!value || std::strlen(value) == 0) return;
    // if (first) {
    //   first = false;
    // } else {
    //   os << " ";
    // }
    os << "\n\"" << var << "=" << value << '"';
  });
  os << "\n)\n";
}

}  // namespace envel
