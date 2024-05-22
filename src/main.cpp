#include <iostream>
#include "model/song.h"

int main(int argc, char const *argv[])
{ 
  model::song song("artist", "album", "name");

  
  /* code */
  std::cout << song.get_song() << std::endl;

  while(true);

  return 0;
}

