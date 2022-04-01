// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#include "Superstructure.h"

#include <string>

#include <imgui.h>
#include <wpi/numbers>

#include "Keys.h"

using namespace frc5190;

void Superstructure::Display() {
  // Get setpoints from NT.
  double turret_position_setpoint =
      nt_->GetNumber(keys::kTurretPositionSetpoint, 0);
  double turret_velocity_setpoint =
      nt_->GetNumber(keys::kTurretVelocitySetpoint, 0);
  double shooter_speed_setpoint =
      nt_->GetNumber(keys::kShooterSpeedSetpoint, 0);
  double hood_angle_setpoint = nt_->GetNumber(keys::kHoodAngleSetpoint, 0);

  // Output setpoints.
  ImGui::Text("Turret Position Setpoint: %3.3f deg",
              turret_position_setpoint * 180.0 / wpi::numbers::pi);
  ImGui::Text("Turret Velocity Setpoint: %3.3f deg/s",
              turret_velocity_setpoint * 180.0 / wpi::numbers::pi);
  ImGui::Text("Shooter Speed Setpoint:   %3.3f rpm",
              shooter_speed_setpoint * 60.0 / 2 / wpi::numbers::pi);
  ImGui::Text("Hood Angle Setpoint:      %3.3f deg",
              hood_angle_setpoint * 180.0 / wpi::numbers::pi);

  // Get state information from NT.
  std::string turret_state =
      nt_->GetString(keys::kSuperstructureTurretState, "None");
  std::string shooter_state =
      nt_->GetString(keys::kSuperstructureShooterState, "None");
  std::string hood_state =
      nt_->GetString(keys::kSuperstructureHoodState, "None");
  std::string feeder_state =
      nt_->GetString(keys::kSuperstructureFeederState, "None");
  std::string intake_state =
      nt_->GetString(keys::kSuperstructureIntakeState, "None");

  // Output state information.
  ImGui::Spacing();
  ImGui::Separator();
  ImGui::Spacing();

  ImGui::Text("Turret State:  %s", turret_state.c_str());
  ImGui::Text("Shooter State: %s", shooter_state.c_str());
  ImGui::Text("Hood State:    %s", hood_state.c_str());
  ImGui::Text("Feeder State:  %s", feeder_state.c_str());
  ImGui::Text("Intake State:  %s", intake_state.c_str());
}
