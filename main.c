#include<stdio.h>
#include<stdlib.h>
#include"waveform.h"
#include"io.h"

int main(int argc,char *argv[1]){

    if(argc < 2){
        printf("usage: %s < power_quality_log.csv_file  >\n", argv[1]);
        return 1;
    }
    int count = 0;

    WaveformSample *data = load_power_quality_log_csv(argv[1], &count);
printf("trying to open: %s\n", argv[1]);
    if(data == NULL ){
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

    printf("Phase A RMS: %.2f V\n", rmsA);
    printf("clipping event: %d\n", clipped);

    write_result( " result.txt",
                  rmsA, rmsB, rmsC,
                  ppA, ppB, ppC,
                  dcA, dcB, dcC, clipped);

    free(data);

    return 0;
}

