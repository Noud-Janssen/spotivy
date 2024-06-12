#ifndef SPOTIVY_CONTROLLER_MUSIC_H
#define SPOTIVY_CONTROLLER_MUSIC_H

#include <vector>
#include "model/artist.h"

namespace controller
{
    class music
    {
    public:
        music() = default;
        ~music() = default;
    public:
        void play();
        void pause();
        void skip();
        std::vector<model::artist> get_artists();
        model::artist find_artist(std::string s);

        void add_to(int placeholder, int placeholder2);
    private:
        
    };

    
} // namespace controller

#endif // SPOTIVY_CONTROLLER_MUSIC_H