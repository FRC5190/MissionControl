// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#include "Tuning.h"

#include <imgui.h>
#include <wpi/numbers>

#include "Keys.h"

using namespace frc5190;

void Tuning::Display() {
  // Display values for entering shooter rpm and hood angle.
  ImGui::SetNextItemWidth(ImGui::GetFontSize() * 8);
  ImGui::InputInt("Shooter Speed (rpm)", &shooter_rpm_, 0);
  ImGui::SetNextItemWidth(ImGui::GetFontSize() * 8);
  ImGui::InputDouble("Hood Angle (deg)", &hood_angle_deg_, 0, 0, "%.1f");

  // Show button to start and stop tuning.
  bool tuning = nt_->GetBoolean(keys::kSuperstructureTune, false);
  if (ImGui::Button(tuning ? "Stop" : "Tune")) {
    nt_->GetEntry(keys::kSuperstructureTuningShooterSpeed)
        .SetDouble(shooter_rpm_ * 2 * wpi::numbers::pi / 60);
    nt_->GetEntry(keys::kSuperstructureTuningHoodAngle)
        .SetDouble(hood_angle_deg_ * wpi::numbers::pi / 180);
    nt_->GetEntry(keys::kSuperstructureTune).SetBoolean(!tuning);
  }
}
