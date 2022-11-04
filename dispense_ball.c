void dispense_ball()
{
	writeDebugStreamLine("%s", "calling dispensing function");
	open_dispense_gate();
	close_dispense_gate();
	ball_found = 0;
	ball_collected = 0;
}