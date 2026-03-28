#pragma once

#include "PDPerfPlugin.h"
#include <memory>
#include <string>

/**
 * Abstract interface for upscaler backends (DLSS, FSR2, XeSS).
 * Each backend implementation handles the specifics of its respective upscaler SDK.
 */
class IUpscalerBackend {
public:
    virtual ~IUpscalerBackend() = default;

    // Graphics API setup
    virtual bool setup_direct_x(void* device, int graphics_api) = 0;

    // Upscaler initialization
    virtual void* init_upscaler(const InitParams* params) = 0;

    // Upscale evaluation (main rendering call)
    virtual void evaluate_upscaler(const UpscaleParams* params) = 0;

    // Query functions
    virtual int get_render_width(int id) = 0;
    virtual int get_render_height(int id) = 0;
    virtual float get_optimal_sharpness(int id) = 0;
    virtual float get_optimal_mipmap_bias(int id) = 0;
    virtual int get_jitter_phase_count(int id) = 0;
    virtual int get_jitter_offset(float* out_x, float* out_y, int index, int phase_count) = 0;

    // Motion scale configuration
    virtual void set_motion_scale_x(int id, float value) = 0;
    virtual void set_motion_scale_y(int id, float value) = 0;

    // Cleanup
    virtual void release_upscale_feature(int id) = 0;

    // Status queries
    virtual bool is_available() const = 0;
    virtual const char* get_name() const = 0;
    virtual int get_method_id() const = 0;  // 0=DLSS, 1=FSR2, 2=XeSS

private:
    // non-copyable
    IUpscalerBackend(const IUpscalerBackend&) = delete;
    IUpscalerBackend& operator=(const IUpscalerBackend&) = delete;

protected:
    IUpscalerBackend() = default;
};

// Convenience aliases
using UpscalerBackendPtr = std::shared_ptr<IUpscalerBackend>;
