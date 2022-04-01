#include "Intake.h"
#include "Keys.h"

#include <memory>
#include <string>

#include <imgui.h>

using namespace frc5190;

void Intake::Display() {
  // Get sensor values from NT.
  bool lower_sensor = nt_->GetBoolean(keys::kIntakeLowerSensor, false);
  bool upper_sensor = nt_->GetBoolean(keys::kIntakeUpperSensor, false);
  std::string next_cargo = nt_->GetString(keys::kIntakeNextCargoColor, "None");

  // Output sensor values.
  ImGui::Text("Lower Sensor:     %s", lower_sensor ? "true" : "false");
  ImGui::Text("Upper Sensor:     %s", upper_sensor ? "true" : "false");
  ImGui::Text("Next Cargo Color: %s", next_cargo.c_str());

  // Get current values from NT.
  double intake_current = nt_->GetNumber(keys::kIntakeSupplyCurrent, 0);
  double bridge_l_current = nt_->GetNumber(keys::kBridgeLSupplyCurrent, 0);
  double bridge_f_current = nt_->GetNumber(keys::kBridgeFSupplyCurrent, 0);
  double feeder_floor_current =
      nt_->GetNumber(keys::kFeederFloorSupplyCurrent, 0);
  double feeder_wall_current =
      nt_->GetNumber(keys::kFeederWallSupplyCurrent, 0);

  // Output current values.
  ImGui::Spacing();
  ImGui::Separator();
  ImGui::Spacing();

  ImGui::Text("Intake Current:       %3.1f A", intake_current);
  ImGui::Text("Bridge L Current:     %3.1f A", bridge_l_current);
  ImGui::Text("Bridge F Current:     %3.1f A", bridge_f_current);
  ImGui::Text("Feeder Floor Current: %3.1f A", feeder_floor_current);
  ImGui::Text("Feeder Wall Current:  %3.1f A", feeder_wall_current);
}