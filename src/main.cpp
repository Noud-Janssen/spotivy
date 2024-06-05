#include <iostream>
#include "model/song.h"

#include "model/playlist.h"

int main(int argc, char const *argv[])
{ 

  model::playlist playlist("My Playlist");
  
  model::song a(10);

  playlist.add(model::song(10));
  playlist.add(model::song(11));
  playlist.add(model::song(15));
  playlist.add(model::song(6));
  playlist.add(model::song(7));

  while(true) {
    playlist.get_size();
  };

  return 0;
}

