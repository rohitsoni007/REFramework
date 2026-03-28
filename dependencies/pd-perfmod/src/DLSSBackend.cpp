// Placeholder stub - real implementation in IMPLEMENTATION_BACKUP.zip
#include "DLSSBackend.h"

DLSSBackend::DLSSBackend() : m_available(false) {}
DLSSBackend::~DLSSBackend() {}
bool DLSSBackend::probe_dlss_dll() { return false; }
bool DLSSBackend::setup_direct_x(void* device, int graphics_api) { return false; }
void* DLSSBackend::init_upscaler(const InitParams* params) { return nullptr; }
void DLSSBackend::evaluate_upscaler(const UpscaleParams* params) {}
int DLSSBackend::get_render_width(int id) { return 0; }
int DLSSBackend::get_render_height(int id) { return 0; }
float DLSSBackend::get_optimal_sharpness(int id) { return 0.0f; }
float DLSSBackend::get_optimal_mipmap_bias(int id) { return 0.0f; }
int DLSSBackend::get_jitter_phase_count(int id) { return 0; }
int DLSSBackend::get_jitter_offset(float* out_x, float* out_y, int index, int phase_count) { return -1; }
void DLSSBackend::set_motion_scale_x(int id, float value) {}
void DLSSBackend::set_motion_scale_y(int id, float value) {}
void DLSSBackend::release_upscale_feature(int id) {}
bool DLSSBackend::is_available() const { return false; }
