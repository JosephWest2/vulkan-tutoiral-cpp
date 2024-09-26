#pragma once

#include <string>
#include <string_view>
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

namespace MVE {
class Window {
  public:
    Window(const int window_width, const int window_height, const std::string_view &window_name);
    ~Window();
    inline bool ShouldClose() { return glfwWindowShouldClose(window); }
    void CreateWindowSurface(VkInstance instance, VkSurfaceKHR *surface);

    Window(const Window &) = delete;
    Window &operator=(const Window &) = delete;
    Window(Window &&) = default;
    Window &operator=(Window &&) = default;

  private:
    int height;
    int width;
    std::string name;
    GLFWwindow *window;

    void InitWindow();
    void DestroyWindow();
};
} // namespace MVE
