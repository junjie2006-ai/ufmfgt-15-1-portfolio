#ifndef UNTITLED1_IO_H
#define UNTITLED1_IO_H

#include "waveform.h"

WaveformSample* load_power_quality_log_csv(const char *filename, int *count);
void write_result(const char *filename,
                  double rmsA, double rmsB, double rmsC,
                  double ppA, double ppB, double ppC,
                  double dcA, double dcB, double dcC,
                  int clipped);



#endif //UNTITLED1_IO_H
