#include "controller/music.h"
#include <iostream>


namespace controller
{
    music::music()
    {

    }


    void music::play(int artist_index, int album_index, int song_index) {
        m_queue.clear();
        if (song_index < 0) {
            m_queue.add(get_artists()[artist_index].get_albums()[album_index]);
        } else {
            m_queue.add(get_artists()[artist_index].get_albums()[album_index][song_index]);
        }
    }

    void music::play(model::playlist playlist)
    {
        std::cout << "Test" << std::endl;
        m_queue.clear();
        for (size_t i = 0; i < playlist.get_size(); i++)
        {
            m_queue.add(playlist[i]);
        }
    }

    bool music::is_playing()
    {
        if (m_queue.get_size() > 0) {
            return true;
        } else {
            return false;
        }
    }

    std::string music::pause() {
        return "Paused: " + m_queue.get_current().get_song();
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

    model::queue &music::get_queue()
    {
        return m_queue;
    }

} // namespace controller
