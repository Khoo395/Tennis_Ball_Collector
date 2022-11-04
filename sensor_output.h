// enum
enum Orientation
{
    NORTH,              // 0
    NORTH_EAST,         // 1
    EAST,               // 2
    SOUTH_EAST,         // 3
    SOUTH,              // 4
    SOUTH_WEST,         // 5
    WEST,               // 6
    NORTH_WEST,         // 7
    INVALID_COMBINATION // 8
};

enum BoundarySide
{
    FRONT_LEFT,
    FRONT_RIGHT,
    BACK_LEFT,
    BACK_RIGHT,
    NO_BOUNDARY_DETECTED
};

// sharp sensor parameter
int top_detection_value = 1100;
int bottom_detection_value = 800;

// distance
float dist_ft;
float dist_bl;
float dist_br;
float dist_back;

// ball status
int ball_found = 0;
int ball_collected = 0;

// compass status
int compass_status;
int goal_compass_status;

// limit_switch_status
int dispense_limit_status;
int dispense_limit_switch_voltage; // analog

// line_sensor_status
BoundarySide line_sensor_status;

// spin_search alternation
int spin_CCW = 0;

// // TBC
// const bool BALL_FOUND = true;
// const bool BALL_NOT_FOUND = false;
// const bool BALL_COLLECTED = true;
// const bool BALL_NOT_COLLECTED = false;

void read_sharp_front_top()
{
    dist_ft = SensorValue(sharp_front_top);
    return;
}

void read_sharp_front_bottom_l()
{
    dist_bl = SensorValue(sharp_front_bottom_l);
    return;
}

void read_sharp_front_bottom_r()
{
    dist_br = SensorValue(sharp_front_bottom_r);
    return;
}

void read_short_sharp()
{
    dist_back = SensorValue(sharp_short);
    return;
}

void read_dispense_limit_switch()
{
    // analog limit switch
    dispense_limit_switch_voltage = SensorValue(dispense_limit_switch);
    if (dispense_limit_switch_voltage != 0)
    {
        dispense_limit_status = 1;
        return;
    }
    else
    {
        dispense_limit_status = 0;
        return;
    }
}

void is_ball_on_vehicle()
{
    if (SensorValue(ball_collection_limit) == 0)
    {
        ball_collected = 1;
        return;
    }
    else
    {
        ball_collected = 0;
        return;
    }
}

void scan_boundary()
{
    int frontLeft = SensorValue(front_l_line);
    int frontRight = SensorValue(front_r_line);
    int backLeft = SensorValue(back_l_line);
    int backRight = SensorValue(back_r_line);
    
    if (frontLeft < 800)
    {
        line_sensor_status = FRONT_LEFT;
        return;
    }
    else if (frontRight == 0)
    {
        line_sensor_status = FRONT_RIGHT;
        return;
    }
    else if (backLeft == 0)
    {
        line_sensor_status = BACK_LEFT;
        return;
    }
    else if (backRight == 0)
    {
        line_sensor_status = BACK_RIGHT;
        return;
    }
    else
    {
        line_sensor_status = NO_BOUNDARY_DETECTED;
        return;
    }
}

void read_compass()
{
    int pin1 = SensorValue(compass1);
    int pin2 = SensorValue(compass2);
    int pin3 = SensorValue(compass3);
    int pin4 = SensorValue(compass4);
    int combination = pin1 * 1000 + pin2 * 100 + pin3 * 10 + pin4;

    switch (combination)
    {
    case 1110:
        compass_status = NORTH;
        return;
    case 1100:
        compass_status = NORTH_EAST;
        return;
    case 1101:
        compass_status = EAST;
        return;
    case 1001:
        compass_status = SOUTH_EAST;
        return;
    case 1011:
        compass_status = SOUTH;
        return;
    case 0011:
        compass_status = SOUTH_WEST;
        return;
    case 0111:
        compass_status = WEST;
        return;
    case 0110:
        compass_status = NORTH_WEST;
        return;
    default:
        compass_status = INVALID_COMBINATION;
        return;
    }
}

void scan_ball()
{
    if (SensorValue(sharp_front_bottom_l) > bottom_detection_value || SensorValue(sharp_front_bottom_r) > bottom_detection_value)
    {
        if (SensorValue(sharp_front_top) < top_detection_value)
        {
            ball_found = 1;
            return;
        }
        else
        {
            ball_found = 0;
            return;
        }
    }
    else
    {
        ball_found = 0;
        return;
    }
}
