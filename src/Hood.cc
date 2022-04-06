// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#include "Hood.h"

#include <imgui.h>
#include <wpi/numbers>

#include "Keys.h"

using namespace frc5190;

void Hood::Display() {
  // Get position data from NetworkTables.
  double raw_enc = nt_->GetNumber(keys::kHoodRawEnc, 0);
  double position = nt_->GetNumber(keys::kHoodPosition, 0);

  // Output position and velocity values.
  ImGui::Text("Raw Encoder: %3.3f", raw_enc);
  ImGui::Text("Position:    %3.3f deg", position * 180.0 / wpi::numbers::pi);

  // Get current values from NetworkTables.
  double current = nt_->GetNumber(keys::kHoodSupplyCurrent, 0);

  // Output current values.
  ImGui::Spacing();
  ImGui::Separator();
  ImGui::Spacing();

  ImGui::Text("Current: %3.1f A", current);
}
