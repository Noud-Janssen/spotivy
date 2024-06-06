#include "model/album.h"

namespace model
{
    album::album(std::string name, std::vector<song> songs) : song_list_base(name)
    {
        for (auto s : songs)
        {
            m_songs.emplace_back(s);
        }
    }

} // namespace model