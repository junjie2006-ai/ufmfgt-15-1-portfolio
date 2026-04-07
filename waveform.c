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



