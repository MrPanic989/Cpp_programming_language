#pragma once

#include <cstdint>

constexpr static auto NUM_VEHICLES_ON_LANE = std::size_t{2};
constexpr static auto EGO_VEHICLE_ID = std::int32_t{-1};
constexpr static auto EGO_VEHICLE_POSITION = float{0.0f};
constexpr static auto VIEW_RANGE_M = 100.0f;
constexpr static auto LONGITUDINAL_DIFFERENCE_PERCENTAGE = 0.05F;
