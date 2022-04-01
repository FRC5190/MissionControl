// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#include "Drivetrain.h"

#include <cstdlib>

#include <imgui.h>

#include "Constants.h"
#include "Keys.h"

using namespace frc5190;

void Drivetrain::Display() {
  // Get position and velocity data from NetworkTables.
  double l_position = nt_->GetNumber(keys::kDrivetrainLPosition, 0);
  double r_position = nt_->GetNumber(keys::kDrivetrainRPosition, 0);
  double l_velocity = nt_->GetNumber(keys::kDrivetrainLVelocity, 0);
  double r_velocity = nt_->GetNumber(keys::kDrivetrainRVelocity, 0);

  // Output position and velocity values.
  ImGui::Text("L Position: %3.3f m", l_position);
  ImGui::Text("R Position: %3.3f m", r_position);
  ImGui::Text("L Velocity: %3.3f m/s", l_velocity);
  ImGui::Text("R Velocity: %3.3f m/s", r_velocity);

  // Get current values from NetworkTables.
  double ll_current = nt_->GetNumber(keys::kDrivetrainLLSupplyCurrent, 0);
  double lf_current = nt_->GetNumber(keys::kDrivetrainLFSupplyCurrent, 0);
  double rl_current = nt_->GetNumber(keys::kDrivetrainRLSupplyCurrent, 0);
  double rf_current = nt_->GetNumber(keys::kDrivetrainRFSupplyCurrent, 0);

  // Output current values.
  ImGui::Spacing();
  ImGui::Separator();
  ImGui::Spacing();

  ImGui::Text("LL Current: %3.1f A", ll_current);
  ImGui::Text("LF Current: %3.1f A", lf_current);
  ImGui::Text("RL Current: %3.1f A", rl_current);
  ImGui::Text("RR Current: %3.1f A", rf_current);

  // Check for current discrepancies.
  static ImVec4 warning_color{1.0f, 0.5f, 0.0f, 1.0f};

  if (std::abs(ll_current - lf_current) >
      constants::kGearboxCurrentDiscrepancyThreshold) {
    ImGui::TextColored(warning_color, "L Gearbox Current Discrepancy!");
  }

  if (std::abs(rl_current - rf_current) >
      constants::kGearboxCurrentDiscrepancyThreshold) {
    ImGui::TextColored(warning_color, "R Gearbox Current Discrepancy!");
  }
}
