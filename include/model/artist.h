#ifndef SPOTIVY_MODEL_ARTIST_H
#define SPOTIVY_MODEL_ARTIST_H

#include <vector>
#include <string>
#include "model/album.h"

namespace model
{
    class artist
    {
    public:
        artist(std::string);
        ~artist() = default;
    public:
        static std::vector<artist> all();
        std::string get_name();
    private:
        std::string m_name;
        std::vector<album> m_albums;

    };
    
    
} // namespace model



#endif // SPOTIVY_MODEL_ARTIST_H