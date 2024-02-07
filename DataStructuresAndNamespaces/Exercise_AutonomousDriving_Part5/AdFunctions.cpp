#include <iostream>
#include <cmath>
#include <cstdint>

#include "AdFunctions.hpp"

float kph_to_mps(const float kph)
{
    return kph / 3.6f;
}

float mps_to_kph(const float mps)
{
    return mps * 3.6F;
}

void init_ego_vehicle(VehicleType &ego_vehicle)
{
    ego_vehicle.id = EGO_VEHICLE_ID;
    ego_vehicle.lane = LaneAssociationType::RIGHT_LANE;
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

void print_vehicle_speed(const VehicleType &vehicle, const char* name)
{
    std::cout.precision(3);
    std::cout << name << " : " << vehicle.speed_mps << " mps";
}

void print_vehicle_on_lane(const VehicleType* const vehicle,
                           const float range_m,
                           const float offset_m,
                           char* string,
                           std::size_t &idx)
{
    if((vehicle != nullptr) && (range_m >= vehicle->rel_distance) &&
        (vehicle->rel_distance > (range_m - offset_m)))
    {
        string[1] = 'V';
        idx++;
    }
    else if((vehicle != nullptr) &&
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

    const auto offset_m = std::uint32_t{10};
    const auto view_range_m = static_cast<std::int32_t>(VIEW_RANGE_M);

    for(auto i = view_range_m; i >= -view_range_m; i -= offset_m)
    {
        const auto range_m = static_cast<float>(i);

        char left_string[]{"   "};
        char center_string[]{"   "};
        char right_string[]{"   "};

        //E.g. i = 60, rel_distance = -18.5: (i >= distance) is true but (distance > (i - offset = 40)) is false
        //E.g. i = 0, rel_distance = -18.5: first condition is true AND -18.5 > (0 - 20 = -20) is also true.
        //If the vehicle distance is in the ragne of the if() statement, then put the vehicle in lane
        if((range_m >= ego_vehicle.rel_distance) && (ego_vehicle.rel_distance > (range_m - offset_m)))
        {
            switch (ego_vehicle.lane)
            {
                case LaneAssociationType::LEFT_LANE:
                {
                    left_string[1] = 'E';
                    break;
                }
                case LaneAssociationType::CENTER_LANE:
                {
                    center_string[1] = 'E';
                    break;
                }
                case LaneAssociationType::RIGHT_LANE:
                {
                    right_string[1] = 'E';
                    break;
                }
                case LaneAssociationType::UNKNOWN_LANE:
                default:
                {
                    break;
                }
            }
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

    std::cout << '\n';
    print_vehicle_speed(ego_vehicle, "E");
    std::cout << '\n';
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

void decrease_speed(VehicleType &ego_vehicle)
{
    const auto decrease_mps =
        ego_vehicle.speed_mps * LONGITUDINAL_DIFFERENCE_PERCENTAGE;

    if((ego_vehicle.speed_mps - decrease_mps) >= 0.0F)
    {
        ego_vehicle.speed_mps -= decrease_mps;
    }
}

void longitudinal_control(const VehicleType &front_vehicle, VehicleType &ego_vehicle)
{
    const auto minimal_distance_m = mps_to_kph(ego_vehicle.speed_mps) / 2.0F;
    const auto front_distance_m = front_vehicle.rel_distance;

    if(front_distance_m < 0.0F)
    {
        return;
    }

    if(front_distance_m < minimal_distance_m)
    {
        decrease_speed(ego_vehicle);
    }
}

const VehicleType* get_vehicle_array(const LaneAssociationType lane,
                                     const NeighborVehiclesType &vehicles)
{
    switch(lane)
    {
        case LaneAssociationType::LEFT_LANE:
        {
            return vehicles.vehicles_left_lane;
        }
        case LaneAssociationType::CENTER_LANE:
        {
            return vehicles.vehicles_center_lane;
        }
        case LaneAssociationType::RIGHT_LANE:
        {
            return vehicles.vehicles_right_lane;
        }
        case LaneAssociationType::UNKNOWN_LANE:
        default:
        {
            return nullptr;
        }
    }
}

LaneAssociationType get_lane_change_request(const VehicleType &ego_vehicle,
    const NeighborVehiclesType &vehicles)
{
    const auto ego_lane_vehicles = get_vehicle_array(ego_vehicle.lane, vehicles);
    const auto rear_vehicle = &ego_lane_vehicles[1];

    const auto minimal_distance_m = mps_to_kph(ego_vehicle.speed_mps) / 5.0F;
    const auto rear_distance_m = std::abs(rear_vehicle->rel_distance);

    if(rear_distance_m < minimal_distance_m)
    {
        switch(ego_vehicle.lane)
        {
            case LaneAssociationType::RIGHT_LANE:
            case LaneAssociationType::LEFT_LANE:
            {
                const auto center_vehicles = get_vehicle_array(LaneAssociationType::CENTER_LANE,
                                            vehicles);
                const auto center_gap_size_m =
                    std::abs(center_vehicles[0].rel_distance) -
                    std::abs(center_vehicles[1].rel_distance);

                if (center_gap_size_m > minimal_distance_m)
                {
                    return LaneAssociationType::CENTER_LANE;
                }

                break;
            }
            case LaneAssociationType::CENTER_LANE:
            {
                const auto right_vehicles = get_vehicle_array(LaneAssociationType::RIGHT_LANE,
                                            vehicles);
                const auto right_gap_size_m =
                    std::abs(right_vehicles[0].rel_distance) -
                    std::abs(right_vehicles[1].rel_distance);

                const auto left_vehicles = get_vehicle_array(LaneAssociationType::LEFT_LANE, vehicles);
                const auto left_gap_size_m = std::abs(left_vehicles[0].rel_distance) -
                                            std::abs(left_vehicles[1].rel_distance);

                if(right_gap_size_m > left_gap_size_m && right_gap_size_m > minimal_distance_m)
                {
                    return LaneAssociationType::RIGHT_LANE;
                }
                else if(left_gap_size_m > right_gap_size_m && left_gap_size_m > minimal_distance_m)
                {
                    return LaneAssociationType::LEFT_LANE;
                }
                break;
            }
            case LaneAssociationType::UNKNOWN_LANE:
            default:
            {
                break;
            }
        }
    }

    return ego_vehicle.lane;
}

bool lateral_control(const LaneAssociationType lane_change_request,
                     VehicleType &ego_vehicle)
{
    if (lane_change_request == ego_vehicle.lane)
    {
        return false;
    }

    ego_vehicle.lane = lane_change_request;

    return true;
}
