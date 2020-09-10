//Author: Enzo Ciccarelli-Asta

//gensine function
//takes a frequency, samplerate, and duration of a sin wave
//outputs corresponding samples of a sin wave with those attributes
int gensine(float frequency, float samplerate, float duration);

//silence function
//takes a samplerate and duration
//prints silence as a sin wave according to the inputs
int silence(float samplerate, float duration, FILE *f);

//keypress function
//takes a char and prints its DTMF tone as a composite of two sin waves
//returns 1 on invalid character
//500 ms, 8 gHz sample size
int keypress(char c, FILE *f);
