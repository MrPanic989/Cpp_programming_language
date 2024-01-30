#include <cstdint>

#include "lib.h"

float convert_milliseconds_to_seconds(const float Millisconds)
{
    return Millisconds / 1000.0f;
}

float convert_seconds_to_minutes(const float seconds)
{
    return seconds / 60.0f;
}

float convert_minutes_to_hours(const float Minutes)
{
    return Minutes / 60.0f;
}

float convert_milliseconds_to_minutes(const float Millisconds)
{
    float seconds = convert_milliseconds_to_seconds(Millisconds);

    return seconds / 60.0f;
}

float convert_milliseconds_to_hours(const float Millisconds)
{
    float minutes = convert_milliseconds_to_minutes(Millisconds);

    return minutes / 60.0f;
}

float convert_seconds_to_hours(const float seconds)
{
    float minutes = convert_seconds_to_minutes(seconds);

    return minutes / 60.0f;
}
