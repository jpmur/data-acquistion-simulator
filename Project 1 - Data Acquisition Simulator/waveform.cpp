#include "DataAcquisition.h"

waveform::waveform(SIGNAL_TYPE sig, double freq, double ampltd, double offset)
{
/**Constructor accepts signal attributes and assigns them to "waveform" struct member data*/
	amplitude = ampltd;
	frequency = freq;
	dcOffset = offset;
	type = sig;
}

