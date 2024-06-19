#ifndef SPOTIVY_CONTROLLER_MUSIC_H
#define SPOTIVY_CONTROLLER_MUSIC_H

#include <vector>
#include "model/artist.h"
#include "model/queue.h"

namespace controller
{
    class music
    {
    public:
        music();
        ~music() = default;
    public:
        std::string play(int artist_index, int album_index, int song_index);
        std::string pause();
        void skip();
        std::vector<model::artist> get_artists();
        model::artist find_artist(std::string s);

        void add_to(int placeholder, int placeholder2);
    private:
        model::song current_song;
        model::queue m_queue;
        
    };

    
} // namespace controller

#endif // SPOTIVY_CONTROLLER_MUSIC_H