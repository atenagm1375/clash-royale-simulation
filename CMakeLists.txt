cmake_minimum_required(VERSION 3.3)
project(Clash_Royale)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_AUTOMOC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SOURCE_FILES main.cpp)

add_executable(Clash_Royale ${SOURCE_FILES} "header files/MainWindow.h" "cpp files/MainWindow.cpp" "header files/FirstPage.h" "cpp files/FirstPage.cpp" "header files/Settings.h" "cpp files/Settings.cpp" "header files/GameOptions.h" "cpp files/GameOptions.cpp" "header files/SelectCard.h" "cpp files/SelectCard.cpp")

find_package(Qt5Core REQUIRED)
find_package(Qt5Multimedia REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)

qt5_use_modules(Clash_Royale Core Multimedia Widgets Gui)

target_link_libraries(Clash_Royale Qt5::Core Qt5::Multimedia Qt5::Widgets Qt5::Gui)