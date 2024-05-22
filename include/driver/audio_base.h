#ifndef SPOTIVY_DRIVER_AUDIO_BASE_H
#define SPOTIVY_DRIVER_AUDIO_BASE_H

#include <cstdint>
#include <vector>


namespace driver
{

    /***
     * @todo when class song is finished, add it to this class
    */
    class audio_base
    {
    public:
        /**
         * @brief add a song to buffer
         * 
         * 
         * @return true 
         * @return false 
         */
        bool add_to_buffer(uint64_t song);
        /**
         * @brief play the next song, returns false when there is no next song
         * 
         * @return true 
         * @return false 
         */
        virtual bool play() = 0;
        /**
         * @brief pause the song
         * 
         * @return true 
         * @return false 
         */
        virtual bool pause() = 0;
        /**
         * @brief skip to the next song in the buffer
         * 
         * @return true 
         * @return false 
         */
        virtual bool skip() = 0;
        /**
         * @brief return to the previous song in the buffer, when the current song is over 5 seconds, restart current song
         * 
         * @return true 
         * @return false 
         */
        virtual bool previous() = 0;
    protected:
        /**
         * @brief Get the relative song at current index + i
         * 
         * @param i 
         * @return uint64_t 
         */
        uint64_t get_relative(int i);
    protected:
        std::vector<int> m_songs;
        int m_current_song;
        bool is_playing();
    };
    
} // namespace driver


#endif // SPOTIVY_DRIVER_AUDIO_BASE_H