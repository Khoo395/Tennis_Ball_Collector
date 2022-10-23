#include <math.h>

const bool BALL_FOUND = true;
const bool BALL_NOT_FOUND = false;
const bool OPPONENTS_FOUND = true;
const bool BOUNDARIES_FOUND = true;
const bool BALL_COLLECTED = false;
const bool BALL_DISPENSED = false;

bool moving_forward()
{
    clearTimer(T1); // start the timer
    while (time1(T1) < 10000)
    {
        if (scan_ball() == BALL_FOUND)
        {
            return BALL_FOUND;
        }
        else if (scan_boundaries == BOUNDARIES_FOUND)
        {
            avoid_boundaries();
            return BALL_NOT_FOUND;
        }
        else if (scan_opponents < XXXX)
        {
            avoid_opponents();
            return BALL_NOT_FOUND;
        }
    }
    return BALL_NOT_FOUND;
}

float IRSensorReading(int pin_number)
{
    float voltage = SensorValue(pin_number) / 4096 * 5;
    float distance = p return distance;
}

void scan_ball()
{
}

void scan_opponents()
{
}

void scan_boundaries()
{
}

void avoid_boundaries()
{
    if (IRSensorReading())
}

bool starting_procedure()
{
}

bool spin_search()
{
}

bool collect_ball()
{
}

void dispense_ball()
{
}