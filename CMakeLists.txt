# CMakeList.txt : CMake project for SpojPractice, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("SpojPractice")

# Add source to this project's executable.
add_executable (SpojPractice "SpojPractice.h" "Prime1.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET SpojPractice PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
