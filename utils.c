#include <math.h>

const int BALL_FOUND = 1;
const int BALL_NOT_FOUND = 0;
const int OPPONENTS_FOUND = 1;
const int BOUNDARIES_FOUND = 1;

int moving_forward()
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