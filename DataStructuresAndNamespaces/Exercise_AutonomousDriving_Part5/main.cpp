/*Implement the following functions:
- LaneAssociationType get_lane_change_request(const VehicleType &ego_vehicle,
    const NeighborVehiclesType &vehicles);
        Send a lane change request to avoid a crash of the ego vehicle with the
        incoming (behind) vehicle
        Change to the neighbor lane that has the largest gap (free space)
        Only if: GapSize >= EgoSpeed(kph) / 5

- bool lateral_control(const LaneAssociationType lane_change_request, VehicleType &ego_vehicle);
    If there is a request from get_lane_change_request do a lane change
*/
#include <chrono>
#include <cstring>
#include <iostream>
#include <numeric>
#include <thread>

#include "AdFunctions.hpp"
#include "AdTypes.hpp"

#include "utils.hpp"

int main(void)
{
    auto ego_vehicle = VehicleType{};   //Initialize all attributs of the structure with 0
    auto vehicles = NeighborVehiclesType{};

    init_ego_vehicle(ego_vehicle);
    init_vehicles(vehicles);

    print_vehicle(ego_vehicle);
    print_neighbor_vehicles(vehicles);

    auto input = char{};
    std::cout << "Start simulation? y - yes / n - no: ";
    std::cin >> input;

    while(input == 'y' || input == 'Y')
    {
        clear_console();

        print_scene(ego_vehicle, vehicles);
        compute_future_state(ego_vehicle, vehicles, 0.100F);

        const auto ego_lane_vehicles = get_vehicle_array(ego_vehicle.lane, vehicles);
        longitudinal_control(ego_lane_vehicles[0], ego_vehicle);

        const auto lane_change_request = get_lane_change_request(ego_vehicle, vehicles);
        const auto lane_change_executed = lateral_control(lane_change_request, ego_vehicle);

        if(lane_change_executed)
        {
            std::cout << "Executed lane change!" << '\n';
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}
