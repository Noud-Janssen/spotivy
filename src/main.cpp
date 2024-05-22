#include <iostream>
#include "model/song.h"
#include "driver/audio_wav.h"

int main(int argc, char const *argv[])
{ 
  driver::audio_wav wav;

  while(true) {
    wav.loop();
  };

  return 0;
}

