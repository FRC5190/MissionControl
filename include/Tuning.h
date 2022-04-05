#pragma once

#include <glass/View.h>
#include <networktables/NetworkTable.h>
#include <memory>

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