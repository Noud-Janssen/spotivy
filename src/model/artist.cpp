#include "model/artist.h"

namespace model
{

    
    artist::artist(std::string name) : m_name(name)
    {
    }

   std::vector<artist> artist::all()
   {
       std::vector<artist> artists;



       
       artists.emplace_back(artist("test"));
       
       artists.emplace_back(artist("test1"));
       artists.emplace_back(artist("test2"));
       artists.emplace_back(artist("test3"));

       return artists;
   }

    std::string artist::get_name()
    {
        return m_name;
    }
} // namespace model
