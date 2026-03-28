#pragma once

#include "UpscalerBackend.h"
#include <map>
#include <vector>
#include <memory>

/**
 * Global singleton that manages upscaler backends and instances.
 * Probes available backends at startup, selects active backend on first init,
 * and maintains per-ID instance data.
 */
class GlobalUpscalerManager {
public:
    // Get singleton instance
    static GlobalUpscalerManager& get();

    // Initialize manager (probe available backends)
    void initialize();

    // Set logging callback
    void set_log_delegate(void (*callback)(char* message, int size));

    // Set debug mode
    void set_debug(bool debug);

    // Graphics setup
    bool setup_direct_x(void* device, int graphics_api);

    // Initialization
    void* init_upscaler(const InitParams* params);

    // Upscale evaluation
    void evaluate_upscaler(const UpscaleParams* params);

    // Query functions
    int get_render_width(int id);
    int get_render_height(int id);
    float get_optimal_sharpness(int id);
    float get_optimal_mipmap_bias(int id);
    int get_jitter_phase_count(int id);
    int get_jitter_offset(float* out_x, float* out_y, int index, int phase_count);

    // Motion scale
    void set_motion_scale_x(int id, float value);
    void set_motion_scale_y(int id, float value);

    // Cleanup
    void release_upscale_feature(int id);

    // Availability & names
    bool is_upscale_method_available(int upscale_method) const;
    const char* get_upscale_method_name(int upscale_method) const;

private:
    GlobalUpscalerManager();
    ~GlobalUpscalerManager() = default;

    // non-copyable
    GlobalUpscalerManager(const GlobalUpscalerManager&) = delete;
    GlobalUpscalerManager& operator=(const GlobalUpscalerManager&) = delete;

    // Helpers
    void log(const char* message);
    UpscalerBackendPtr get_backend_by_id(int backend_id) const;
    UpscalerBackendPtr get_active_backend() const;

    // State
    std::vector<UpscalerBackendPtr> m_backends;  // Ordered by priority
    std::map<int, UpscalerBackendPtr> m_instances;  // ID → backend
    int m_next_id = 1;
    void (*m_log_callback)(char*, int) = nullptr;
    bool m_debug = false;

    // Track which backend was selected for each upscale method
    std::map<int, UpscalerBackendPtr> m_method_backends;
};
