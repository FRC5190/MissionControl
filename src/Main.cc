// This Source Code Form is subject to the terms of the Mozilla Public
// License, v. 2.0. If a copy of the MPL was not distributed with this
// file, You can obtain one at https://mozilla.org/MPL/2.0/.

#include <algorithm>
#include <iostream>
#include <memory>

#include <Drivetrain.h>
#include <Hood.h>
#include <Shooter.h>
#include <Superstructure.h>
#include <Turret.h>
#include <glass/Context.h>
#include <glass/MainMenuBar.h>
#include <glass/Storage.h>
#include <glass/Window.h>
#include <glass/WindowManager.h>
#include <imgui.h>
#include <networktables/NetworkTableEntry.h>
#include <networktables/NetworkTableInstance.h>
#include <networktables/TableEntryListener.h>
#include <wpigui.h>
#include "Intake.h"
#include "Climber.h"

using namespace frc5190;

namespace gui = wpi::gui;

static std::unique_ptr<glass::WindowManager> window_manager_;

static glass::Window* drivetrain_;
static glass::Window* turret_;
static glass::Window* shooter_;
static glass::Window* hood_;
static glass::Window* intake_;
static glass::Window* climber_;
static glass::Window* superstructure_;

static glass::MainMenuBar main_menu_bar_;

void Application(std::string_view save_dir) {
  // Create wpigui and Glass contexts.
  gui::CreateContext();
  glass::CreateContext();

  // Set the storage name and location.
  glass::SetStorageName("Mission Control");
  glass::SetStorageDir(save_dir.empty() ? gui::GetPlatformSaveFileDir()
                                        : save_dir);

  // Create global NT instance.
  nt::NetworkTableInstance inst = nt::NetworkTableInstance::GetDefault();
  inst.StartClientTeam(5190);
  std::shared_ptr<nt::NetworkTable> robot_table = inst.GetTable("robot");

  // Initialize window manager and add views.
  auto& storage = glass::GetStorageRoot().GetChild("Mission Control");
  window_manager_ = std::make_unique<glass::WindowManager>(storage);
  window_manager_->GlobalInit();

  drivetrain_ = window_manager_->AddWindow(
      "Drivetrain", std::make_unique<Drivetrain>(robot_table));
  turret_ = window_manager_->AddWindow("Turret",
                                       std::make_unique<Turret>(robot_table));
  shooter_ = window_manager_->AddWindow("Shooter",
                                        std::make_unique<Shooter>(robot_table));
  hood_ =
      window_manager_->AddWindow("Hood", std::make_unique<Hood>(robot_table));
  intake_ = window_manager_->AddWindow("Intake",
                                       std::make_unique<Intake>(robot_table));
  climber_ = window_manager_->AddWindow("Climber",
                                        std::make_unique<Climber>(robot_table));
  superstructure_ = window_manager_->AddWindow(
      "Superstructure", std::make_unique<Superstructure>(robot_table));

  // Add menu bar.
  gui::AddLateExecute([] {
    ImGui::BeginMainMenuBar();
    main_menu_bar_.WorkspaceMenu();
    gui::EmitViewMenu();
    ImGui::EndMainMenuBar();
  });

  // Initialize and run GUI.
  gui::Initialize("Mission Control", 1920, 1080);
  gui::Main();

  // Shutdown.
  glass::DestroyContext();
  gui::DestroyContext();
}

int main() {
  Application("");
  return 0;
}