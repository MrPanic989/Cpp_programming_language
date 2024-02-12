/*After this exercise, we will implement a feature to load in recorded data of a test drive
of our fictional autonomous car. For that, we will read in JSON files.
To be able to read in the files, update the code:
- Add the argc, **argv to the main function such that the user can input the data path,
inside the data path the following files should be
    -ego_data file
    -vehicle_data file

- If the user does not provide the data path just assume that these files are relative to the main file
    -./data/ego_data.json
    -./data/vehicle_data.json

Note:
In this exercise, we will only update the main.cc file.
For the file paths, use the filesystem library.
*/
#include <chrono>
#include <cstring>
#include <filesystem>
#include <iostream>
#include <numeric>
#include <thread>

#include "AdFunctions.hpp"
#include "AdTypes.hpp"

#include "utils.hpp"

namespace fs = std::filesystem;

int main(int argc, char** argv)
{
    auto data_filepath = fs::path{};

    if(argc < 2)    //If arguments lesser than 2, that means, the user didn't specify any information, then
    {               //use current path, e.g. C++_Strings/Exercise_AutonomousDriving_Part6/ and add data
        data_filepath /= fs::current_path();
        data_filepath /= "data";
    }
    else
    {
        const auto data_path_str = std::string(argv[1]);
        data_filepath = fs::path(data_path_str);
    }

    auto ego_filepath = data_filepath;
    ego_filepath /= "ego_data.json";
    auto vehicle_filepath = data_filepath;
    vehicle_filepath /= "vehicle_data.json";

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
