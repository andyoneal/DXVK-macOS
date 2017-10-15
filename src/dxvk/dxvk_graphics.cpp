#include "dxvk_graphics.h"

namespace dxvk {
  
  size_t DxvkGraphicsPipelineState::hash() const {
    // TODO implement
  }
  
  
  bool DxvkGraphicsPipelineState::operator == (const DxvkGraphicsPipelineState& other) const {
    // TODO implement
  }
  
  
  bool DxvkGraphicsPipelineState::operator != (const DxvkGraphicsPipelineState& other) const {
    return !this->operator == (other);
  }
  
  
  DxvkGraphicsPipeline::DxvkGraphicsPipeline(
      const Rc<vk::DeviceFn>& vkd,
      const Rc<DxvkShader>&   vs,
      const Rc<DxvkShader>&   tcs,
      const Rc<DxvkShader>&   tes,
      const Rc<DxvkShader>&   gs,
      const Rc<DxvkShader>&   fs)
  : m_vkd(vkd), m_vs(vs), m_tcs(tcs),
    m_tes(tes), m_gs(gs), m_fs(fs) {
    
  }
  
  
  DxvkGraphicsPipeline::~DxvkGraphicsPipeline() {
    
  }
  
  
  VkPipeline DxvkGraphicsPipeline::getPipelineHandle(
    const DxvkGraphicsPipelineState& state) {
    std::lock_guard<std::mutex> lock(m_mutex);
    
    auto pair = m_pipelines.find(state);
    if (pair != m_pipelines.end())
      return pair->second;
    
    VkPipeline pipeline = this->compilePipeline(state);
    m_pipelines.insert(std::make_pair(state, pipeline));
    return pipeline;
  }
  
  
  VkPipeline DxvkGraphicsPipeline::compilePipeline(
    const DxvkGraphicsPipelineState& state) const {
    
  }
  
}