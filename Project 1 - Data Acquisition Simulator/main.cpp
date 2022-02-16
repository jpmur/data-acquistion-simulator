#include "DataAcquisition.h"

void main(void)
{
	double  samples[CHANNEL_SAMPLE_TOTAL];

	clock aClock(0, 1e-4L);

	waveform SquareWaveform(Square, 250);
	waveform SineWaveform(Sine, 250, 10, 0);

	signal  Signal0(&aClock, SquareWaveform);
	signal  Signal1(&aClock, SineWaveform);

	Channel  channel0(&Signal0, 100);  
	Channel  channel1(&Signal1, 300);

	Analyser myAnalyser(channel0, channel1);
	myAnalyser.GetAllSampleValues(1, samples);
	myAnalyser.DisplayChannel();

	myAnalyser.GetAllSampleValues(0, samples);
	myAnalyser.DisplayChannel();

}


