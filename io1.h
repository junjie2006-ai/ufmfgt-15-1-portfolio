#ifndef UNTITLED2_IO_H
#define UNTITLED2_IO_H
#include "waveform.h"

WaveformSample* power_quality_log_csv(const char *filename, int *count);
void write_result(const char *filename,
                  double rmsA, double rmsB, double rmsC,
                  double ppA, double ppB, double ppC,
                  double dcA, double dcB, double dcC,
                  int clipped, double pf, double thd,
                  double freq);
#endif //UNTITLED2_IO_H
