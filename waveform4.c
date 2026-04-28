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
double power_factor(WaveformSample *data , int count, double *min, double *max) {
    *min = data[0].power_factor;
    *max = data[0].power_factor;

    for (int i = 1; i < count; i++) {
        if (data[i].power_factor < *min) {
            *min = data[i].power_factor;
        }
        if (data[i].power_factor > *max) {
            *max = data[i].power_factor;
        }


    }
}

double thd_percent(WaveformSample *data, int count, double *min, double *max) {
    *min = data[0].thd_percent;
   * max = data[0].thd_percent;

    for (int i = 1; i < count; i++) {
        if (data[i].thd_percent < *min) {
            *min = data[i].thd_percent;
        }
        if (data[i].thd_percent > *max) {
            *max = data[i].thd_percent;
        }

    }
}

double frequency (WaveformSample *data, int count, double *min, double *max) {
    *min = data[0].frequency;
    *max = data[0].frequency;

    for (int i = 1; i < count; i++) {
        if (data[i].frequency < *min) {
            *min = data[i].frequency;
        }
        if (data[i].frequency > *max) {
            *max = data[i].frequency;
        }


    }
}
int check_tolerance(double rms){
    if( rms >= 207.0 && rms <= 253){
        return 1;
    }else{
        return 0;
    }

}

//Extension

double compute_variance(double *values, int count ) {
    double mean = 0;

    for (int i = 0; i < count; i++) {
        mean += values[i];
    }
    mean /= count;
    double sum= 0;
    for(int i =0;i <count; i++){
        double diff = values[i] - mean;
        sum += diff * diff;
    }
    return sum/count;
}

double compute_sd(double *values, int count){
    return sqrt(compute_variance( values, count));
}

unsigned char compute_status_flags( int clipping, int tolerance , double thd_percent) {
    unsigned char status = 0;

    if (clipping > 0) {
        status |= (1 << 0);
    }

    if (!tolerance){
        status |= (1<<1);

    }

    if (thd_percent> 5){
        status |= (1 << 2);
    }
    return status;
}

