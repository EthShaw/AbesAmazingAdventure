#include "Sound.h"

static Uint8 *audio_file;
static Uint32 audio_len, audio_len_original;
static Uint8 *audio_pos;

/* The audio function callback takes the following parameters:
   stream:  A pointer to the audio buffer to be filled
   len:     The length (in bytes) of the audio buffer
*/
void fill_audio(void *udata, Uint8 *stream, int len) {
  /* Only play if we have data left */
  if(audio_len == 0) {
	if(audio_pos) {
	  // close audio, free sound
	  //	  SDL_FreeWAV(audio_file);
	  audio_pos = NULL;
	}
	return;
  }
  
  /* Mix as much data as possible */
  len = ( len > audio_len ? audio_len : len );
  SDL_MixAudio(stream, audio_pos, len, SDL_MIX_MAXVOLUME);
  audio_pos += len;
  audio_len -= len;
}

void playWav(char *wav) {
  SDL_AudioSpec spec, obtained;
  char path[80];

  if(audio_pos) {
	fprintf(stderr, "Already playing a sound.\n");
	return;
  }
  
  /*
  // load the wav
  sprintf(path, "%s/%s.wav", SOUND_DIR, wav);
  fprintf(stderr, "Trying to open: %s\n", path);
  if(SDL_LoadWAV(path, &spec, &audio_file, &audio_len) == NULL ){
	fprintf(stderr, "Could not open %s: %s\n", path, SDL_GetError());
	return;
  }
  */

  // reset sound buffer pointer
  audio_pos = audio_file;
  audio_len = audio_len_original;
  
  // start playing
  SDL_PauseAudio(0);  

  //  while(audio_pos) {
  //	SDL_Delay(100);
  //  }
}

void initAudio() {
  SDL_AudioSpec spec, obtained;
  char path[80];
  
  // load the wav
  sprintf(path, "%s/door.wav", SOUND_DIR);
  fprintf(stderr, "Trying to open: %s\n", path);
  if(SDL_LoadWAV(path, &spec, &audio_file, &audio_len_original) == NULL ){
	fprintf(stderr, "Could not open %s: %s\n", path, SDL_GetError());
	return;
  }
  // set the callback function
  spec.callback = fill_audio;
  spec.samples=128;

  // open audio
  if(SDL_OpenAudio(&spec, &obtained)) {
	fprintf(stderr, "Could not open audio device for this audio spec.: %s\n", SDL_GetError());
	return;
  }


  //  SDL_FreeWAV(audio_file);
  
  audio_pos = NULL;
}