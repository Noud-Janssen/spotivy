#ifndef SPOTIVY_CONTROLLER_SONG_LIST_BASE_H
#define SPOTIVY_CONTROLLER_SONG_LIST_BASE_H

#include <cstdint>
#include <string>
#include <vector>
#include "song.h"

namespace model
{
    class song_list_base
    {
    public:
        void add(song);
        void add(song_list_base);
        song operator[](size_t index);
        size_t get_size(); 
        std::string get_title();

    private:
        std::string m_title;     
    
    };

    
} // namespace model


#endif // SPOTIVY_CONTROLLER_SONG_LIST_BASE_H