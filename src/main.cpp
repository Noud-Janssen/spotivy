#include <iostream>
#include "model/song.h"
#include "driver/audio_wav.h"
#include "debug_client.h"
#include "model/artist.h"
#include "model/song_list_base.h"

int main(int argc, char const *argv[])
{ 
  #ifndef __UNIX__
  std::system("chcp 65001");
  #endif

  debug_client client;
  client.init();
  client.loop();
  return 0;
}

