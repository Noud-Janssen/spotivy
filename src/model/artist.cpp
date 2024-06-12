#include "model/artist.h"

namespace model
{

    
    artist::artist(std::string name) 
        : m_name(name)
    {
    }

   std::vector<artist> artist::all()
   {
       std::vector<artist> artists;
       
        artists.emplace_back(artist("Kendrick Lamar"));  
        artists.back().m_albums.emplace_back(album("To pimp a butterfly",{
            song("Kendrick Lamar", "To pimp a butterfly", "Wesley's Theory"),
            song("Kendrick Lamar", "To pimp a butterfly", "For Free?"),
            song("Kendrick Lamar", "To pimp a butterfly", "King Kunta"),
            song("Kendrick Lamar", "To pimp a butterfly", "Institutionalized"),
            song("Kendrick Lamar", "To pimp a butterfly", "These Walls")
        }));
        artists.back().m_albums.emplace_back(album("Mr Morale & The Big Steppers",{
            song("Kendrick Lamar", "Mr Morale & The Big Steppers", "United in Grief"),
            song("Kendrick Lamar", "Mr Morale & The Big Steppers", "N95"),
            song("Kendrick Lamar", "Mr Morale & The Big Steppers", "Worldwide Steppers"),
            song("Kendrick Lamar", "Mr Morale & The Big Steppers", "Die Hard"),
            song("Kendrick Lamar", "Mr Morale & The Big Steppers", "Father Time")
        }));
        artists.emplace_back(artist("Hiatus Kaiyote"));
        artists.back().m_albums.emplace_back(album("Mood Valiant",{
            song("Hiatus Kaiyote", "Mood Valiant", "Flight of the Tiger Lilly"),
            song("Hiatus Kaiyote", "Mood Valiant", "Slip into Something Soft"),
            song("Hiatus Kaiyote", "Mood Valiant", "Chivalry is Not Dead"),
            song("Hiatus Kaiyote", "Mood Valiant", "And We Go Gently"),
            song("Hiatus Kaiyote", "Mood Valiant", "Get Sun"),
        }));
 

       return artists;
   }

    std::string artist::get_name()
    {
        return m_name;
    }

    std::vector<model::album> artist::get_albums()
    {
        return m_albums;
    }
} // namespace model
