#include "DataAcquisition.h"

Channel::Channel(signal *sig, int num_samples)
{
/*Constructor accepts pointer to a signal object and the channel buffer size*/
	theSignal = sig;
	numberOfSamples = num_samples;
}

double* Channel::GetSamples()
{	
/*This function populates an array of signal values and returns a pointer to this array*/
	for (int i = 0; i <= numberOfSamples; i++)
	{
		values[i] = theSignal->GetSample();
	}
	return values;
}

int Channel::GetChannelSize()
{
/*Returns the buffer size*/
	return numberOfSamples;
}

void Channel::SetSize(int channelSize)
{
	this->numberOfSamples = channelSize;
}

void Channel::SetChannelSize(int bufferSize)
{
	if (bufferSize <= CHANNEL_SAMPLE_TOTAL)
	{
		SetSize(bufferSize);
	}
	else
	{
		cout << "The buffer size input exceeds the maximum size!" << endl;
	}
}

void Channel::GetChannelParameters(int& numberOfSamples)
{
	numberOfSamples = this->numberOfSamples;
}