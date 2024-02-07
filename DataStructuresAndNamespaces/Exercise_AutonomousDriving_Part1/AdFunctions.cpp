#include <iostream>

#include "AdFunctions.hpp"

float kph_to_mps(const float kph)
{
    return kph / 3.6f;
}

void init_ego_vehicle(VehicleType &ego_vehicle)
{
    ego_vehicle.id = EGO_VEHICLE_ID;
    ego_vehicle.lane = LaneAssociationType::CENTER_LANE;
    ego_vehicle.rel_distance = EGO_VEHICLE_POSITION;
    ego_vehicle.speed_mps = kph_to_mps(135.0f);
}

//helper function to initialize the neighbor vehicles
void init_vehicle(VehicleType &vehicle, const std::int32_t id, const float speed_kph,
                  const float distance, const LaneAssociationType lane)
{
    vehicle.id = id;
    vehicle.lane = lane;
    vehicle.rel_distance = distance;
    vehicle.speed_mps = kph_to_mps(speed_kph);
}

void init_vehicles(NeighborVehiclesType &vehicles)
{
    init_vehicle(vehicles.vehicles_left_lane[0], 0, 130.0f, 80.0f, LaneAssociationType::LEFT_LANE);
    init_vehicle(vehicles.vehicles_left_lane[1], 1, 80.0f, -20.0f, LaneAssociationType::LEFT_LANE);
    init_vehicle(vehicles.vehicles_center_lane[0], 2, 80.0f, 50.0f, LaneAssociationType::CENTER_LANE);
    init_vehicle(vehicles.vehicles_center_lane[1], 3, 120.0f, -50.0f, LaneAssociationType::CENTER_LANE);
    init_vehicle(vehicles.vehicles_right_lane[0], 4, 110.0f, 30.0f, LaneAssociationType::RIGHT_LANE);
    init_vehicle(vehicles.vehicles_right_lane[1], 5, 90.0f, -30.0f, LaneAssociationType::RIGHT_LANE);
}

void print_vehicle(const VehicleType &vehicle)
{
    std::cout << "ID: " << vehicle.id << '\n';
    std::cout << "Speed (m/s): " << vehicle.speed_mps << '\n';
    std::cout << "Distance (m): " << vehicle.rel_distance << '\n';
    std::cout << "Lane: " << static_cast<std::int32_t>(vehicle.lane) << '\n';
}

void print_neighbor_vehicles(const NeighborVehiclesType &vehicles)
{
    print_vehicle(vehicles.vehicles_left_lane[0]);
    print_vehicle(vehicles.vehicles_left_lane[1]);
    print_vehicle(vehicles.vehicles_center_lane[0]);
    print_vehicle(vehicles.vehicles_center_lane[1]);
    print_vehicle(vehicles.vehicles_right_lane[0]);
    print_vehicle(vehicles.vehicles_right_lane[1]);
}
