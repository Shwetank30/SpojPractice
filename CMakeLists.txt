# CMakeList.txt : CMake project for SpojPractice, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("SpojPractice")

# Add source to this project's executable.
add_executable (Test "Test.cpp")
add_executable (Prime1 "Prime1.cpp")
add_executable (SieveOfEratosthenes "SieveOfEratosthenes.cpp")
add_executable (SegmentedSieve "SegmentedSieve.cpp")
add_executable (Onp "Onp.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Test PROPERTY CXX_STANDARD 20)
  set_property(TARGET Prime1 PROPERTY CXX_STANDARD 20)
  set_property(TARGET SieveOfEratosthenes PROPERTY CXX_STANDARD 20)
  set_property(TARGET SegmentedSieve PROPERTY CXX_STANDARD 20)
  set_property(TARGET Onp PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
