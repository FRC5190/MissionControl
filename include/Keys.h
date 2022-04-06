// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

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
static constexpr std::string_view kRobotStateGoalDistance =
    "robot_state/goal_distance";

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
static constexpr std::string_view kHoodRawEnc = "hood/raw_enc";
static constexpr std::string_view kHoodPosition = "hood/position";
static constexpr std::string_view kHoodSupplyCurrent = "hood/supply_current";

// Intake
static constexpr std::string_view kIntakeSupplyCurrent =
    "intake/intake_supply_current";
static constexpr std::string_view kBridgeLSupplyCurrent =
    "intake/bridge_l_supply_current";
static constexpr std::string_view kBridgeFSupplyCurrent =
    "intake/bridge_f_supply_current";

// Feeder
static constexpr std::string_view kFeederLowerSensor = "feeder/lower_sensor";
static constexpr std::string_view kFeederUpperSensor = "feeder/upper_sensor";
static constexpr std::string_view kFeederFloorSupplyCurrent =
    "feeder/floor_supply_current";
static constexpr std::string_view kFeederWallSupplyCurrent =
    "feeder/wall_supply_current";

// Climber
static constexpr std::string_view kClimberLPosition = "climber/l_position";
static constexpr std::string_view kClimberRPosition = "climber/r_position";
static constexpr std::string_view kClimberLSupplyCurrent =
    "climber/l_supply_current";
static constexpr std::string_view kClimberRSupplyCurrent =
    "climber/r_supply_current";

// Superstructure
static constexpr std::string_view kTurretPositionSetpoint =
    "superstructure/turret_position_setpoint";
static constexpr std::string_view kTurretVelocitySetpoint =
    "superstructure/turret_velocity_setpoint";
static constexpr std::string_view kShooterSpeedSetpoint =
    "superstructure/shooter_speed_setpoint";
static constexpr std::string_view kHoodAngleSetpoint =
    "superstructure/hood_angle_setpoint";

static constexpr std::string_view kSuperstructureNextCargo =
    "superstructure/next_up_cargo";

static constexpr std::string_view kSuperstructureTurretState =
    "superstructure/turret_state";
static constexpr std::string_view kSuperstructureShooterState =
    "superstructure/shooter_state";
static constexpr std::string_view kSuperstructureHoodState =
    "superstructure/hood_state";
static constexpr std::string_view kSuperstructureFeederState =
    "superstructure/feeder_state";
static constexpr std::string_view kSuperstructureIntakeState =
    "superstructure/intake_state";

static constexpr std::string_view kSuperstructureTurretAtGoal =
    "superstructure/turret_at_goal";
static constexpr std::string_view kSuperstructureShooterAtGoal =
    "superstructure/shooter_at_goal";
static constexpr std::string_view kSuperstructureHoodAtGoal =
    "superstructure/hood_at_goal";

static constexpr std::string_view kSuperstructureTuningShooterSpeed =
    "superstructure/tuning_shooter_speed";
static constexpr std::string_view kSuperstructureTuningHoodAngle =
    "superstructure/tuning_hood_angle";
static constexpr std::string_view kSuperstructureTune =
    "superstructure/start_tune";
}  // namespace keys
}  // namespace frc5190
