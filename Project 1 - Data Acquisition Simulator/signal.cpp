#include "DataAcquisition.h"

signal::signal(clock *clk, waveform wave)
{
/*Constructor accepts pointer to a clock object and a wavefrom object.*/
	clockSource = clk;
	aWaveform = wave;
}

double signal::GetSample()
{
/*This function generates a signal value for either a sine or square wave.*/
	double current_time;
	current_time = clockSource->GetSimulationTime();	// Get the current time to be used in creating the signal value
	switch (aWaveform.type)								// Check the waveform type..
	{
		case (Sine):									// If its a sine wave..
			return aWaveform.amplitude * sin(2 * pi * aWaveform.frequency * current_time) + aWaveform.dcOffset; // Calculate a sine wave signal value
		case (Square):									// If a square wave...
			double samp = sin(2 * pi * aWaveform.frequency * current_time); // Generate a sine wave value..
			return  (samp >= 0) ? 1 : 0;				// If the value is 0 or greater , return a 1 value otherwise return a 0 value
	}
}