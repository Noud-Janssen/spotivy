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
        /**
         * @brief Construct a new music controller
         * 
         */
        music();
        /**
         * @brief Destroy the music controller
         * 
         */
        ~music() = default;
    public:
        /**
         * @brief clear the queue, and add this song and or album to the queue
         * 
         * @param artist_index 
         * @param album_index 
         * @param song_index 
         */
        void play(int artist_index, int album_index, int song_index = -1);
        /**
         * @brief pause the current song
         * 
         * @return std::string 
         */
        std::string pause();
        /**
         * @brief skip to the next song
         * 
         */
        void skip();
        /**
         * @brief Get all artists
         * 
         * @return std::vector<model::artist> 
         */
        std::vector<model::artist> get_artists();
        /**
         * @brief find a artist based on its name
         * 
         * @param s 
         * @return model::artist 
         */
        model::artist find_artist(std::string s);

        void add_to(int placeholder, int placeholder2);
        /**
         * @brief Get the queue
         * 
         * @return model::queue& 
         */
        model::queue &get_queue(); 
    private:
        model::queue m_queue;
        
    };

    
} // namespace controller

#endif // SPOTIVY_CONTROLLER_MUSIC_H