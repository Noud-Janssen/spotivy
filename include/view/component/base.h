#ifndef SPOTIVY_VIEW_COMPONENT_BASE_H
#define SPOTIVY_VIEW_COMPONENT_BASE_H

#include "ftxui/component/component.hpp"

namespace view::component
{
    class base
    {
    public:
        /**
         * @brief Construct a new base object
         * 
         */
        base() = default;
        /**
         * @brief Destroy the base object
         * 
         */
        ~base() = default;
    public:
        /**
         * @brief Get the component object
         * 
         * @return ftxui::Component
         */
        ftxui::Component get_component();
        /**
         * @brief Get the element object
         * 
         * @return ftxui::Element
         */
        ftxui::Element get_element();
    protected:
        ftxui::Component m_component;
        ftxui::Element m_element;
    };

} // namespace view::component


#endif // SPOTIVY_VIEW_COMPONENT_BASE_H