// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#pragma once

#include <memory>

#include <glass/View.h>
#include <networktables/NetworkTable.h>

namespace frc5190 {
class Tuning : public glass::View {
 public:
  explicit Tuning(std::shared_ptr<nt::NetworkTable> nt) : nt_{nt} {}
  void Display() override;

 private:
  std::shared_ptr<nt::NetworkTable> nt_;
  int shooter_rpm_ = 0;
  double hood_angle_deg_ = 0;
};
}  // namespace frc5190
