#include <stdio.h>
#include<stdlib.h>
#include"io.h"
#include <string.h>
WaveformSample* power_quality_log_csv(const char *filename , int *count){
    printf("%s\n",filename);
    FILE *file = fopen(filename , "r");

    if(file == NULL) {
        printf("Error opening file.\n");
        return 0;
    }

    WaveformSample *data = malloc(1000 * sizeof(WaveformSample));

    char line[256];
    int i = 0;

    fgets(line, sizeof(line), file );

    while (fgets(line, sizeof (line), file ) !=NULL ){

        char *token;
       token = strtok(line, ",");
       data[i].timestamp = atof(token);

       token = strtok(NULL , ",");
       data[i].phase_A_voltage = atof(token);

        token = strtok(NULL , ",");
        data[i].phase_B_voltage = atof(token);

        token = strtok(NULL , ",");
        data[i].phase_C_voltage = atof(token);

        token = strtok(NULL , ",");
        data[i].line_current = atof(token);

        token = strtok(NULL , ",");
        data[i].frequency = atof(token);

        token = strtok(NULL , ",");
        data[i].power_factor= atof(token);

        token = strtok(NULL , ",");
        data[i].thd_percent = atof(token);

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
                   int clipped, double pf,
                   double thd, double freq, double pfmin, double pfmax,
                   double thdmin, double thdmax, double fmin, double fmax,
                   int tolerance, double var, double sd, unsigned char status ){

    FILE *file = fopen(filename, "w");

    if(file == NULL) {
        printf("Error opening file.\n");
        return  ;}

    fprintf(file, "POWER QUALITY WAVEFORM DATA:\n\n");

    fprintf(file, "RMS voltage: \n");
    fprintf(file, "phase A : %.2f V\n", rmsA);
    fprintf(file, "phase B : %.2f V\n", rmsB);
    fprintf(file, "phase C : %.2f V\n", rmsC);
    fprintf(file, "Tolerance: %s (rms >= 207 and rms <= 253)\n\n", tolerance ? "COMPLIANT" : "OUT OF TOLERANCE");

    fprintf(file, "Peak to peak voltage:\n");
    fprintf(file, "phase A: %.2f V\n", ppA);
    fprintf(file, "phase B: %.2f V\n", ppB);
    fprintf(file, "phase C: %.2f V\n\n", ppC);

    fprintf(file, "DC offset:\n");
    fprintf(file, "phase A: %.16f V\n", dcA);
    fprintf(file, "phase B: %.16f V\n", dcB);
    fprintf(file, "phase C: %.16f V\n\n", dcC);

    fprintf(file, "clipping event: %d\n\n", clipped);

    fprintf(file , "power factor: %.3f - %.3f\n",pfmin,pfmax);
    fprintf(file , "thd percent: %.3f  - %.3f %\n",thdmin, thdmax);
    fprintf(file , "frequency: %.3f - %.3f Hz\n\n",fmin, fmax);


    //Extension

    fprintf(file, "The variance: %.3f\n", var);
    fprintf(file, "the standard deviations : %.3f\n\n ",sd);

    fprintf(file, "Status flags: %u\n", status);
    fprintf(file, "Flags meaning: \n");
    fprintf(file, "bit 0 = clipping\n");
    fprintf(file, "bit 1 = out of tolerance\n");
    fprintf(file, "bit 2 = high thd(>5%%)\n");



    fclose(file);

}



