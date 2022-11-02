#include "motor_control.h"
#include "sensor_output.h"
#include "helper_function.h"

const int BALL_FOUND = 1;
const int BALL_NOT_FOUND = 0;
enum BoundarySide
{
    FRONT_LEFT,
    FRONT_RIGHT,
    BACK_LEFT,
    BACK_RIGHT,
    NO_BOUNDARY_DETECTED
};
void move_forward()
{
    clearTimer(T3);
    while (time1(T3) < 10000)
    {
        move_forward();
        if (scan_ball() == BALL_FOUND)
        {
            return BALL_FOUND;
        }
        else if (scan_boundary() != NO_BOUNDARY_DETECTED)
        {
        }
    }
}