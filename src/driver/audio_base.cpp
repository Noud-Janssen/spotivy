#include "driver/audio_base.h"

namespace driver
{
    bool audio_base::add_to_buffer(uint64_t songid) {
        m_songs.emplace_back(songid);
        return true;
    }

    uint64_t audio_base::get_relative(int i) {
        return m_songs[m_current_song + i];
    }
} // namespace driver
