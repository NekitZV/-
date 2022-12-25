# CMakeList.txt: проект CMake для CMake0; включите исходный код и определения,
# укажите здесь логику для конкретного проекта.
#
cmake_minimum_required (VERSION 3.8)

project ("CMake0")

# Добавьте источник в исполняемый файл этого проекта.
add_executable (CMake0 "CMake0.cpp" "CMake0.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMake0 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Добавьте тесты и целевые объекты, если это необходимо.
