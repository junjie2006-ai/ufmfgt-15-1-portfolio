#include"waveform.h"
#include<math.h>
double get_value(WaveformSample  sample ,char phase){
    if (phase == 'A') return sample.phase_A_voltage;
    else if (phase == 'B') return sample.phase_B_voltage;
    else return sample.phase_C_voltage;
}

double compute_rms(WaveformSample *data, int count, char phase ){
    double sum = 0;
    double value;

    for(int i = 0; i< count; i++) {
        value = get_value(data[i], phase);

        sum += value * value;
    }

    return sqrt(sum/count);
}
double compute_peak_to_peak(WaveformSample *data, int count , char phase){
    double min = get_value(data[0], phase);
    double max = min;
    double value;

    for(int i =0; i < count;i++){
        value = get_value(data[i], phase);

        if (value < min) min = value;
        if(value > max) max = value;

    }
    return max - min;

}

double compute_dc_offset(WaveformSample *data, int count , char phase){
    double sum = 0;

    for( int i = 0; i < count; i++){
        sum += get_value(data[i], phase);
    }
    return sum/count;
}
int count_clipping(WaveformSample *data, int count){
    int clipped = 0;

    for (int i = 0; i< count; i++){
        if (fabs(data[i].phase_A_voltage) >= 324.9) clipped++;
        if (fabs(data[i].phase_B_voltage) >= 324.9) clipped++;
        if (fabs(data[i].phase_C_voltage) >= 324.9) clipped++;

    }
    return clipped;
}
double power_factor(WaveformSample *data , int count){
    double sum = 0;

    for(int i = 0;i < count; i++){
        sum += data[i].power_factor;
    }
    return sum/ count;

}

double thd_percent(WaveformSample *data, int count){
    double sum = 0;

    for(int i=0; i < count; i++){
        sum += data[i].thd_percent;
    }
    return sum/count;
}

double frequency (WaveformSample *data, int count){
    double sum = 0;

    for(int i = 0; i<count; i++){
        sum += data[i].frequency;

    }
    return sum/count;
}