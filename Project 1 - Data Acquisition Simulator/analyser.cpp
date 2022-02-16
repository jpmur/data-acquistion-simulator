#include "DataAcquisition.h"

Analyser::Analyser(Channel &ch1, Channel &ch2)
/*Constructor accepts Channel objects and stored them in an array of objects within the Analyser class*/
{
	channel_array[0] = &ch1;
	channel_array[1] = &ch2;
}

Analyser::Analyser(Channel &ch)
{
	channel_array[0] = &ch;
}

Analyser::Analyser(int num_channels)
{
	num_channels = numberOfChannels;
}

bool Analyser::GetAllSampleValues(int channel_num, double*)
{
/*This function gets an array of signal values by calling the channel.GetSamples() function which populates
an array with signal values and returns a pointer to this array.*/
	double *ptr;
	SetChannelProperties(channel_num, *channel_array[channel_num]);
	GetChannelProperties(channel_num, VoltsPerDiv, Timebase, channelSampleSize);
	ptr = channel_array[channel_num]->GetSamples();	// Get pointer to an array of signal values
	numberOfSamples = channel_array[channel_num]->GetChannelSize(); // Get size of array
	for (int i = 0; i <= numberOfSamples; i++)
	{
		samples[i] = *(ptr+i);						// Copy contents of signal value array into local array
	}
	return true;
}

void Analyser::DisplayChannel()
{
	for (int i = 0; i < numberOfSamples; i++)
	{
		cout << samples[i] << endl;					// Print contents of samples array
	}
}

bool Analyser::SetChannelProperties(int ch_num, Channel MetaData)
{
	channel_array[ch_num]->GetChannelParameters(channelSampleSize);
	return true;
}

bool Analyser::GetChannelProperties(int ch_num, double& volts, double& time, int& channelSampleSize)
{
	cout << "Channel Number:" << endl;
	cin >> ch_num;
	cout << "Volts per divison: " << endl;
	cin >> volts;
	cout << "Timebase:" << endl;
	cin >> time;
	return true;
}
