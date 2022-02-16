#include "DataAcquisition.h"

clock::clock(double start_time, double step_size)
{
	/*Constructor accepts clock start time and the increment size*/
	microsecs = start_time;
	increment = step_size;
}

void clock::AdvanceTime(double new_inc = 5e-6)
{
	increment = new_inc;				// If the user supplies an different increment value, it will be used. Otherwise, default will be used.
	microsecs = microsecs + increment;
}

double clock::GetSimulationTime()
{
	double time_now = microsecs;		// Save the time when the function was called
	AdvanceTime();						// Increment the clock
	return time_now;					// Return the time when the function was called
}

