#include <iostream>
#include <pybind11/embed.h>
#include <pybind11/stl.h>  // necessary functionality for Pybind11 to automatically convert std::vector types 
#include <pybind11/numpy.h> // include this for direct NumPy array support (calling from module instead of py::exec)

namespace py = pybind11;

int main() {
    py::scoped_interpreter guard{}; // start the interpreter

    py::module_ np = py::module_::import("numpy");
    std::vector<int> vec = {1, 2, 3, 4, 5};
    py::array_t<int> arr(vec.size(), vec.data());

    int result = np.attr("sum")(arr).cast<int>();
    std::cout << "Sum of array: " << result << std::endl;

    return 0;
}