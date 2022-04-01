// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#include "Shooter.h"

#include <imgui.h>
#include <wpi/numbers>

#include "Keys.h"

using namespace frc5190;

void Shooter::Display() {
  // Get velocity data from NetworkTables.
  double velocity = nt_->GetNumber(keys::kShooterVelocity, 0);

  // Output velocity values.
  ImGui::Text("Velocity: %3.3f rpm", velocity * 60.0 / 2 / wpi::numbers::pi);

  // Get current values from NetworkTables.
  double l_current = nt_->GetNumber(keys::kShooterLSupplyCurrent, 0);
  double f_current = nt_->GetNumber(keys::kShooterFSupplyCurrent, 0);

  // Output current values.
  ImGui::Spacing();
  ImGui::Separator();
  ImGui::Spacing();

  ImGui::Text("L Current: %3.1f A", l_current);
  ImGui::Text("F Current: %3.1f A", f_current);
}
