/*Update the following functions:
- void print_scene(const VehicleType &ego_vehicle, const NeighborVehiclesType &vehicles);
        Update the distance slices to 10m instead of 20m
        Add the console output of the ego vehicle speed

           L     C     R
100     |     |     |     |
90      |     |     |     |
80      |  V  |     |     |
70      |     |     |     |
60      |     |  V  |     |
50      |     |     |     |
40      |     |     |  V  |
30      |     |     |     |
20      |     |     |     |
10      |     |     |     |
0       |     |  E  |     |
-10     |     |     |     |
-20     |  V  |     |  V  |
-30     |     |     |     |
-40     |     |  V  |     |
-50     |     |     |     |
-60     |     |     |     |
-70     |     |     |     |
-80     |     |     |     |
-90     |     |     |     |
-100    |     |     |     |

E: (37.5 mps)

Implement the following functions:
- float mps_to_kph(const float mps);
    Convert the m/s input to km/h value

- void decrease_speed(VehicleType &ego_vehicle);
    Decrease the ego vehicle speed by the constant: LONGITUDINAL_DIFFERENCE_PERCENTAGE

- void longitudinal_control(const VehicleType &front_vehicle, VehicleType &ego_vehicle);
    The ego vehicle needs to decrease_speed whenever
        There is a vehicle in front of the ego vehicle
        and the distance is below half speed (kph, "halbe tacho")
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

    print_scene(ego_vehicle, vehicles);

    auto input = char{};
    std::cout << "Start simulation? y - yes / n - no: ";
    std::cin >> input;

    while(input == 'y' || input == 'Y')
    {
        clear_console();

        compute_future_state(ego_vehicle, vehicles, 0.100F);
        print_scene(ego_vehicle, vehicles);
        longitudinal_control(vehicles.vehicles_center_lane[0], ego_vehicle);

        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }

    return 0;
}
