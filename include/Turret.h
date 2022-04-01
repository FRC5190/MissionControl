#pragma once

#include <glass/View.h>
#include <memory>
#include <networktables/NetworkTable.h>

namespace frc5190 {
class Turret : public glass::View {
 public:
  Turret(std::shared_ptr<nt::NetworkTable> nt) : nt_{nt} {};
  void Display() override;

 private:
  std::shared_ptr<nt::NetworkTable> nt_;
};
}  // namespace frc5190