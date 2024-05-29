#include "view/main.h"
#include <iostream>

namespace view
{
    main::main()
        : m_screen(ftxui::ScreenInteractive::Fullscreen()), m_controls()
    {

    }

    void main::init()
    {


        m_controls.init();
        std::cout << "Initialising view::main" << std::endl;

        m_component = ftxui::Container::Vertical({
            m_controls.get_component()
        });

        m_element = ftxui::vbox({m_controls.get_element()});

        auto render = ftxui::Renderer(m_component, [&] {return m_element;});

        m_screen.Loop(render);
    }
} // namespace view
