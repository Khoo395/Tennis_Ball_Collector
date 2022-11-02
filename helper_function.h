#include "sensor_output.h"

const float BOTTOM_DIST_THRES = 25;
const float TOP_DIST_THRES = 25;
const int BALL_FOUND = 1;
const int BALL_NOT_FOUND = 0;
float reading_from_bottom_l;
float reading_from_bottom_r;
float reading_from_top;

int scan_ball()
{
    if (read_sharp_front_bottom_l() < BOTTOM_DIST_THRES || read_sharp_front_bottom_r() < BOTTOM_DIST_THRES)
    {
        if (read_sharp_front_top() > TOP_DIST_THRES)
        {
            return BALL_FOUND;
        }
        else
        {
            return BALL_NOT_FOUND;
        }
    }
    else
    {
        return BALL_NOT_FOUND;
    }
}