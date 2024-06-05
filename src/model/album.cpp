#include "model/album.h"

namespace model
{
    album::album(std::string title, std::vector<song> songs) : song_list_base(title) {
        for (size_t i = 0; i < songs.size(); i++) {
            m_songs.push_back(songs[i]);
        }
    }
} // namespace model