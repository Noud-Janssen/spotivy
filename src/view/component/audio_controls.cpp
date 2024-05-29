#include "view/component/audio_controls.h"

namespace view::component
{
    audio_controls::audio_controls()
        : m_current_song(0)
    {
        set_current_song(m_current_song);
    }

    void test(std::string s)
    {
        std::system(("notify-send " + s).c_str());
    }


    void audio_controls::init() {
        m_play_btn = ftxui::Button("Play", std::bind(test,"play"));
        m_next_btn = ftxui::Button(">>", std::bind(test,"next"));
        m_prev_btn = ftxui::Button("<<", std::bind(test,"prev"));

        m_component = ftxui::Container::Horizontal({
            m_prev_btn, m_play_btn, m_next_btn
        });

        m_element = ftxui::vbox({
            ftxui::hbox({
                ftxui::text(m_song_name)
            }),
            m_component->Render()
        });
    }

    void audio_controls::set_current_song(model::song s)
    { 
        m_current_song = s;
        m_song_name = s.get_song();
        m_song_album = s.get_album();
        m_song_artist = s.get_artist();
    }


    void audio_controls::set_play_fxn(std::function<void()> fxn) {
        m_play_fxn = fxn;
    }

    void audio_controls::set_next_fxn(std::function<void()> fxn) {
        m_next_fxn = fxn;
    }

    void audio_controls::set_prev_fxn(std::function<void()> fxn) {
        m_prev_fxn = fxn;
    }
} // namespace view::component
