#pragma once

#include <networktables/NetworkTable.h>
#include <glass/View.h>

#include <memory>

namespace frc5190 {
class Superstructure : public glass::View {
 public:
  explicit Superstructure(std::shared_ptr<nt::NetworkTable> nt) : nt_{nt} {}
  void Display() override;

 private:
  std::shared_ptr<nt::NetworkTable> nt_;
};
}  // namespace frc5190