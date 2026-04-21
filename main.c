#include<stdio.h>
#include<stdlib.h>
#include"waveform.h"
#include"io.h"

int main(){
    int count = 0;

    WaveformSample *data = power_quality_log_csv("power_quality_log.csv", &count);

    if(data == NULL ){
        printf("Error opening file.\n");
        return 1;
    }

    double rmsA = compute_rms(data, count , 'A');
    double rmsB = compute_rms(data, count , 'B');
    double rmsC = compute_rms(data, count , 'C');

    double ppA = compute_peak_to_peak(data,count, 'A');
    double ppB = compute_peak_to_peak(data,count, 'B');
    double ppC = compute_peak_to_peak(data,count, 'C');

    double dcA = compute_dc_offset(data, count, 'A');
    double dcB = compute_dc_offset(data, count, 'B');
    double dcC = compute_dc_offset(data, count, 'C');

    int clipped = count_clipping(data, count);

    double pf = power_factor(data,count);
    double thd = thd_percent(data,count);
    double freq = frequency(data, count);

    printf("Phase A RMS: %.2f V\n", rmsA);
    printf("clipping event: %d\n", clipped);
    printf("Phase A peak to peak: %.2f V\n", ppA);
    printf("Phase A DC offset: %.2f V\n",dcA);

    printf("power factor : %.2f\n", pf);
    printf("thd percent : %.2f %\n", thd);
    printf("Frequency : %.2f Hz\n", freq);


    write_result( " result.txt",
                  rmsA, rmsB, rmsC,
                  ppA, ppB, ppC,
                  dcA, dcB, dcC, clipped,
                  pf,
                  thd,freq);

    free(data);

    return 0;
}
