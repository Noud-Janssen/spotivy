#ifndef SPOTIVY_DRIVER_AUDIO_WAV_H
#define SPOTIVY_DRIVER_AUDIO_WAV_H

#include "driver/audio_base.h"
#include <SFML/Audio.hpp>

namespace driver
{
    class audio_wav
    {
    public:
        /**
         * @brief Construct a new audio wav object
         * 
         */
        audio_wav();
        /**
         * @brief Destroy the audio wav object
         * 
         */
        ~audio_wav() = default;
    public:

        /**
         * @brief loop the driver
         * 
         */
        void loop();

        /**
         * @brief add a song to the buffer
         * 
         * @return true 
         * @return false 
         */
        bool add_to_buffer(uint64_t song);

        /**
         * @brief play the current song
         * 
         * @return true 
         * @return false 
         */
        bool play();

        /**
         * @brief 
         * 
         * @return true 
         * @return false 
         */
        bool pause();

        /**
         * @brief get if the song is done
         * 
         * @return true 
         * @return false 
         */
        bool done();

        /**
         * @brief skip to the next song
         * 
         * @return true 
         * @return false 
         */
        bool skip();

        /**
         * @brief 
         * 
         * @return true 
         * @return false 
         */
        bool previous();
    private:

        int m_index;

        std::vector<uint64_t> m_buffer;

        sf::Music m_music_player;
    
    };
    
} // namespace driver


#endif // SPOTIVY_DRIVER_AUDIO_WAV_H