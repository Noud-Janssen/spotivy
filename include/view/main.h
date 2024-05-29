#ifndef SPOTIVY_VIEW_MAIN_H
#define SPOTIVY_VIEW_MAIN_H

#include "ftxui/component/component.hpp"

#include "view/component/audio_controls.h"

namespace view
{
    class main : public component::base
    {
    public:
        main();
        ~main() = default;
    public:
        /**
         * @brief initialise the view
         * 
         */
        void init();
    private:
        component::audio_controls m_controls;

        ftxui::ScreenInteractive m_screen;
    };
} // namespace view


#endif // SPOTIVY_VIEW_MAIN_H