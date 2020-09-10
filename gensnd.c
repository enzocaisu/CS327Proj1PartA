#include <stdio.h>
#include <gensnd.h>
#include <math.h>

int gensine(float frequency, float samplerate, float duration){
  printf("%f %f %f\n", frequency, samplerate, duration);
  int samples = duration * samplerate;
  float time = 0;
  for(int i = 0; i < samples; i++){
    printf("%f\n", sin(2.0 * M_PI * frequency * i / samplerate));
  }
  return 0;
}
