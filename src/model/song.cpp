#include "model/song.h"

namespace model
{
    song::song(std::string artist, std::string album, std::string name) {
        
    }

    song::song(uint64_t song_id) 
        : m_id(song_id)
    {
        
    }

    uint64_t song::get_id() {
        return m_id;
    }

    std::string song::get_file_path() {
        return get_artist() + "/" + get_album() + "/" + get_song();
    }

    std::string song::get_genre() {
        return "rap";
    }

    std::string song::get_artist() {
        return "boef";
    }

    std::string song::get_filetype() {
        return ".wav";
    }   

    std::vector<std::string> song::get_collabs() {
        return {"habiba", "habiba2", "habiba3"};
    }   

    std::string song::get_album() {
        return "habiba";
    }

    std::string song::get_song() {
        return "habiba.wav";
    } 

    std::vector<song> song::all() {
        return {song(1), song(2), song(3)};
    }
} // namespace model
