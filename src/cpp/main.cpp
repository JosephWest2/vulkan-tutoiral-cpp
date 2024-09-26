#include "app.hpp"
#include <iostream>

int main() {
    MVE::App app = MVE::App();
    try {
        app.Run();
    } catch(const std::exception e) {
        std::cerr << e.what() << std::endl;
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}
