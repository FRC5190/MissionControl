// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#pragma once

#include <memory>

#include <glass/View.h>
#include <networktables/NetworkTable.h>

namespace frc5190 {
class Drivetrain : public glass::View {
 public:
  explicit Drivetrain(std::shared_ptr<nt::NetworkTable> nt) : nt_{nt} {};
  void Display() override;

 private:
  std::shared_ptr<nt::NetworkTable> nt_;
};
}  // namespace frc5190
