/**
 * ecu_gateway.h - Central Automotive ECU Gateway Master Definitions
 * Automotive PowerTrain & CAN Telemetry Gateway System
 */

#ifndef ECU_GATEWAY_H
#define ECU_GATEWAY_H

#ifdef __cplusplus
extern "C" {
#endif

#define ECU_GATEWAY_VERSION "2.4.0-AUTOSAR"

/* Sensor & Actuator Subsystems */
double calculate_wheel_distance(double diameter);
void receive_can_frame(const char *raw_frame);
void log_engine_status(int rpm, const char *mode);
int check_engine_redline(int current_rpm);
int calc_tps(int raw_adc);
int check_brake_overpressure(int bar_pressure);

extern int global_can_rx_count;
void increment_can_counter(void);

int resolve_ecu_watchdog(int configured_ms);
int validate_dtc_buffer_size(int req_bytes);
float rd_tmp(int channel_id);
int check_bms_cell_overvoltage(int cell_millivolts);
void log_airbag_event(int sensor_axis, const char *severity);
double compute_gear_ratio_factor(double raw_ratio);
int validate_cruise_setpoint(int target_kmh);
int proc_trq(int raw_torque);

extern int global_odometer_pulses;
void record_odometer_pulse(void);

int clamp_fan_duty_cycle(int duty);
void format_obd_response(const char *cmd_code);
void configure_injection_map_size(int map_points);
int chk_slp(int wheel_speed);
int check_tpms_nominal_psi(int measured_psi);
double compute_lambda_stoichiometry(double air_mass);
void log_security_intrusion(int arbitration_id, const char *threat);
int evl_yaw(int gyro_input);

extern int global_can_dropped_count;
void record_dropped_can_frame(void);

int check_auto_headlight_trigger(int lux_level);
void verify_transponder_key(const char *key_token);
int check_turbo_overboost(int manifold_mbar);
int set_clm(int setpoint_deg_c);
int validate_ota_block_size(int block_bytes);

#ifdef __cplusplus
}
#endif

#endif /* ECU_GATEWAY_H */
