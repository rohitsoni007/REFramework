// Placeholder stub - real implementation in IMPLEMENTATION_BACKUP.zip
#include "FSR2Backend.h"

FSR2Backend::FSR2Backend() : m_available(false) {}
FSR2Backend::~FSR2Backend() {}
bool FSR2Backend::probe_fsr2_dll() { return false; }
bool FSR2Backend::setup_direct_x(void* device, int graphics_api) { return false; }
void* FSR2Backend::init_upscaler(const InitParams* params) { return nullptr; }
void FSR2Backend::evaluate_upscaler(const UpscaleParams* params) {}
int FSR2Backend::get_render_width(int id) { return 0; }
int FSR2Backend::get_render_height(int id) { return 0; }
float FSR2Backend::get_optimal_sharpness(int id) { return 0.0f; }
float FSR2Backend::get_optimal_mipmap_bias(int id) { return 0.0f; }
int FSR2Backend::get_jitter_phase_count(int id) { return 0; }
int FSR2Backend::get_jitter_offset(float* out_x, float* out_y, int index, int phase_count) { return -1; }
void FSR2Backend::set_motion_scale_x(int id, float value) {}
void FSR2Backend::set_motion_scale_y(int id, float value) {}
void FSR2Backend::release_upscale_feature(int id) {}
bool FSR2Backend::is_available() const { return false; }
