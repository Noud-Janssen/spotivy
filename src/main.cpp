#include <iostream>
#include "model/song.h"
#include "driver/audio_wav.h"
#include "debug_client.h"
#include "model/artist.h"

#include "model/song_list_base.h"

int main(int argc, char const *argv[])
{ 


  std::vector<model::artist> artists = model::artist::all();

  for(auto artist : artists)
  {
    std::cout << artist.get_name() << std::endl;
  }

  debug_client client;
  client.init();
  client.loop();
  return 0;
}

