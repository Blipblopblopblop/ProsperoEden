// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once
#include <atomic>

namespace Eden {
// The single Joy-Con side a game that takes only single Joy-Cons gets first: Library > Game
// settings > Single Joy-Con, set when the game starts (main.cpp). Some games take only one side.
// Defined with the controller code it steers: the derived emulated_controller.cpp
// (headless/CMakeLists.txt).
extern std::atomic<bool> prefer_left_joycon;
} // namespace Eden
