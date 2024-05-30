#include <iostream>
#include "model/song.h"
#include "model/song_list_base.h"

int main(int argc, char const *argv[])
{ 
  model::song song("artist", "album", "name");

  
  /* code */
  std::cout << song.get_song() << std::endl;

  while(true);


  model::song_list_base list;


  return 0;
}

