#pragma once

#include <glass/View.h>
#include <networktables/NetworkTable.h>
#include <memory>

namespace frc5190 {
class Drivetrain : public glass::View {
 public:
  Drivetrain(std::shared_ptr<nt::NetworkTable> nt) : nt_{nt} {};
  void Display() override;

 private:
  std::shared_ptr<nt::NetworkTable> nt_;
};
}  // namespace frc5190
