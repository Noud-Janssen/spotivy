#ifndef SPOTIVY_MODEL_ARTIST_H
#define SPOTIVY_MODEL_ARTIST_H

#include <vector>

namespace model
{
    class artist
    {
    public:
        artist() = default;
        ~artist() = default;
    public:
        static std::vector<artist> all();
    };
    
    
} // namespace model



#endif // SPOTIVY_MODEL_ARTIST_H