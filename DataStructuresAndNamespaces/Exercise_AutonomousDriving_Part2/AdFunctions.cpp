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

void print_vehicle_on_lane(const VehicleType* const vehicle,
                           const float range_m,
                           const float offset_m,
                           char* string,
                           std::size_t &idx)
{
    if ((vehicle != nullptr) && (range_m >= vehicle->rel_distance) &&
        (vehicle->rel_distance > (range_m - offset_m)))
    {
        string[1] = 'V';
        idx++;
    }
    else if ((vehicle != nullptr) &&
             (std::abs(vehicle->rel_distance) > VIEW_RANGE_M))
    {
        idx++;
    }
}

void print_scene(const VehicleType &ego_vehicle, const NeighborVehiclesType &vehicles)
{
    std::cout << "    \t   L     C     R  \n";

    auto left_idx = std::size_t{0};
    auto center_idx = std::size_t{0};
    auto right_idx = std::size_t{0};

    const auto offset_m = std::uint32_t{20};
    const auto view_range_m = static_cast<std::int32_t>(VIEW_RANGE_M);

    for (auto i = view_range_m; i >= -view_range_m; i -= offset_m)
    {
        const auto range_m = static_cast<float>(i);

        char left_string[]{"   "};
        char center_string[]{"   "};
        char right_string[]{"   "};

        //E.g. i = 60, rel_distance = -18.5: (i >= distance) is true but (distance > (i - offset = 40)) is false
        //E.g. i = 0, rel_distance = -18.5: first condition is true AND -18.5 > (0 - 20 = -20) is also true.
        //If the vehicle distance is in the ragne of the if() statement, then put the vehicle in lane
        if ((range_m >= ego_vehicle.rel_distance) && (ego_vehicle.rel_distance > (range_m - offset_m)))
        {
            center_string[1] = 'E';
        }

        if (left_idx < NUM_VEHICLES_ON_LANE)
        {
            print_vehicle_on_lane(&vehicles.vehicles_left_lane[left_idx],
                                  range_m,
                                  offset_m,
                                  left_string,
                                  left_idx);
        }
        if (center_idx < NUM_VEHICLES_ON_LANE)
        {
            print_vehicle_on_lane(&vehicles.vehicles_center_lane[center_idx],
                                  range_m,
                                  offset_m,
                                  center_string,
                                  center_idx);
        }
        if (right_idx < NUM_VEHICLES_ON_LANE)
        {
            print_vehicle_on_lane(&vehicles.vehicles_right_lane[right_idx],
                                  range_m,
                                  offset_m,
                                  right_string,
                                  right_idx);
        }

        std::cout << i << "\t| " << left_string << " | " << center_string
                  << " | " << right_string << " | \n";
    }
}

void compute_future_distance(VehicleType &vehicle,
                             const float ego_driven_distance,
                             const float seconds)
{
    const auto driven_distance = vehicle.speed_mps * seconds;
    vehicle.rel_distance += (driven_distance - ego_driven_distance);
}

void compute_future_state(const VehicleType &ego_vehicle,
                          NeighborVehiclesType &vehicles,
                          const float seconds)
{
    //We want to compute the relative distance of all the other vehicles to our vehicle,
    //so we have to compute where our vehicle will be in n-seconds and pass on that
    //information to other vehicles in order to compute their distance to us
    const auto ego_driven_distance = ego_vehicle.speed_mps * seconds;

    compute_future_distance(vehicles.vehicles_left_lane[0],
                            ego_driven_distance,
                            seconds);
    compute_future_distance(vehicles.vehicles_left_lane[1],
                            ego_driven_distance,
                            seconds);
    compute_future_distance(vehicles.vehicles_center_lane[0],
                            ego_driven_distance,
                            seconds);
    compute_future_distance(vehicles.vehicles_center_lane[1],
                            ego_driven_distance,
                            seconds);
    compute_future_distance(vehicles.vehicles_right_lane[0],
                            ego_driven_distance,
                            seconds);
    compute_future_distance(vehicles.vehicles_right_lane[1],
                            ego_driven_distance,
                            seconds);
}
