#ifndef UNTITLED2_WAVEFORM_H
#define UNTITLED2_WAVEFORM_H

typedef struct{

    double timestamp, phase_A_voltage, phase_B_voltage, phase_C_voltage, line_current,frequency,
            power_factor, thd_percent;
} WaveformSample;

double compute_rms(WaveformSample *data, int count, char phase);
double compute_peak_to_peak(WaveformSample *data, int count, char phase);
double compute_dc_offset(WaveformSample *data, int count, char phase );
int count_clipping(WaveformSample *data, int count );
double power_factor(WaveformSample *data, int count);
double thd_percent(WaveformSample *data, int count);
double frequency(WaveformSample *data, int count);


#endif //UNTITLED2_WAVEFORM_H
