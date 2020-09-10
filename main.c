#include <stdio.h>
#include <gensnd.h>

int main(int argc, char const *argv[]) {
  float frequency, samplerate, duration = 0;
  printf("Please enter \"<frequency> <samplerate> <duration>\"\n");
  scanf("%f %f %f", &frequency, &samplerate, &duration);
  gensine(frequency, samplerate, duration);
  return 0;
}
