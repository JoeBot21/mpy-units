module;

#include <string>

#include <mp-units/systems/si.h>


export module cpp_module;

export namespace cpp_module {

  std::string hello_world_cpp() {
    return "Hello world, from C++";
  }
}
