#pragma once

#include "UpscalerBackend.h"
#include <map>

/**
 * XeSS Backend implementation (priority=2).
 * Loads Intel XeSS upscaler at runtime.
 */
class XeSSSBackend : public IUpscalerBackend {
public:
    XeSSSBackend();
    virtual ~XeSSSBackend();

    // IUpscalerBackend interface
    bool setup_direct_x(void* device, int graphics_api) override;
    void* init_upscaler(const InitParams* params) override;
    void evaluate_upscaler(const UpscaleParams* params) override;
    int get_render_width(int id) override;
    int get_render_height(int id) override;
    float get_optimal_sharpness(int id) override;
    float get_optimal_mipmap_bias(int id) override;
    int get_jitter_phase_count(int id) override;
    int get_jitter_offset(float* out_x, float* out_y, int index, int phase_count) override;
    void set_motion_scale_x(int id, float value) override;
    void set_motion_scale_y(int id, float value) override;
    void release_upscale_feature(int id) override;
    bool is_available() const override;
    const char* get_name() const override { return "XeSS"; }
    int get_method_id() const override { return 2; }  // XeSS = 2

private:
    struct UpscalerInstance {
        int render_width = 0;
        int render_height = 0;
        int display_width = 0;
        int display_height = 0;
        float sharpness = 0.5f;
        float mipmap_bias = -1.0f;
    };

    std::map<int, UpscalerInstance> m_instances;
    void* m_device = nullptr;
    int m_graphics_api = 0;
    bool m_available = false;

    // Helper to check if XeSS DLL is available
    bool probe_xess_dll();
};
