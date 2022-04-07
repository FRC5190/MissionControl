// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#include "Climber.h"

#include <imgui.h>

#include "Keys.h"

using namespace frc5190;

void Climber::Display() {
  // Get position and pivot values from NT.
  double l_position = nt_->GetNumber(keys::kClimberLPosition, 0);
  double r_position = nt_->GetNumber(keys::kClimberRPosition, 0);
  bool l_pivot = nt_->GetBoolean(keys::kClimberLPivotSensor, false);
  bool r_pivot = nt_->GetBoolean(keys::kClimberRPivotSensor, false);

  // Output position and pivot values.
  ImGui::Text("L Position: %3.3f in", l_position * 39.3701);
  ImGui::Text("R Position: %3.3f in", r_position * 39.3701);
  ImGui::Text("L Pivot:    %s", l_pivot ? "true" : "false");
  ImGui::Text("R Pivot:    %s", r_pivot ? "true" : "false");

  // Get current values from NT.
  double l_current = nt_->GetNumber(keys::kClimberLSupplyCurrent, 0);
  double r_current = nt_->GetNumber(keys::kClimberRSupplyCurrent, 0);

  // Output current values.
  ImGui::Spacing();
  ImGui::Separator();
  ImGui::Spacing();

  ImGui::Text("L Current: %3.1f A", l_current);
  ImGui::Text("R Current: %3.1f A", r_current);
}
