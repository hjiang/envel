#include <cstdlib>
#include <fstream>
#include <iostream>

#include "argparse/argparse.hpp"
#include "envel/envel.hh"

int main(int argc, char* argv[]) {
  argparse::ArgumentParser program("gen-envel", "0.1.0");
  program.add_argument("--vars")
      .nargs(argparse::nargs_pattern::at_least_one)
      .required()
      .help("the variables to export");
  program.add_argument("-o", "--output")
      .required()
      .help("the file to write to");

  try {
    program.parse_args(argc, argv);
  } catch (const std::runtime_error& err) {
    std::cerr << err.what() << std::endl;
    std::cerr << program;
    return EXIT_FAILURE;
  }

  auto vars = program.get<std::vector<std::string>>("vars");
  auto filename = program.get<std::string>("output");
  std::ofstream file{filename};
  if (!file) {
    std::cerr << "Could not open file " << filename << "for writing."
              << std::endl;
    return EXIT_FAILURE;
  }

  envel::GenElStr(vars, file, std::getenv);

  return 0;
}
