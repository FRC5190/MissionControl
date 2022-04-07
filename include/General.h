// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#pragma once

#include <memory>

#include <fmt/core.h>
#include <glass/View.h>
#include <glass/networktables/NTStringChooser.h>
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableInstance.h>

#include "Keys.h"

namespace frc5190 {
class General : public glass::View {
 public:
  explicit General(std::shared_ptr<nt::NetworkTable> nt)
      : nt_{nt},
        string_chooser_model_(nt_->GetInstance().GetHandle(),
                              fmt::format("robot/{}", keys::kAutoSelector)) {}
  void Display() override;

 private:
  std::shared_ptr<nt::NetworkTable> nt_;
  glass::NTStringChooserModel string_chooser_model_;
};
}  // namespace frc5190
