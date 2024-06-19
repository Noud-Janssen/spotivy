#include "model/song.h"

namespace model
{
    song::song(std::string artist, std::string album, std::string name) 
        : m_artist(artist), m_album(album), m_name(name)
    {
        
    }

    song::song(uint64_t song_id) 
        : m_id(song_id)
    {
        
    }

    bool song::operator==(const song &s) const {
        return (m_name == s.m_name
            && m_artist == s.m_artist
            && m_album == s.m_album);
    }

    uint64_t song::get_id() {
        return m_id;
    }

    std::string song::get_file_path() {
        return get_artist() + "/" + get_album() + "/" + get_song();
    }

    std::string song::get_genre() {
        return m_genre;
    }

    std::string song::get_artist() {
        return m_artist;
    }

    std::string song::get_filetype() {
        return ".wav";
    }   

    std::vector<std::string> song::get_collabs() {
        return {"a", "b", "c"};
    }   

    std::string song::get_album() {
        return m_album;
    }

    std::string song::get_song() {
        return m_name;
    } 

    std::vector<song> song::all() {
        return {song(1), song(2), song(3)};
    }
} // namespace model
