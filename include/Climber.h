#pragma once

#include <networktables/NetworkTable.h>
#include <glass/View.h>
#include <memory>

namespace frc5190 {
class Climber : public glass::View {
 public:
  explicit Climber(std::shared_ptr<nt::NetworkTable> nt) : nt_{nt} {}
  void Display() override;

 private:
  std::shared_ptr<nt::NetworkTable> nt_;
};
}  // namespace frc5190