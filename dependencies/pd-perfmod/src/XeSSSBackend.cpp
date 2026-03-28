// Placeholder stub - real implementation in IMPLEMENTATION_BACKUP.zip
#include "XeSSSBackend.h"

XeSSSBackend::XeSSSBackend() : m_available(false) {}
XeSSSBackend::~XeSSSBackend() {}
bool XeSSSBackend::probe_xess_dll() { return false; }
bool XeSSSBackend::setup_direct_x(void* device, int graphics_api) { return false; }
void* XeSSSBackend::init_upscaler(const InitParams* params) { return nullptr; }
void XeSSSBackend::evaluate_upscaler(const UpscaleParams* params) {}
int XeSSSBackend::get_render_width(int id) { return 0; }
int XeSSSBackend::get_render_height(int id) { return 0; }
float XeSSSBackend::get_optimal_sharpness(int id) { return 0.0f; }
float XeSSSBackend::get_optimal_mipmap_bias(int id) { return 0.0f; }
int XeSSSBackend::get_jitter_phase_count(int id) { return 0; }
int XeSSSBackend::get_jitter_offset(float* out_x, float* out_y, int index, int phase_count) { return -1; }
void XeSSSBackend::set_motion_scale_x(int id, float value) {}
void XeSSSBackend::set_motion_scale_y(int id, float value) {}
void XeSSSBackend::release_upscale_feature(int id) {}
bool XeSSSBackend::is_available() const { return false; }
