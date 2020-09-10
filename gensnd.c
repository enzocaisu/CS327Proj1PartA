#include <stdio.h>
#include <gensnd.h>
#include <math.h>

int gensine(float frequency, float samplerate, float duration){
  //printf("%f %f %f\n", frequency, samplerate, duration);
  int samples = duration * samplerate;
  for(int i = 0; i < samples; i++){
    printf("%f\n", sin(2.0 * M_PI * frequency * i / samplerate));
  }
  return 0;
}

int silence(float samplerate, float duration){
  int samples = duration * samplerate;
  for(int i = 0; i < samples; i++){
    printf("%f\n", 0.0);
  }
}

int keypress(char c){
  float freq1, freq2 = 0;
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
  }
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
  }
  int duration = 0.5; //500 ms
  int samplerate = 8000; //8kHZ
  int samples = duration * samplerate;
  for(int i = 0; i < samples; i++){
    printf("%f\n", (sin(2.0 * M_PI * freq1 * i / samplerate) + sin(2.0 * M_PI * freq2 * i / samplerate))/2);
  }
}
