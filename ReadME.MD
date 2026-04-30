Overview:
The whole point of this project is to analyses the electrical power quality log data from a csv file using
the C programming language.
It performs calculations on the three phase voltage A, B and C and also the system parameter such as RMS voltage
peak to peak, DC offset, frequency, power factor and THD percent.
The program will also read the data from the csv file, it will procces it and output the final result on the text file
and the programming.

FIlE structure:
main.c = Is the main program execution
Waveform.c/Waveform.h = Signal proceesing functions
io.c/io.h = It will file input and output operations form the csv file
power quality log csv = Its the are input data
Result.txt = Is the output of my result

Main features:
It will read the csv file using file input and output (fopen, fclose(), string.h)
All the data from the file will store in to my WaveformSample as a struct
I used Dynamic memory allocation which is a library function that allow C to allocate memory dynamically.
In the Waveform.c I have placed all my calculations in the file, RMS voltage, peak to peak,DC offset, clipping and also
the tolerance check.
There were extra stuff like the frequency range, power factor range and THD range.

Extension:

Statistical analysis:
I have calculated the variance and also the standard deviations from the rms of phase A cos the three phase have the same vale.

Bitwise Status flags:

bit 0 = clipping detected
bit 1 = out of tolerance
bit 2 = High THD (>5%)

How to run it:
place the csv file into teh project folder
I have build the code with the use of Waveform.c/.h , io.c/.h and main.c and the run the code
The program will print the value out on the programe but also on the reult.txt and save the value in there.

Output:
example output for phase A:
RMS = 229.81V
Peak to Peak = 650V
DC offset: 0V
clipping count: 20 (BUT output was 60)
tolerance: compliant

Frequency range: 50 - 50.048 Hz
Power factor range: 0.950 - 0.962
THD range:2.00% - 2.18%

The key concept used:
pointers and arrays
structure
dynamic memory allocation
file handling in c
modular programming
basic statistical analysis


Github repository 
https://github.com/junjie2006-ai/ufmfgt-15-1-portfolio