# RefactorIQ automotive_ecu_gateway Makefile
CC = gcc
CFLAGS = -Wall -Wextra -Iinclude -O2
SRC_DIR = src
BIN_DIR = bin

MODULES = wheel_speed_sensor can_receiver engine_telemetry engine_rpm_limiter \
          throttle_sensor brake_pressure can_frame_counter ecu_watchdog \
          dtc_manager oil_temperature bms_cell_monitor airbag_controller \
          transmission_controller cruise_control steering_torque odometer_service \
          cooling_system obd_diagnostic_service fuel_injector abs_brake_system \
          tpms_sensor exhaust_lambda can_security_ids esp_stability \
          can_frame_dropper ambient_light_sensor immobilizer_security \
          turbo_boost_controller hvac_climate_control ota_firmware_updater

all: $(MODULES)

$(MODULES): %: $(SRC_DIR)/%.c
	@mkdir -p $(BIN_DIR)
	$(CC) $(CFLAGS) $< -o $(BIN_DIR)/$@

clean:
	rm -rf $(BIN_DIR)

.PHONY: all clean $(MODULES)
