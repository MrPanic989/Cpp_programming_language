/*Update the following functions:
- void print_scene(const VehicleType &ego_vehicle, const NeighborVehiclesType &vehicles);
    Such that the ego vehicle can be displayed on every lane not only the center lane

Implement the following functions:
- const VehicleType *get_vehicle_array(const LaneAssociationType lane,
                                        const NeighborVehiclesType &vehicles);

        Return the vehicle array for a certain lane
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

        compute_future_state(ego_vehicle, vehicles, 0.100F);
        print_scene(ego_vehicle, vehicles);

        const auto ego_lane_vehicles = get_vehicle_array(ego_vehicle.lane, vehicles);
        longitudinal_control(ego_lane_vehicles[0], ego_vehicle);

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}
