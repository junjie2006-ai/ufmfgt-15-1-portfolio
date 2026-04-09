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



