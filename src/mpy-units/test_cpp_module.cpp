module;

#include <string>

// #include <mp-units/systems/si.h>


export module test_cpp_module;

export namespace test_cpp_module {

  std::string hello_world_cpp() {
    return "Hello world, from C++";
  }
}
