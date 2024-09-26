#include "window.hpp"
#include <GLFW/glfw3.h>
#include <stdexcept>

namespace MVE {
Window::Window(const int window_width, const int window_height, const std::string_view &window_name) : width(window_width), height(window_height), name(window_name) { InitWindow(); }

Window::~Window() { DestroyWindow(); }

void Window::InitWindow() {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    window = glfwCreateWindow(width, height, name.c_str(), nullptr, nullptr);
}

void Window::DestroyWindow() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

void Window::CreateWindowSurface(VkInstance instance, VkSurfaceKHR *surface) {
    if (glfwCreateWindowSurface(instance, window, nullptr, surface) != VK_SUCCESS) {
        throw std::runtime_error("Failed to create window surface.");
    }
}

} // namespace MVE
