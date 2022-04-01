#pragma once

#include <networktables/NetworkTable.h>
#include <glass/View.h>
#include <memory.h>

namespace frc5190 {
class Intake : public glass::View {
 public:
  explicit Intake(std::shared_ptr<nt::NetworkTable> nt) : nt_{nt} {}
  void Display() override;

 private:
  std::shared_ptr<nt::NetworkTable> nt_;
};
}  // namespace frc5190