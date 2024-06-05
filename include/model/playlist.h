#ifndef SPOTIVY_MODEL_PLAYLIST
#define SPOTIVY_MODEL_PLAYLIST

#include <cstdint>
#include <string>
#include <vector>
#include "model/song_list_base.h"

namespace model
{
    class playlist : public song_list_base
    {
    public:
        playlist(std::string title);
    public:
        
    private:
        
    };

    
} // namespace model


#endif // SPOTIVY_MODEL_PLAYLIST