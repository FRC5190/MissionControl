// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#include "Plot.h"

#include <implot_internal.h>

#include <iostream>

#include <fmt/core.h>
#include <imgui.h>
#include <implot.h>
#include <networktables/NetworkTable.h>
#include <wpi/numbers>
#include <wpi/timestamp.h>

#include "Keys.h"

using namespace frc5190;

ImPlotPoint ExtractPlotPoint(void* data, int idx) {
  return static_cast<ImPlotPoint*>(data)[idx];
}

Plot::Plot(std::shared_ptr<nt::NetworkTable> nt) : nt_{nt} {
  start_time_ = wpi::Now() * 1.0e-6;
}

void Plot::Display() {
  // Get shooter speed and desired shooter speed.
  double actual_shooter_speed =
      nt_->GetNumber(keys::kShooterVelocity, 0) * 60 / 2 / wpi::numbers::pi;
  double wanted_shooter_speed = nt_->GetNumber(keys::kShooterSpeedSetpoint, 0) *
                                60 / 2 / wpi::numbers::pi;

  // Get hood angle and desired hood angle.
  double actual_hood_angle =
      nt_->GetNumber(keys::kHoodPosition, 0) * 180 / wpi::numbers::pi;
  double wanted_hood_angle =
      nt_->GetNumber(keys::kHoodAngleSetpoint, 0) * 180 / wpi::numbers::pi;

  // Get current time.
  double now = wpi::Now() * 1.0e-6 - start_time_;

  // Add data to plot series.
  if (size_ < kMaxSize) {
    actual_shooter_speed_[size_] = ImPlotPoint{now, actual_shooter_speed};
    wanted_shooter_speed_[size_] = ImPlotPoint{now, wanted_shooter_speed};
    actual_hood_angle_[size_] = ImPlotPoint{now, actual_hood_angle};
    wanted_hood_angle_[size_] = ImPlotPoint{now, wanted_hood_angle};
    size_++;
  } else {
    actual_shooter_speed_[offset_] = ImPlotPoint{now, actual_shooter_speed};
    wanted_shooter_speed_[offset_] = ImPlotPoint{now, wanted_shooter_speed};
    actual_hood_angle_[offset_] = ImPlotPoint{now, actual_hood_angle};
    wanted_hood_angle_[offset_] = ImPlotPoint{now, wanted_hood_angle};
    offset_ = (offset_ + 1) % kMaxSize;
  }

  // Construct plots.
  ImPlot::SetNextAxesLimits(now - kViewDuration, now, 0, 5000,
                            ImPlotCond_Always);
  if (ImPlot::BeginPlot("Shooter")) {
    ImPlot::PlotLineG("Wanted Speed", &ExtractPlotPoint, wanted_shooter_speed_,
                      size_);
    ImPlot::PlotLineG("Actual Speed", &ExtractPlotPoint, actual_shooter_speed_,
                      size_);
    ImPlot::EndPlot();
  }

  ImPlot::SetNextAxesLimits(now - kViewDuration, now, 0, 70, ImPlotCond_Always);
  if (ImPlot::BeginPlot("Hood")) {
    ImPlot::PlotLineG("Wanted Angle", &ExtractPlotPoint, wanted_hood_angle_,
                      size_);
    ImPlot::PlotLineG("Actual Angle", &ExtractPlotPoint, actual_hood_angle_,
                      size_);
    ImPlot::EndPlot();
  }
}
