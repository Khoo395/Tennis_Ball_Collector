int dispense_limit_status;

void control_motor(int left_speed, int right_speed)
{
    motor(left_driver) = left_speed;
    motor(right_driver) = right_speed;
}

void stop_motor()
{
    motor(left_driver) = 0;
    motor(right_driver) = 0;
}

void activate_roller(int roller_speed)
{
    motor(roller_driver) = roller_speed;
}

void stop_roller()
{
    motor(roller_driver) = 0;
}

void open_dispense_gate()
{
    clearTimer(T2);
    while (time1(T2) < 550)
    {
        motor(ball_dispense_driver) = 40;
    }
}

void close_dispense_gate()
{
    while (1)
    {
        dispense_limit_status = read_dispense_limit_switch();
        if (dispense_limit_status != 0)
        {
            motor(ball_dispense_driver) = -30;
        }
        else
        {
            motor(ball_dispense_driver) = 0;
            break;
        }
    }
}