#include "view/component/base.h"

namespace view::component
{
    ftxui::Component base::get_component()
    {
        return m_component;
    }

    ftxui::Element base::get_element()
    {
        return m_element;
    }
} // namespace view::component
