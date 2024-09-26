#pragma once

#include "device.hpp"
#include <string_view>
#include <vector>

namespace MVE {

struct PipelineConfigInfo {
    VkPipelineInputAssemblyStateCreateInfo input_assembly_info;
    VkViewport viewport;
    VkRect2D scissor;
    VkPipelineViewportStateCreateInfo viewport_info;
    VkPipelineRasterizationStateCreateInfo rasterization_info;
    VkPipelineMultisampleStateCreateInfo multisample_info;
    VkPipelineColorBlendAttachmentState color_blend_attachment;
    VkPipelineColorBlendStateCreateInfo color_blend_info;
    VkPipelineDepthStencilStateCreateInfo depth_stencil_info;
    VkPipelineLayout pipeline_layout = nullptr;
    VkRenderPass render_pass = nullptr;
    uint32_t subpass = 0;
};

class Pipeline {
  public:
    Pipeline(MVE::Device &in_device, const PipelineConfigInfo &config_info, const std::string_view vert_filepath, const std::string_view frag_filepath);

    ~Pipeline();

    Pipeline(const Pipeline &) = delete;
    void operator=(const Pipeline &) = delete;

    static PipelineConfigInfo DefaultPipelineConfigInfo(uint32_t width, uint32_t height);

  private:
    static std::vector<char> ReadFile(const std::string &filepath);

    void CreateGraphicsPipeline(const PipelineConfigInfo &config_info, const std::string_view vert_filepath, const std::string_view frag_filepath);

    void CreateShaderModule(const std::vector<char> &code, VkShaderModule *shader_module);

    MVE::Device &device;
    VkPipeline graphics_pipeline;
    VkShaderModule vert_shader_module;
    VkShaderModule frag_shader_module;
};
} // namespace MVE
