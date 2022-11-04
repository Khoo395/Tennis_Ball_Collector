float dist_ft;
float dist_bl;
float dist_br;
float dist_back;
int dispense_limit_switch_voltage;
const bool BALL_FOUND = true;
const bool BALL_NOT_FOUND = false;
const bool BALL_COLLECTED = true;
const bool BALL_NOT_COLLECTED = false;
// according to sharp sensor calibration (search distance)
int top_detection_value = 1100;
int bottom_detection_value = 550;
int compass_status;
int dispense_limit_status;
bool ball_identified;

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
BoundarySide line_sensor_status;

float read_sharp_front_top()
{
    dist_ft = SensorValue(sharp_front_top);
    writeDebugStreamLine("top: %d", dist_ft);
    return dist_ft;
    // return SensorValue(sharp_front_top);
}

float read_sharp_front_bottom_l()
{
    dist_bl = SensorValue(sharp_front_bottom_l);
    writeDebugStreamLine("bottom left: %d", dist_bl);
    return dist_bl;
    // return SensorValue(sharp_front_bottom_l);
}

float read_sharp_front_bottom_r()
{
    dist_br = SensorValue(sharp_front_bottom_r);
    writeDebugStreamLine("bottom right: %d", dist_br);
    return dist_br;
    // return SensorValue(sharp_front_bottom_r);
}

float read_short_sharp()
{
    dist_back = SensorValue(sharp_short);
    return dist_back;
}

int read_dispense_limit_switch()
{
    dispense_limit_switch_voltage = SensorValue(dispense_limit_switch);
    if (dispense_limit_switch_voltage != 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int is_ball_on_vehicle()
{
    if (SensorValue(ball_collection_limit) == 0)
    {
        return BALL_COLLECTED;
    }
    else
    {
        return BALL_NOT_COLLECTED;
    }
}
BoundarySide scan_boundary()
{
    int frontLeft = SensorValue(front_l_line);
    int frontRight = SensorValue(front_r_line);
    int backLeft = SensorValue(back_l_line);
    int backRight = SensorValue(back_r_line);

    if (frontLeft > 1800)
    {
        writeDebugStreamLine("%s", "FRONT_LEFT");
        return FRONT_LEFT;
    }
    else if (frontRight == 1)
    {
        writeDebugStreamLine("%s", "FRONT_RIGHT");
        return FRONT_RIGHT;
    }
    else if (backLeft == 1)
    {
        writeDebugStreamLine("%s", "BACK_LEFT");
        return BACK_LEFT;
    }
    else if (backRight == 1)
    {
        writeDebugStreamLine("%s", "BACK_RIGHT");
        return BACK_RIGHT;
    }
    else
    {
        writeDebugStreamLine("%s", "NO_BOUNDARY_DETECTED");
        return NO_BOUNDARY_DETECTED;
    }
}

Orientation read_compass()
{
    int pin1 = SensorValue(compass1);
    int pin2 = SensorValue(compass2);
    int pin3 = SensorValue(compass3);
    int pin4 = SensorValue(compass4);
    int combination = pin1 * 1000 + pin2 * 100 + pin3 * 10 + pin4;

    switch (combination)
    {
    case 1110:
        writeDebugStreamLine("%s", "NORTH");
        return NORTH;
    case 1100:
        writeDebugStreamLine("%s", "NORTH_EAST");
        return NORTH_EAST;
    case 1101:
        writeDebugStreamLine("%s", "EAST");
        return EAST;
    case 1001:
        writeDebugStreamLine("%s", "SOUTH_EAST");
        return SOUTH_EAST;
    case 1011:
        writeDebugStreamLine("%s", "SOUTH");
        return SOUTH;
    case 0011:
        writeDebugStreamLine("%s", "SOUTH_WEST");
        return SOUTH_WEST;
    case 0111:
        writeDebugStreamLine("%s", "WEST");
        return WEST;
    case 0110:
        writeDebugStreamLine("%s", "NORTH_WEST");
        return NORTH_WEST;
    default:
        writeDebugStreamLine("%s", "INVALID_COMBINATION");
        return INVALID_COMBINATION;
    }
}

bool scan_ball()
{
    if (SensorValue(sharp_front_bottom_l) > bottom_detection_value || SensorValue(sharp_front_bottom_r) > bottom_detection_value)
    {
        if (SensorValue(sharp_front_top) < top_detection_value)
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
