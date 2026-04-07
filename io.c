#include <stdio.h>
#include<stdlib.h>
#include"io.h"

WaveformSample* load_power_quality_log_csv(const char *filename , int *count){
    FILE *file = fopen(filename , "r");

    if(file == NULL) {
        printf("Error opening file\n");
        return 0;
    }

    WaveformSample *data = malloc(1000 * sizeof(WaveformSample));

    char line[256];
    int i = 0;

    fgets(line, sizeof(line), file );

    while (fgets(line, sizeof (line), file )){
        scanf(line, "%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf,",
              &data[i].phase_C_voltage,
              &data[i].phase_B_voltage,
              &data[i].phase_A_voltage,
              &data[i].thd_percent,
              &data[i].line_current,
              &data[i].power_factor,
              &data[i].frequency,
              &data[i].timestamp);
        i++;
    }
    fclose(file );
    *count = i;

    return data;
}
 void write_result(const char *filename,
                   double rmsA, double rmsB, double rmsC,
                   double ppA, double ppB, double ppC,
                   double dcA, double dcB, double dcC,
                   int clipped){

    FILE *file = fopen(filename, "w");

    if(file == NULL) {
        printf("Error opening file\n");
        return ;}

    fprintf(file, "RMS voltage: \n");
    fprintf(file, "phase A : %.2f V\n", rmsA);
    fprintf(file, "phase B : %.2f V\n", rmsB);
    fprintf(file, "phase C : %.2f V\n", rmsC);

    fprintf(file, "Peak to peak voltage:\n");
    fprintf(file, "phase A: %.2f v\n", ppA);
    fprintf(file, "phase B: %.2f v\n", ppB);
    fprintf(file, "phase C: %.2f v\n", ppC);

    fprintf(file, "DC offset:\n");
    fprintf(file, "phase A: %.2f v\n", dcA);
    fprintf(file, "phase B: %.2f v\n", dcB);
    fprintf(file, "phase C: %.2f v\n", dcC);

    fprintf(file, "clipping event: %d\n", clipped);

    fclose(file);

}


