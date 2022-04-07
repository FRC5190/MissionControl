// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#include "Intake.h"

#include <cstdlib>
#include <memory>
#include <string>

#include <imgui.h>

#include "Constants.h"
#include "Keys.h"

using namespace frc5190;

void Intake::Display() {
  // Get sensor values from NT.
  int lower_sensor_prox = nt_->GetNumber(keys::kFeederLowerSensorProx, 0);
  int upper_sensor_prox = nt_->GetNumber(keys::kFeederUpperSensorProx, 0);
  bool lower_sensor = nt_->GetBoolean(keys::kFeederLowerSensor, false);
  bool upper_sensor = nt_->GetBoolean(keys::kFeederUpperSensor, false);
  std::string upper_sensor_color =
      nt_->GetString(keys::kFeederUpperSensorColor, "");

  // Output sensor values.
  ImGui::Text("Lower Sensor Prox:  %i", lower_sensor_prox);
  ImGui::Text("Upper Sensor Prox:  %i", upper_sensor_prox);
  ImGui::Text("Lower Sensor:       %s", lower_sensor ? "true" : "false");
  ImGui::Text("Upper Sensor:       %s", upper_sensor ? "true" : "false");
  ImGui::Text("Upper Sensor Color: %s", upper_sensor_color.c_str());

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

  // Check for current discrepancy.
  static ImVec4 warning_color{1.0f, 0.5f, 0.0f, 1.0f};
  if (std::abs(bridge_l_current - bridge_f_current) >
      constants::kGearboxCurrentDiscrepancyThreshold) {
    ImGui::TextColored(warning_color, "Bridge Gearbox Current Discrepancy!");
  }
}
