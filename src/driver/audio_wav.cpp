#include "driver/audio_wav.h"

namespace driver
{
    audio_wav::audio_wav()
        : m_index(-1)
    {
    }

    void audio_wav::loop()
    {
        if (done()) {
            skip();
        }
    }

    bool audio_wav::add_to_buffer(uint64_t song)
    {
        m_buffer.emplace_back(song);
        ++m_index;
        return true;
    }

    bool audio_wav::play() 
    {
        if (m_music_player.openFromFile("../assets/test.wav")) {
            m_music_player.play();
        };
        if (m_index >= 0) {
            // m_music_player.openFromFile(m_buffer[m_index].get_file_path());
            // m_music_player.play();
            return true;

        } else {
            return false;
        }
    }

    bool audio_wav::pause() 
    {
        m_music_player.pause();
        return true;
    }

    bool audio_wav::done()
    {
        return m_music_player.getStatus() == sf::SoundSource::Status::Stopped;
    }

    bool audio_wav::skip() 
    {
        if (m_index < m_buffer.size()) {
            m_index++;
        }
        play();
        return true;
    }

    bool audio_wav::previous() 
    {
        if (m_index > 0) {
            m_index--;
        }
        play();
        return true;
    }
} // namespace driver
