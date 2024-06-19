#ifndef SPOTIVY_MODEL_SONG_LIST_BASE_H
#define SPOTIVY_MODEL_SONG_LIST_BASE_H

#include <cstdint>
#include <string>
#include <vector>
#include "song.h"

namespace model
{
    class song_list_base
    {
    public:
        song_list_base(std::string title);
        ~song_list_base() = default;  
    public:
        void add(song s);
        void remove(song s);
        void add(song_list_base list);
        song operator[](size_t index);
        size_t get_size(); 
        std::string get_title();

    protected:
        std::string m_title;   
        std::vector<song> m_songs;  
    };

    
} // namespace model


#endif // SPOTIVY_MODEL_SONG_LIST_BASE_H