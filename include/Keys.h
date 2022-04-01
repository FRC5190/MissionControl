#pragma once

#include <string_view>

namespace frc5190 {
namespace keys {
// Robot
static constexpr std::string_view kClimbMode = "climb_mode";
static constexpr std::string_view kAirPressure = "air_pressure";
static constexpr std::string_view kAutoSelector = "auto_selector";

// Robot State
static constexpr std::string_view kRobotStateX = "robot_state/x";
static constexpr std::string_view kRobotStateY = "robot_state/y";
static constexpr std::string_view kRobotStateTheta = "robot_state/theta";

// Drivetrain
static constexpr std::string_view kDrivetrainLPosition =
    "drivetrain/l_position";
static constexpr std::string_view kDrivetrainRPosition =
    "drivetrain/r_position";
static constexpr std::string_view kDrivetrainLVelocity =
    "drivetrain/l_velocity";
static constexpr std::string_view kDrivetrainRVelocity =
    "drivetrain/r_velocity";
static constexpr std::string_view kDrivetrainLLSupplyCurrent =
    "drivetrain/ll_supply_current";
static constexpr std::string_view kDrivetrainLFSupplyCurrent =
    "drivetrain/lf_supply_current";
static constexpr std::string_view kDrivetrainRLSupplyCurrent =
    "drivetrain/rl_supply_current";
static constexpr std::string_view kDrivetrainRFSupplyCurrent =
    "drivetrain/rf_supply_current";

// Turret
static constexpr std::string_view kTurretPosition = "turret/position";
static constexpr std::string_view kTurretVelocity = "turret/velocity";
static constexpr std::string_view kTurretSupplyCurrent =
    "turret/supply_current";
static constexpr std::string_view kTurretReady = "turret/ready";

// Shooter
static constexpr std::string_view kShooterVelocity = "shooter/velocity";
static constexpr std::string_view kShooterLSupplyCurrent =
    "shooter/l_supply_current";
static constexpr std::string_view kShooterFSupplyCurrent =
    "shooter/f_supply_current";

// Hood
static constexpr std::string_view kHoodPosition = "hood/position";
static constexpr std::string_view kHoodVelocity = "hood/velocity";
static constexpr std::string_view kHoodSupplyCurrent = "hood/supply_current";

// Intake
static constexpr std::string_view kIntakeSupplyCurrent =
    "intake/intake_supply_current";
static constexpr std::string_view kBridgeLSupplyCurrent =
    "intake/bridge_l_supply_current";
static constexpr std::string_view kBridgeFSupplyCurrent =
    "intake/bridge_f_supply_current";
static constexpr std::string_view kFeederFloorSupplyCurrent =
    "intake/feeder_floor_supply_current";
static constexpr std::string_view kFeederWallSupplyCurrent =
    "intake/feeder_wall_supply_current";

// Superstructure
static constexpr std::string_view kTurretPositionSetpoint =
    "superstructure/turret_position_setpoint";
static constexpr std::string_view kTurretVelocitySetpoint =
    "superstructure/turret_velocity_setpoint";
static constexpr std::string_view kShooterSpeedSetpoint =
    "superstructure/shooter_speed_setpoint";
static constexpr std::string_view kHoodAngleSetpoint =
    "superstructure/hood_angle_setpoint";
}  // namespace keys
}  // namespace frc5190