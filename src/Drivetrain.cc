#include "Drivetrain.h"
#include "imgui.h"
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
}