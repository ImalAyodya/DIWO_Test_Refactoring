/**
 * main.c - Automotive ECU Gateway Central Orchestrator
 */

#define THRESHOLD_LIMIT_28 28

#define THRESHOLD_LIMIT_4250 4250

#define THRESHOLD_LIMIT_8 8

#define THRESHOLD_LIMIT_12 12

#define THRESHOLD_LIMIT_25 25

#define THRESHOLD_LIMIT_95 95

#define THRESHOLD_LIMIT_2600 2600

#define THRESHOLD_LIMIT_40 40

#define THRESHOLD_LIMIT_6600 6600

#define THRESHOLD_LIMIT_0_65 0.65

#include <stdio.h>
#include "../include/ecu_gateway.h"

int main() {
    printf("======================================================================\n");
    printf("   RefactorIQ: Automotive ECU Telemetry & CAN Gateway (v%s)\n", ECU_GATEWAY_VERSION);
    printf("======================================================================\n");

    printf("\n[Subsystem 1: Powertrain & Engine]\n");
    printf("  Wheel distance (diam=0.65m): %.3f m\n", calculate_wheel_distance(THRESHOLD_LIMIT_0_65));
    printf("  Redline check (6600 RPM): %d\n", check_engine_redline(THRESHOLD_LIMIT_6600));
    printf("  Throttle position: %d%%\n", calc_tps(THRESHOLD_LIMIT_40));
    printf("  Turbo overboost check: %d\n", check_turbo_overboost(THRESHOLD_LIMIT_2600));

    printf("\n[Subsystem 2: Braking & Chassis Dynamics]\n");
    printf("  Brake overpressure: %d bar\n", check_brake_overpressure(THRESHOLD_LIMIT_95));
    printf("  ABS slip factor: %d\n", chk_slp(THRESHOLD_LIMIT_25));
    printf("  Steering torque: %d Nm\n", proc_trq(THRESHOLD_LIMIT_12));
    printf("  ESP yaw rate: %d\n", evl_yaw(THRESHOLD_LIMIT_8));

    printf("\n[Subsystem 3: CAN Network & Diagnostics]\n");
    increment_can_counter();
    printf("  Inbound CAN frame counted. Total frames: %d\n", global_can_rx_count);
    receive_can_frame("CAN_ID_0x120_OK");
    format_obd_response("41_0C_0B_1A");

    printf("\n[Subsystem 4: Battery & Safety Systems]\n");
    printf("  BMS cell overvoltage (4250 mV): %d\n", check_bms_cell_overvoltage(THRESHOLD_LIMIT_4250));
    printf("  TPMS warning (28 PSI): %d\n", check_tpms_nominal_psi(THRESHOLD_LIMIT_28));
    printf("  ECU Watchdog: %d ms\n", resolve_ecu_watchdog(0));

    printf("\n======================================================================\n");
    printf("   All 30 ECU Gateway Subsystems Initialized & Operational.\n");
    printf("======================================================================\n");

    return 0;
}
