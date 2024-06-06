#include "model/artist.h"
#include "model/album.h"

namespace model
{


    artist::artist(std::string name) : m_name(name)
    {
    }

   std::vector<artist> artist::all()
   {
       std::vector<artist> artists;
       
       artists.emplace_back(artist("artiest 1"));
       artists.back().m_albums.emplace_back(album("album 1",{song(1),song(2),song(3)}));
       artists.emplace_back(artist("artiest 2"));
       artists.back().m_albums.emplace_back(album("album 2",{song(4),song(5),song(6)}));
       artists.emplace_back(artist("artiest 3"));
       artists.back().m_albums.emplace_back(album("album 3",{song(7),song(8),song(9)}));
       artists.emplace_back(artist("artiest 4"));
       artists.back().m_albums.emplace_back(album("album 4",{song(10),song(11),song(12)}));

       return artists;
   }

    std::string artist::get_name()
    {
        return m_name;
    }
} // namespace model
