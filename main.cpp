#include <iostream>
#include <pybind11/embed.h>

namespace py = pybind11;

int main() {
    py::scoped_interpreter guard{}; // start the interpreter

    py::exec(R"(
        def greet(name):
            return 'Hello, ' + name
    )");

    auto greet = py::globals()["greet"];
    std::string result = greet("World").cast<std::string>();
    std::cout << result << std::endl;

    return 0;
}