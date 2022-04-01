// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#include "Turret.h"

#include <imgui.h>
#include <wpi/numbers>

#include "Keys.h"

using namespace frc5190;

void Turret::Display() {
  // Get position, velocity, and ready data from NetworkTables.
  double position = nt_->GetNumber(keys::kTurretPosition, 0);
  double velocity = nt_->GetNumber(keys::kTurretVelocity, 0);
  bool ready = nt_->GetBoolean(keys::kTurretReady, false);

  // Output position and ready values.
  ImGui::Text("Position: %3.3f deg", position * 180.0 / wpi::numbers::pi);
  ImGui::Text("Velocity: %3.3f deg/s", velocity * 180.0 / wpi::numbers::pi);
  ImGui::Text("Ready?: %s", ready ? "true" : "false");

  // Get current values from NetworkTables.
  double current = nt_->GetNumber(keys::kTurretSupplyCurrent, 0);

  // Output current values.
  ImGui::Spacing();
  ImGui::Separator();
  ImGui::Spacing();

  ImGui::Text("Current: %3.1f A", current);
}
