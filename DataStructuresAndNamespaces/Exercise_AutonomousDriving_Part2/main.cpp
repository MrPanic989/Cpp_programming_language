/*Implement the following functions:
- void print_scene(const VehicleType &ego_vehicle, const NeighborVehiclesType &vehicles);
    -Output the vehicles at their postion (regarding the relative distance and lane)
    -Every row of the console output has a size of 20 meters (this should be modifiable)

           L     C     R
100     |     |     |     |
80      |  V  |     |     |
60      |     |  V  |     |
40      |     |     |  V  |
20      |     |     |     |
0       |     |  E  |     |
-20     |  V  |     |  V  |
-40     |     |  V  |     |
-60     |     |     |     |
-80     |     |     |     |
-100    |     |     |     |

- void compute_future_state(const VehicleType &ego_vehicle, NeighborVehiclesType &vehicles,
                            const float seconds);
    -Compute the position of a vehicles in n seconds
    -Assuming the vehicle has constant velocity (no change in the speed)
    -Note: The future distance of a vehicle is dependent on the ego vehicle

Example:
- Other Vehicle V1:
    Distance = 100m
    Speed = 30 m/s
- Ego Vehicle E:
    Speed = 25 m/s
- Predict the distance in 1 second
    V1 will drive 1s * 30m/s = 30m
    E will drive 1s * 25m/s = 25m
    The new relative distance will be 100 + (25 - 30) = 95
*/
#include <iostream>

#include "AdTypes.hpp"
#include "AdFunctions.hpp"

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
    std::cout << "Compute forward(1sec)? y - yes / n - no: ";
    std::cin >> input;

    while(input == 'y' || input == 'Y')
    {
        compute_future_state(ego_vehicle, vehicles, 1);
        print_scene(ego_vehicle, vehicles);

        std::cout << "Compute forward(1sec)? y - yes / n - no: ";
        std::cin >> input;
    }

    return 0;
}
