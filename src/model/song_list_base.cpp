#include "model/song_list_base.h"

namespace model
{
    song_list_base::song_list_base(std::string title) : m_title(title) {

    }
    
    void song_list_base::add(song s) {
        m_songs.push_back(s);
    }
     
    void song_list_base::remove(song s) {
        for (size_t i = 0; i < m_songs.size(); i++) {
            if (m_songs[i] == s) {
                m_songs.erase(m_songs.begin() + i);
                return;
            }
        }
    }

    void song_list_base::add(song_list_base list) {
        for (size_t i = 0; i < list.get_size(); i++) {
            add(list[i]);
        }
    }

    song song_list_base::operator[](size_t index) {
        return m_songs[index];
    }

    size_t song_list_base::get_size() {
        return m_songs.size();
    }

    std::string song_list_base::get_title() {
        return m_title;
    }
} // namespace model
