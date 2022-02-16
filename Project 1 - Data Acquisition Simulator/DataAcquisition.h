#pragma once
#include <iostream>
#include <cmath>

using namespace std;

const double pi = 3.14159265358979323846;
const int CHANNEL_SAMPLE_TOTAL = 500;
const int CHANNEL_COUNT = 2;


class clock
{
	double microsecs;
	double increment;
	void AdvanceTime(double new_inc);
public:
	clock(double start_time = 0, double step_size = 5e-6);
	double GetSimulationTime();
};

enum SIGNAL_TYPE { Sine, Square };


struct waveform
{
public:
	waveform(SIGNAL_TYPE sig = SIGNAL_TYPE(),double freq=0, double ampltd=0, double offset=0);
	double amplitude;
	double frequency;
	double dcOffset;
	SIGNAL_TYPE type;
};

class signal
{
	waveform aWaveform;
	clock *clockSource;
public:
	signal(clock *clk, waveform wave);
	double GetSample();
};


class Channel
{
	int numberOfSamples;
	signal* theSignal;
	double values[CHANNEL_SAMPLE_TOTAL];
public:
	Channel(signal* sig, int num_samples);
	double* GetSamples();
	void SetSize(int);
	void SetChannelSize(int);
	int GetChannelSize();
	void GetChannelParameters(int&);
};


class Analyser
{
	Channel* channel_array[CHANNEL_COUNT];
	bool SetChannelProperties(int, Channel);
	bool GetChannelProperties(int, double&, double&, int&);
	int numberOfChannels;
	int numberOfSamples;
	double Timebase;
	double VoltsPerDiv;
	int channelSampleSize;
	double samples[];
public:
	Analyser(Channel &ch1 , Channel &ch2);
	Analyser(Channel &ch);
	Analyser(int num_channels);
	void DisplayChannel();
	bool GetAllSampleValues(int channel, double*);
};