#ifndef SPOTIVY_VIEW_COMPONENTS_AUDIO_CONTROLS_H
#define SPOTIVY_VIEW_COMPONENTS_AUDIO_CONTROLS_H

#include "view/component/base.h"
#include "ftxui/component/screen_interactive.hpp"

#include "model/song.h"
#include <functional>

namespace view::component
{
    class audio_controls : public base
    {
    public:
        audio_controls();
        ~audio_controls() = default;
    public:
        void init();
        void set_current_song(model::song s);
        void set_play_fxn(std::function<void()> fxn);
        void set_next_fxn(std::function<void()> fxn);
        void set_prev_fxn(std::function<void()> fxn);
    private:

        // functions
        std::function<void()> m_play_fxn;
        std::function<void()> m_next_fxn;
        std::function<void()> m_prev_fxn;

        // components
        ftxui::Component m_play_btn;
        ftxui::Component m_next_btn;
        ftxui::Component m_prev_btn;

        // models
        model::song m_current_song;
        std::string m_song_name;
        std::string m_song_album;
        std::string m_song_artist;
    };

    
} // namespace view::component


#endif // SPOTIVY_VIEW_COMPONENTS_AUDIO_CONTROLS_H