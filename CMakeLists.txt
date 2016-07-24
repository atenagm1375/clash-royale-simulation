cmake_minimum_required(VERSION 3.3)
project(Clash_Royale)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(CMAKE_AUTOMOC ON)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(SOURCE_FILES main.cpp)

add_executable(Clash_Royale ${SOURCE_FILES} "header files/MainWindow.h" "cpp files/MainWindow.cpp" "header files/FirstPage.h" "cpp files/FirstPage.cpp" "header files/Settings.h" "cpp files/Settings.cpp" "header files/GameOptions.h" "cpp files/GameOptions.cpp" "header files/SelectCard.h" "cpp files/SelectCard.cpp" "cpp files/Card.cpp" "header files/Card.h" "cpp files/LavaHound.cpp" "header files/LavaHound.h" "header files/IceWizard.h" "cpp files/IceWizard.cpp" "header files/Balloon.h" "cpp files/Balloon.cpp" "header files/DarkPrince.h" "cpp files/DarkPrince.cpp" "header files/HogRider.h" "cpp files/HogRider.cpp" "cpp files/MinionHorde.cpp" "header files/MinionHorde.h" "header files/Valkyrie.h" "cpp files/Valkyrie.cpp" "header files/Miner.h" "cpp files/Miner.cpp" "header files/Witch.h" "cpp files/Witch.cpp" "header files/RoyalGiant.h" "cpp files/RoyalGiant.cpp" "header files/Mirror.h" "cpp files/Mirror.cpp" "header files/Zap.h" "cpp files/Zap.cpp" "header files/Rage.h" "cpp files/Rage.cpp" "header files/InfernoTower.h" "cpp files/InfernoTower.cpp" "header files/UsingFurnace.h" "cpp files/UsingFurnace.cpp" "header files/map1.h" "cpp files/map1.cpp" "header files/map2.h" "cpp files/map2.cpp" "header files/PausePage.h" "cpp files/PausePage.cpp" "header files/Tower.h" "cpp files/Tower.cpp" "header files/Fire.h" "cpp files/Fire.cpp" "header files/Object.h" "cpp files/Object.cpp" "header files/Specifications.h" "header files/FireSpirits.h" "cpp files/FireSpirits.cpp" "header files/Skeleton.h" "cpp files/Skeleton.cpp" "header files/LavaPups.h" "cpp files/LavaPups.cpp" "header files/CardManagement.h" "header files/CardManagement.h" "cpp files/CardManagement.cpp" "header files/WinnerAnnouncement.h" "cpp files/WinnerAnnouncement.cpp")

find_package(Qt5Core REQUIRED)
find_package(Qt5Multimedia REQUIRED)
find_package(Qt5Widgets REQUIRED)
find_package(Qt5Gui REQUIRED)

qt5_use_modules(Clash_Royale Core Multimedia Widgets Gui)

target_link_libraries(Clash_Royale Qt5::Core Qt5::Multimedia Qt5::Widgets Qt5::Gui)