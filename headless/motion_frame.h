// SPDX-License-Identifier: GPL-3.0-or-later
#pragma once

namespace Eden {
// The frame a controller's motion reaches the game in. Eden's (a Pro Controller's, and a Joy-Con's
// as it sits on the console): x to the right, y toward the shoulder buttons, z out of the face;
// lying face up, acceleration reads (0, 0, -1) G.
//
// Native: the source already reports in that frame (a DualSense as a Pro Controller, and a real
// Joy-Con, whose own report is in its frame on the console).
// JoyconGrip: a DualSense standing in for a single Joy-Con. Motion games (Just Dance) want the
// Joy-Con upright in the right hand, palm on its back, buttons toward the TV. The DualSense's
// counterpart is the same hand around its right grip, buttons toward the TV, the controller
// standing up out of the fist: its right edge points down, its shoulders toward the left. The
// Joy-Con's top points up and its rail to the left, so the frames differ by a quarter turn about
// the face: x' = y, y' = -x, z' = z. Gravity in that grip, (1, 0, 0) on the DualSense, reaches
// the game as (0, -1, 0): a Joy-Con standing upright.
enum class MotionFrame : unsigned char { Native, JoyconGrip };

struct MotionVector {
    float x{}, y{}, z{};
};

// For gyro and acceleration alike: a rotation turns both the same way.
constexpr MotionVector ToMotionFrame(MotionFrame frame, MotionVector v) {
    if (frame == MotionFrame::JoyconGrip) return {v.y, -v.x, v.z};
    return v;
}
} // namespace Eden
