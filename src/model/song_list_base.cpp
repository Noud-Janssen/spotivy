#include "model/song_list_base.h"

namespace model
{
    void song_list_base::add(song s) {
        
    }

    void song_list_base::add(song_list_base list) {
        
    }

    song song_list_base::operator[](size_t index) {
        return song(1);
    }

    size_t song_list_base::get_size() {
        return 6;
    }

    std::string song_list_base::get_title() {
        return m_title;
    }
} // namespace model
