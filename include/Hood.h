#pragma once

#include <networktables/NetworkTable.h>
#include <memory>
#include <glass/View.h>

namespace frc5190 {
class Hood : public glass::View {
 public:
  Hood(std::shared_ptr<nt::NetworkTable> nt) : nt_{nt} {}
  void Display() override;

 private:
  std::shared_ptr<nt::NetworkTable> nt_;
};
}  // namespace frc5190