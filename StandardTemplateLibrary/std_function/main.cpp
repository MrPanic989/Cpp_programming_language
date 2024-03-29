#include <cstdint>
#include <functional>
#include <iostream>
#include <vector>
//function as parameter           //return type //parameter list
std::int32_t f(const std::function<std::int32_t(const std::int32_t)> &callback)
{
    return callback(2);
}

std::int32_t h(const std::int32_t v)
{
    return v * 2;
}

int main()
{                            //return (callback(2))          2 * 2
    const auto result1 = f([](const std::int32_t v) { return v * 2; });
    std::cout << result1 << '\n';   // 2 * 2 = 4

    auto l = [](const std::int32_t v) { return v * 2; };
    const auto result2 = f(l);
    std::cout << result2 << '\n';   // 2 * 2 = 4

    const auto result3 = f(h);
    std::cout << result3 << '\n';   // 2 * 2 = 4

    const std::int32_t threshold = 2;
                //vector of functions //return  //parameter
    auto fns = std::vector<std::function<bool(const std::int32_t)>>{
        [&threshold](const std::int32_t v) { return v > threshold; },
        [&threshold](const std::int32_t v) { return v < threshold; },
        [&threshold](const std::int32_t v) { return v == threshold; },
        [&threshold](const std::int32_t v) { return v != threshold; },
        [&threshold](const std::int32_t v) { return v >= threshold; },
        [&threshold](const std::int32_t v) { return v <= threshold; },
    };

    for (const auto &fn : fns)
    {
        std::cout << std::boolalpha << fn(1) << '\n';
    }

    return 0;
}
