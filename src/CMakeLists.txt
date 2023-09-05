add_library(envel STATIC envel.cc)
target_compile_features(envel PUBLIC cxx_std_20)
set_target_properties(envel PROPERTIES CXX_EXTENSIONS OFF)
