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

  model::playlist list2("My Playlist 2");

  list2.add(playlist);



  std::cout << "Playlist list2 length is: " << list2.get_size() << std::endl;
  while(true) {
  };

  return 0;
}

