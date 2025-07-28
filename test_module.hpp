module;

#include <string>

export module test_cpp_module;

export namespace test_cpp_module {

  std::string hello_world_cpp() {
    return "Hello world, from C++";
  }
}
