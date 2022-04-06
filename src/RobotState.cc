// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#include "RobotState.h"

#include <imgui.h>
#include <wpi/numbers>

#include "Keys.h"

using namespace frc5190;

void RobotState::Display() {
  // Get values from NT.
  double x = nt_->GetNumber(keys::kRobotStateX, 0);
  double y = nt_->GetNumber(keys::kRobotStateY, 0);
  double theta = nt_->GetNumber(keys::kRobotStateTheta, 0);
  double goal_distance = nt_->GetNumber(keys::kRobotStateGoalDistance, 0);

  // Show values.
  ImGui::Text("Robot X:       %3.3f ft", x * 3.28084);
  ImGui::Text("Robot Y:       %3.3f ft", y * 3.28084);
  ImGui::Text("Robot Theta:   %3.3f deg", theta * 180 / wpi::numbers::pi);

  ImGui::Spacing();
  ImGui::Separator();
  ImGui::Spacing();

  ImGui::Text("Goal Distance:");
  ImGui::Text("  %3.3f ft", goal_distance * 3.28084);
  ImGui::Text("  %3.3f m", goal_distance);
}
