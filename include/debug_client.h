#ifndef SPOTIVY_DEBUG_CLIENT_H
#define SPOITVY_DEBUG_CLIENT_H

#include <vector>
#include <string>
#include <functional>

typedef std::function<void(std::vector<std::string>)> cmd_callback;

class debug_client
{
public:
    debug_client();
    ~debug_client() = default;
public:
    void init();
    void loop();
private:
    void define(std::string s, cmd_callback fxn);
private:
    struct commands_t {
        std::string text;
        cmd_callback fxn;
    };
    std::vector<commands_t> m_commands;

    bool m_running;
};


#endif // SPOTIVY_DEBUG_CLIENT_H