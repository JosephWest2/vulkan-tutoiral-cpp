#include "pipeline.hpp"
#include "device.hpp"
#include "window.hpp"

namespace MVE {
class App {
  public:
    App();
    void Run();

  private:
    MVE::Window window;
    MVE::Device device;
    MVE::Pipeline pipeline;

};
} // namespace MVE
