add_library(envel STATIC envel.cc)
set_default_props(envel)

add_executable(gen-envel gen-envel.cc)
set_default_props(gen-envel)
target_link_libraries(gen-envel envel argparse)

