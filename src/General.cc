// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#include "General.h"

#include <imgui.h>
#include <networktables/NetworkTableInstance.h>

#include "Keys.h"

using namespace frc5190;

void General::Display() {
  // Get connection status.
  bool connection = nt_->GetInstance().IsConnected();

  // Output values.
  static ImVec4 connected_color{0.0f, 1.0f, 0.0f, 1.0f};
  static ImVec4 disconnected_color{1.0f, 0.1f, 0.0f, 1.0f};

  ImGui::TextColored(connection ? connected_color : disconnected_color,
                     connection ? "Robot Connected" : "No Robot Connection");

  // Get climb mode and air pressure from NT.
  bool climb_mode = nt_->GetBoolean(keys::kClimbMode, false);
  double air_pressure = nt_->GetNumber(keys::kAirPressure, 0);

  // Output values.
  ImGui::Spacing();
  ImGui::Separator();
  ImGui::Spacing();

  ImGui::Text("Climb Mode:   %s", climb_mode ? "true" : "false");
  ImGui::Text("Air Pressure: %.3f psi", air_pressure);
}
