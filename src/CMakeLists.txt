# CMakeList.txt : CMake project for 31-1-using-smart-pointer, include source and define
# project specific logic here.
#

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

# Add source to this project's executable.
add_executable (31-1-using-smart-pointer "main.cpp" ${MY_INCLUDE_DIR}/dog.h "dog.cpp" ${MY_INCLUDE_DIR}/toy.h "toy.cpp")

target_include_directories(31-1-using-smart-pointer PUBLIC ${CMAKE_SOURCE_DIR}/include)

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET 31-1-using-smart-pointer PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
