#ifndef SPOTIVY_DEBUG_CLIENT_H
#define SPOITVY_DEBUG_CLIENT_H

#include <vector>
#include <string>
#include <functional>

#include "controller/music.h"

typedef std::function<void(std::vector<std::string>)> cmd_callback;

class debug_client
{
public:
    /**
     * @brief Construct a new debug client object
     * 
     */
    debug_client();
    /**
     * @brief Destroy the debug client object
     * 
     */
    ~debug_client() = default;
public:
    /**
     * @brief initialise the debug client
     * 
     */
    void init();
    /**
     * @brief loop over the debug client
     * 
     */
    void loop();
private:
    void define(std::string s, cmd_callback fxn);
private:
    struct commands_t {
        std::string text;
        cmd_callback fxn;
    };
    std::vector<commands_t> m_commands;

    controller::music m_music_controller;

    bool m_running;
};


#endif // SPOTIVY_DEBUG_CLIENT_H