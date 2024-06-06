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
        #ifdef __unix__
        std::system("clear");
        #else
        std::system("cls");
        #endif // __unix__

    });
    define("help", [&](std::vector<std::string> strings) {
        std::cout << " -- exit                  Exit the program" << std::endl;
        std::cout << " -- clear                 Clear the screen" << std::endl;
        std::cout << " -- help                  Show this help screen" << std::endl;
    });

    define("list", [&](std::vector<std::string> strings){ 
        if (strings.size() == 1) {
            std::cout << "Artists: " << std::endl;
            std::cout << "TODO: get all artists" << std::endl;
            // LIST ALL ARTISTS
        }
        if (strings.size() == 2) {
            std::cout << "Albums of " << strings[1] << ":" << std::endl;
            std::cout << "TODO: get all albums of given artists " << std::endl;
            // LIST ALL ALBUMS
            // for (model::album alb : m_music_controller.find_artist(strings[1]).get_albums()) {
            //     std::cout << alb.get_name() << std::endl;
            // }
        }
        if (strings.size() == 3) {
            std::cout << "Songs of " << strings[1] << "/" << strings[2] << std::endl;
            std::cout << "TODO: get all songs of given album of given artist" << std::endl;
            // LIST ALL SONGS OF A ALBUM OF A SONG
            // for (model::song s : m_music_controller.find_artist(strings[1]).find_albums(strings[2])) {
            //     std::cout << s.get_name() << std::endl;
            // }
        }
    });

    define("queue", [&](std::vector<std::string> strings){
        if (strings.size() == 1) {
            std::cout << "TODO: get all song in the queue" << std::endl;
        } else {
            if (strings[2] == "add") {

            } else
            if (strings[2] == "clear") {

            }

        }
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
                cmd.fxn(args);
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