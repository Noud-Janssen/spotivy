#include "debug_client.h"

#include <iostream>
#include <sstream>
#include "model/album.h"

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
        std::cout << " ─ exit                           Exit the program" << std::endl;
        std::cout << " ─ clear                          Clear the screen" << std::endl;
        std::cout << " ─ help                           Show this help screen" << std::endl;
        std::cout << " ━━━━ Info Commands ━━━━" << std::endl;
        std::cout << " ─ List  [ARTIST] [ALBUM]         Show a list of items" << std::endl;

        std::cout << " ━━━━ Play Commands ━━━━" << std::endl;
        std::cout << " ─ queue                          subcommands to use the queue system" << std::endl;
        std::cout << " ─ skip                           skip to the next song" << std::endl;
        std::cout << " ─ previous                       go back one song in the queue" << std::endl;
        std::cout << " ─ play  [ARTIST] [ALBUM] [SONG]  play the selected song" << std::endl;
        std::cout << " ─ pause                          pause the current playing song" << std::endl;
    });

    define("list", [&](std::vector<std::string> strings){
        if (strings.size() == 1) {
            std::cout << "Artists: " << std::endl;
            std::vector<model::artist> artists = m_music_controller.get_artists();
            for (int i = 0; i < artists.size(); i++) {
                if (i == artists.size() - 1) {
                    std::cout << " ┗━[" << i << "] " << artists[i].get_name() << std::endl;
                } else {
                    std::cout << " ┣━[" << i << "] " << artists[i].get_name() << std::endl;
                }

            }
        }
        if (strings.size() == 2) {
            model::artist artist = m_music_controller.get_artists()[std::stoi(strings[1])];
            std::cout << "Albums of " << artist.get_name() << ":" << std::endl;
            // LIST ALL ALBUMS
            std::vector<model::album> albums = artist.get_albums();
            for (int i = 0; i < albums.size(); i++) {
                if (i == albums.size() - 1) {
                    std::cout << " ┗━┳━ " << albums[i].get_title() << std::endl;
                    for(size_t j = 0; j < albums[i].get_size(); j++) 
                    {
                        if (j == albums[i].get_size() - 1) {
                            std::cout << "   ┗[";
                        } else {
                            std::cout << "   ┣[";
                        }
                        std::cout << (i * 100 + j) << "] " << albums[i][j].get_song() << std::endl;
                    }
                } else {
                    std::cout << " ┣━┳━ " << albums[i].get_title() << std::endl;
                    for(size_t j = 0; j < albums[i].get_size(); j++) 
                    {
                        if (j == albums[i].get_size() - 1) {
                            std::cout << " ┃ ┗[";
                        } else {
                            std::cout << " ┃ ┣[";
                        }
                        std::cout << (i * 100 + j) << "] " << albums[i][j].get_song() << std::endl;
                    }
                }
                
            }

        }
    });

    define("queue", [&](std::vector<std::string> strings){
        if (strings.size() == 1) {
            std::cout << "TODO: get all song in the queue" << std::endl;
        } else {
            if (strings[1] == "add") {
                std::cout << "TODO: add functionality of adding songs, playlists and albums to the queue" << std::endl;
            } else
            if (strings[1] == "clear") {
                std::cout << "TODO: add functionality of clearing the queue" << std::endl;
            }
        }
    });

    define("play", [&](std::vector<std::string> strings) {
        if (strings.size() == 1) {
            m_music_controller.play();
        } else if (strings.size() == 2) {
            std::cout << "play [ARTIST NUMBER] [SONG NUMBER]" << std::endl;
        } else {
            m_music_player.queue().clear();
            m_music_player.queue().add(m_music_controller.get_artists()[std::stoi(strings[1])].get_song_by_number(std::stoi(strings[2])));
        }
        
    });


    m_commands[1].fxn({});

    std::cout << "Welcome to Spotivy!" << std::endl;

    

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