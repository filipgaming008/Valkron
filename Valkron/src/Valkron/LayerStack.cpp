#include "valkron_pch.hpp"

#include "LayerStack.hpp"

namespace Valkron {

    LayerStack::LayerStack() : m_LayerInsertIndex(m_Layers.begin()) {}

    LayerStack::~LayerStack() {
        for (Layer* layer : m_Layers) {
            delete layer;
        }
    }

    void LayerStack::PushLayer(Layer* layer) {
        m_LayerInsertIndex = m_Layers.emplace(m_LayerInsertIndex, layer);
    }

    void LayerStack::PushOverlay(Layer* overlay) {
        m_Layers.emplace_back(overlay);
    }

    void LayerStack::PopLayer(Layer* layer) {
        auto it = std::find(m_Layers.begin(), m_Layers.end(), layer);
        if (it != m_Layers.end()) {
            m_Layers.erase(it);
            --m_LayerInsertIndex;
        }
    }

    void LayerStack::PopOverlay(Layer* overlay) {
        auto it = std::find(m_Layers.begin(), m_Layers.end(), overlay);
        if (it != m_Layers.end()) {
            m_Layers.erase(it);
        }
    }

}