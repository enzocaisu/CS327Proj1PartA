//Author: Enzo Ciccarelli-Asta
#include <stdio.h>
#include <gensnd.h>
#include <math.h>

//gensine function
//takes a frequency, samplerate, and duration of a sin wave
//outputs corresponding samples of a sin wave with those attributes
int gensine(float frequency, float samplerate, float duration){
  //printf("%f %f %f\n", frequency, samplerate, duration);
  FILE *f;
  f = fopen("gensine.txt", "w");
  int samples = duration * samplerate;
  for(int i = 0; i < samples; i++){
    fprintf(f, "%f\n", sin(2.0 * M_PI * frequency * i / samplerate));
  }
  fclose(f);
  return 0;
}

//silence function
//takes a samplerate and duration
//prints silence as a sin wave according to the inputs
int silence(float samplerate, float duration, FILE *f){
  int samples = duration * samplerate;
  for(int i = 0; i < samples; i++){
    fprintf(f, "%f\n", 0.0);
  }
}

//keypress function
//takes a char and prints its DTMF tone as a composite of two sin waves
//returns 1 on invalid character
//500 ms, 8 gHz sample size
int keypress(char c, FILE *f){
  float freq1, freq2 = 0;
  //column frequency
  switch(c){
    case 'A': case'B': case'C': case'D':
    freq1 = 1633.0;
    break;
    case'3': case '6': case'9': case'#':
    freq1 = 1477.0;
    break;
    case'2': case'5': case'8': case'0':
    freq1 = 1336.0;
    break;
    case'1': case'4': case'7': case'*':
    freq1 = 1209.0;
    break;
    default: return 1;
  }
  //row frequency
  switch(c){
    case '1': case '2': case '3': case 'A':
    freq2 = 697.0;
    break;
    case'4': case'5': case'6': case'B':
    freq2 = 770.0;
    break;
    case'7': case'8': case'9': case'C':
    freq2 = 852.0;
    break;
    case'*': case'0': case'#': case'D':
    freq2 = 941.0;
    break;
    default: return 1;
  }

  float duration = 0.5; //500 ms
  float samplerate = 8000; //8kHZ
  int samples = duration * samplerate;
  //printf("freq1: %f freq2: %f\n", freq1, freq2);
  for(int i = 0; i < samples; i++){
    fprintf(f, "%f\n", (sin(2.0 * M_PI * freq1 * i / samplerate) + sin(2.0 * M_PI * freq2 * i / samplerate))/2.0);
  }
}
