#include "app.hpp"
#include <iostream>

namespace MVE {
App::App()
    : window(500, 500, "Vulkan Engine Test"), device(window),
      pipeline(device, MVE::Pipeline::DefaultPipelineConfigInfo(500, 500), "./shaders/simple_shader.vert.spv", "./shaders/simple_shader.frag.spv") {
    std::cerr << "App Created" << std::endl;
}
void App::Run() {
    while (!window.ShouldClose()) {
        glfwPollEvents();
    }
}
} // namespace MVE
