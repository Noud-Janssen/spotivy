#include "controller/music.h"

namespace controller
{
    std::string music::play(int artist_index, int album_index, int song_index) {
        current_song = get_artists()[artist_index].get_albums()[album_index][song_index];
        return current_song.get_album();
    }

    std::string music::pause() {
        return "Paused: " + current_song.get_song();
    }

    void music::skip() {
        m_queue.next();
    }

    std::vector<model::artist> music::get_artists() {
        return model::artist::all();
    }

    model::artist music::find_artist(std::string s)
    {
        std::vector<model::artist> artists = get_artists();
        for (model::artist art : artists) {
            if (art.get_name() == s) {
                return art;
            }
        }
        return model::artist(s);

    }
} // namespace controller
