#include "Hood.h"
#include "Keys.h"

#include <imgui.h>
#include <wpi/numbers>

using namespace frc5190;

void Hood::Display() {
  // Get position and velocity data from NetworkTables.
  double position = nt_->GetNumber(keys::kHoodPosition, 0);
  double velocity = nt_->GetNumber(keys::kHoodVelocity, 0);

  // Output position and velocity values.
  ImGui::Text("Position: %3.3f deg", position * 180.0 / wpi::numbers::pi);
  ImGui::Text("Velocity: %3.3f deg/s", velocity * 180.0 / wpi::numbers::pi);

  // Get current values from NetworkTables.
  double current = nt_->GetNumber(keys::kHoodSupplyCurrent, 0);

  // Output current values.
  ImGui::Spacing();
  ImGui::Separator();
  ImGui::Spacing();

  ImGui::Text("Current: %3.1f A", current);
}