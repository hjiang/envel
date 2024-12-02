#ifndef ENVEL_ENVEL_HH
#define ENVEL_ENVEL_HH

#include <cstdlib>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

namespace envel {

void GenElStr(const std::vector<std::string>& vars,
              std::ostream& os = std::cout,
              std::function<const char*(const char*)> getenv = std::getenv);

}

#endif  // ENVEL_ENVEL_HH
