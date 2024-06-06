#include "debug_client.h"

#include <iostream>
#include <sstream>

debug_client::debug_client()
    : m_running(true)
{

}

void debug_client::init() 
{
    define("exit", [&](std::vector<std::string> strings){ 
        m_running = false;
    });
    define("clear", [&](std::vector<std::string> strings){ 
        std::system("clear");
    });
    define("help", [&](std::vector<std::string> strings) {
        std::cout << " -- exit                  Exit the program" << std::endl;
        std::cout << " -- clear                 Clear the screen" << std::endl;
        std::cout << " -- help                  Show this help screen" << std::endl;
    });

}

void debug_client::loop()
{
    
    while (m_running) {
        std::cout << "Spotivy -> ";
        
        std::string input;

        getline(std::cin, input);

        std::vector<std::string> args;

        std::istringstream stream(input);
        std::string word;
        while (stream >> word) {
            args.push_back(word);
        }

        bool found_cmd = false;
        
        for (commands_t cmd : m_commands) {
            if (args[0] == cmd.text) {
                found_cmd = true;
                cmd.fxn({});
            }
        }
        if (!found_cmd) {
            std::cout << args[0] << " is not a viable command!" << std::endl;
        }
    }
}

void debug_client::define(std::string command, cmd_callback fxn)
{
    commands_t cmd;
    cmd.text = command;
    cmd.fxn = fxn;
    m_commands.emplace_back(cmd);
}