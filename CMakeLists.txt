# Set the minimum CMake version required to build this project.
cmake_minimum_required(VERSION 3.16)

# The name of the project.
project(MissionControl)

# Add the allwpilib subdirectory to pull in wpigui, imgui, et al.
add_subdirectory(allwpilib)

# Add our main executable.
file(GLOB missioncontrol_src src/*.cc)
add_executable(MissionControl ${missioncontrol_src})

# Set include directories.
target_include_directories(MissionControl PRIVATE include)

# Add target link libraries for executable.
set_target_properties(MissionControl PROPERTIES LINK_FLAGS "-framework Metal -framework QuartzCore")
target_link_libraries(MissionControl PRIVATE libglassnt libglass ntcore wpimath wpiutil wpigui imgui)
