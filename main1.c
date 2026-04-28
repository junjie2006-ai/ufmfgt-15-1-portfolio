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

    double pfmin,pfmax;
    double thdmin, thdmax;
    double fmin,fmax;


    double pf = power_factor(data,count, &pfmin, &pfmax);
    double thd = thd_percent(data,count, &thdmin, &thdmax);
    double freq = frequency(data, count,&fmin, &fmax);


    int ok = check_tolerance( rmsA);
    if (ok){
        printf("phase A is within tolerance \n");
    }else{
        printf("phase A is not within the tolerance \n\n");
    }


    //Extension

    double *phaseA = malloc(count * sizeof(double));

    for (int i = 0; i < count; i++) {
        phaseA[i] = data[i].phase_A_voltage;
    }

    double var = compute_variance(phaseA, count);
    double sd = compute_sd(phaseA, count);

    printf("variance: %.2f\n", var);
    printf("standard deviations: %.2f\n\n", sd);


    unsigned char status = compute_status_flags(clipped,ok,thdmax);

    printf("Status flag : %d\n\n", status);
//

    printf("Phase A RMS: %.2f V\n", rmsA);
    printf("clipping event: %d\n", clipped);
    printf("Phase A peak to peak: %.2f V\n", ppA);
    printf("Phase A DC offset: %.2f V\n\n",dcA);

    printf("power factor : %.3f - %.3f\n", pfmin,pfmax);
    printf("thd percent : %.3f - %.3f %\n", thdmin, thdmax);
    printf("Frequency : %.3f - %.3f Hz\n\n", fmin, fmax);


    write_result( " result.txt",
                  rmsA, rmsB, rmsC,
                  ppA, ppB, ppC,
                  dcA, dcB, dcC, clipped,
                  pf, thd,freq, fmin,fmax, pfmin, pfmax, thdmin, thdmax,
                  check_tolerance(rmsA) , var, sd, status);

    free(data);

    return 0;
}
