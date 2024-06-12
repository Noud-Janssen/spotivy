#ifndef SPOTIVY_MODEL_ALBUM
#define SPOTIVY_MODEL_ALBUM

#include <cstdint>
#include <string>
#include <vector>
#include "model/song_list_base.h"

namespace model
{
    class album : public song_list_base
    {
    public:
        album(std::string title, std::vector<song> songs);
    public:
        void add(song s) = delete;
    public:

    private:
        
    };

    
} // namespace model


#endif // SPOTIVY_MODEL_ALBUM