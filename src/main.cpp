#include <iostream>
#include "model/song.h"
#include "driver/audio_wav.h"
#include "debug_client.h"

int main(int argc, char const *argv[])
{ 

  debug_client client;
  client.init();
  client.loop();


  return 0;
}

