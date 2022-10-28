#pragma config(Sensor, in1, sharp_front_top, sensorAnalog)
#pragma config(Sensor, in2, sharp_front_bottom_l, sensorAnalog)
#pragma config(Sensor, in3, sharp_front_bottom_r, sensorAnalog)
#pragma config(Sensor, in4, sharp_short, sensorAnalog)
#pragma config(Sensor, in8, compass_power, sensorNone)
#pragma config(Sensor, dgtl1, compass1, sensorDigitalIn)
#pragma config(Sensor, dgtl2, compass2, sensorDigitalIn)
#pragma config(Sensor, dgtl3, compass3, sensorDigitalIn)
#pragma config(Sensor, dgtl4, compass4, sensorDigitalIn)
#pragma config(Sensor, dgtl5, home_limit_l, sensorDigitalIn)
#pragma config(Sensor, dgtl6, home_limit_r, sensorDigitalIn)
#pragma config(Sensor, dgtl7, ball_dispense_1, sensorDigitalIn)
#pragma config(Sensor, dgtl8, ball_dispense_2, sensorDigitalIn)
#pragma config(Sensor, dgtl9, front_l_line, sensorDigitalIn)
#pragma config(Sensor, dgtl10, front_r_line, sensorDigitalIn)
#pragma config(Sensor, dgtl11, back_l_line, sensorDigitalIn)
#pragma config(Sensor, dgtl12, back_r_line, sensorDigitalIn)
#pragma config(Sensor, dgtl13, ball_status, sensorDigitalIn)

enum Orientation {
    NORTH,
    NORTH_EAST,
    EAST,
    SOUTH_EAST,
    SOUTH,
    SOUTH_WEST,
    WEST,
    NORTH_WEST,
    INVALID_COMBINATION
};

enum BoundarySide {
    FRONT_LEFT,
    FRONT_RIGHT,
    BACK_LEFT,
    BACK_RIGHT,
    NO_BOUNDARY_DETECTED
};

float sensor_value_to_distance(float sensor_value){
    float voltage = sensor_value / 4096 * 5;
    return 26.758*pow(voltage,-1.376);
}

float read_sharp_front_top(){
    return sensor_value_to_distance(SensorValue(sharp_front_top));
}

float read_sharp_front_bottom_l(){
    return sensor_value_to_distance(SensorValue(sharp_front_bottom_l));
}

float read_sharp_front_bottom_r(){
    return sensor_value_to_distance(SensorValue(sharp_front_bottom_r));
}

float read_short_sharp(){
    float voltage = SensorValue(sharp_short) / 4096 * 5;
    return 11.16*pow(voltage,-1.191);
}

float is_gate_opened(){
    //Needs adjustment according to limit switch placement and configuration
    return !SensorValue(ball_dispense_1); 
}

float is_gate_closed(){
    //Needs adjustment according to limit switch placement and configuration
    return !SensorValue(ball_dispense_2); 
}

float is_ball_on_vehicle(){
    //Needs adjustment according to limit switch configuration
    return SensorValue(is_ball_on_vehicle); 
}

BoundarySide scan_boundary(){
    int frontLeft = SensorValue(front_l_line);
    int frontRight = SensorValue(front_r_line);
    int backLeft = SensorValue(back_l_line);
    int backRight = SensorValue(back_r_line);

    if(frontLeft == 0){
        return FRONT_LEFT;
    }
    else if(frontRight ==0){
        return FRONT_RIGHT;
    }
    else if(backLeft == 0){
        return BACK_LEFT;
    }
    else if(backRight == 0){
        return BACK_RIGHT; 
    }
    else{
        return NO_BOUNDARY_DETECTED; 
    }
}

Orientation read_compass(){
 int pin1 = SensorValue(compass1); 
 int pin2 = SensorValue(compass2); 
 int pin3 = SensorValue(compass3); 
 int pin4 = SensorValue(compass4); 
 int combination = pin1 * 1000 + pin2 * 100 + pin3 * 10 + pin4; 

 switch (combination)
 {
 case 1110:
    return NORTH;
 case 1100:
    return NORTH_EAST;
 case 1101:
    return EAST; 
 case 1001:
    return SOUTH_EAST;
 case 1011:
    return SOUTH;
 case 0011:
    return SOUTH_WEST;
 case 0111:
    return WEST;
 case 0110:
    return NORTH_WEST;
 default:
    return INVALID_COMBINATION;
 }
}
