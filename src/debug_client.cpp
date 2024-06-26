#include "debug_client.h"

#include "model/album.h"
#include "model/user.h"

#include <iostream>
#include <sstream>

debug_client::debug_client() : m_running(true) {}

bool isdigit(const std::string &s)
{
    for (char c : s)
    {
        if (!std::isdigit(c)) {
            return false;
        }
    }
    return true;
}

void debug_client::init()
{
    define("exit", [&](std::vector<std::string> strings) { m_running = false; });
    define("clear",
           [&](std::vector<std::string> strings)
           {
#ifdef __unix__
               std::system("clear");
#else
        std::system("cls");
#endif // __unix__
           });
    define("help",
           [&](std::vector<std::string> strings)
           {
               std::cout << " ━━━━ Basic Commands ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << std::endl;
               std::cout << " ─ exit                           Exit the program" << std::endl;
               std::cout << " ─ clear                          Clear the screen" << std::endl;
               std::cout << " ─ help                           Show this help screen" << std::endl << std::endl;
               std::cout << " ━━━━ Info Commands ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << std::endl;
               std::cout << " ─ List [ARTIST] [ALBUM]          Show a list of items" << std::endl << std::endl;
               std::cout << " ━━━━ Play Commands ━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━" << std::endl;
               std::cout << " ─ play  [ARTIST] [ALBUM] [SONG]  play the selected song" << std::endl;
               std::cout << " ─ playlist || pl                 subcommands to use for playlists" << std::endl;
               std::cout << " ─ queue    || q                  subcommands to use the queue system" << std::endl;
               std::cout << " ─ skip                           skip to the next song in the queue" << std::endl;
               std::cout << " ─ pause                          pause the current playing song" << std::endl
                         << std::endl;
               // std::cout << " ─ previous                       go back one song in the queue" << std::endl;
           });

    define("list",
           [&](std::vector<std::string> strings)
           {
               if (strings.size() == 1)
               {
                   std::cout << "Artists: " << std::endl;
                   std::vector<model::artist> artists = m_music_controller.get_artists();
                   for (int i = 0; i < artists.size(); i++)
                   {
                       if (i == artists.size() - 1)
                       {
                           std::cout << " ┗━[" << i << "] " << artists[i].get_name() << std::endl;
                       }
                       else
                       {
                           std::cout << " ┣━[" << i << "] " << artists[i].get_name() << std::endl;
                       }
                   }
               }
               if (strings.size() == 2)
               {
                   model::artist artist = m_music_controller.get_artists()[std::stoi(strings[1])];
                   std::cout << "Albums of " << artist.get_name() << ":" << std::endl;
                   // LIST ALL ALBUMS
                   std::vector<model::album> albums = artist.get_albums();
                   for (int i = 0; i < albums.size(); i++)
                   {
                       if (i == albums.size() - 1)
                       {
                           std::cout << " ┗━[" + std::to_string(i) + "] " << albums[i].get_title() << std::endl;
                           for (size_t j = 0; j < albums[i].get_size(); j++)
                           {
                               if (j == albums[i].get_size() - 1)
                               {
                                   std::cout << "   ┗[";
                               }
                               else
                               {
                                   std::cout << "   ┣[";
                               }
                               std::cout << (j) << "] " << albums[i][j].get_song() << std::endl;
                           }
                       }
                       else
                       {
                           std::cout << " ┣━[" + std::to_string(i) + "] " << albums[i].get_title() << std::endl;
                           for (size_t j = 0; j < albums[i].get_size(); j++)
                           {
                               if (j == albums[i].get_size() - 1)
                               {
                                   std::cout << " ┃ ┗[";
                               }
                               else
                               {
                                   std::cout << " ┃ ┣[";
                               }
                               std::cout << (j) << "] " << albums[i][j].get_song() << std::endl;
                           }
                       }
                   }
               }
           });

    define("queue",
           [&](std::vector<std::string> strings)
           {
               if (strings.size() == 1)
               {
                   if (m_music_controller.get_queue().get_size() == 0)
                   {
                       std::cout << "queue is empty" << std::endl;
                   }
                   for (int i = 0; i < m_music_controller.get_queue().get_size(); i++)
                   {
                       if (m_music_controller.get_queue().get_current_index() == i)
                       {
                           std::cout << " ○ ";
                       }
                       std::cout << m_music_controller.get_queue()[i].get_song() << std::endl;
                   }
               }
               else
               {
                   if (strings[1] == "add")
                   {
                       std::cout << "TODO: add functionality of adding songs, playlists and albums to the queue"
                                 << std::endl;
                   }
                   else if (strings[1] == "clear")
                   {
                       m_music_controller.get_queue().clear();
                   }
               }
           });
    define("q",
           [&](std::vector<std::string> strings)
           {
               strings[0] = "queue";
               mock(strings);
           });

    define("play",
           [&](std::vector<std::string> strings)
           {
               if (strings.size() < 3 || strings.size() > 4)
               {
                   std::cout << "play [artist] [album] [song]" << std::endl;
               }
               else if (strings.size() == 3)
               {
                   m_music_controller.play(std::stoi(strings[1]), std::stoi(strings[2]));
                   std::cout << "Now playing: " << m_music_controller.get_queue().get_current().get_song() << std::endl;
               }
               else if (strings.size() == 4)
               {
                   m_music_controller.play(std::stoi(strings[1]), std::stoi(strings[2]), std::stoi(strings[3]));
                   std::cout << "Now playing: " << m_music_controller.get_queue().get_current().get_song() << std::endl;
               }
           });

    define("pause",
           [&](std::vector<std::string> strings)
           {
               if (m_music_controller.is_playing()) {
                std::cout << "Paused: " << m_music_controller.get_queue().get_current().get_song() << std::endl;
               } else {
                std::cout << "No song is playing."<< std::endl;
               }
           });

    define(
        "playlist",
        [&](std::vector<std::string> strings)
        {
            const std::function<void()> print_help = []()
            {
                std::cout << " ━━━━ Info Commands "
                             "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
                             "━━━━━━━━━━━━━━━"
                          << std::endl;
                std::cout << " ─ playlist list                                   Show a list of your own playlists"
                          << std::endl;
                std::cout
                    << " ─ playlist list [index]                           Show a list of songs in the given playlist"
                    << std::endl;
                std::cout
                    << " ─ playlist list [index] from <user>               Show a list of songs in the given playlist"
                    << std::endl;
                std::cout << " ─ playlist list all                               Show a list of all playlists with "
                             "their owner\n"
                          << std::endl;
                std::cout << " ━━━━ Play Commands "
                             "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
                             "━━━━━━━━━━━━━━━"
                          << std::endl;
                std::cout << " ─ playlist play [playlist index]                  Play a playlist" << std::endl;
                std::cout << " ─ playlist play [playlist index] from <user>      play a playlist from a selected user\n"
                          << std::endl;
                std::cout << " ━━━━ CRUD Commands "
                             "━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━"
                             "━━━━━━━━━━━━━━━"
                          << std::endl;
                std::cout
                    << " ─ playlist create <name>                                              create a new playlist"
                    << std::endl;
                std::cout << " ─ playlist add [artist index] [album index] to [playlist index]       add a album to a "
                             "given playlist"
                          << std::endl;
                std::cout << " ─ playlist add [artist index] [album index] [song index] to [playlist index]       add "
                             "a song to a given playlist"
                          << std::endl;
            };

            if (strings.size() == 1)
            {
                print_help();
            }
            else if (strings[1] == "add")
            {
            }
            else if (strings[1] == "remove")
            {
                if (strings.size() == 3 && isdigit(strings[2]))
                {
                    std::vector<model::playlist> &lists = model::user::get_logged_in().get_playlists();
                    lists.erase(lists.begin() + std::stoi(strings[2]));
                }
            }
            else if (strings[1] == "play")
            {
                if (strings.size() == 3 && isdigit(strings[2]))
                {
                    m_music_controller.play(model::user::get_logged_in().get_playlists()[std::stoi(strings[2])]);
                }
            }
            else if (strings[1] == "list")
            {
                if (strings.size() == 2)
                {
                    std::cout << "Your playlists:" << std::endl;
                    for (size_t i = 0; i < model::user::get_logged_in().get_playlists().size(); i++)
                    {
                        std::cout << "[ " + std::to_string(i) + " ] "
                                  << model::user::get_logged_in().get_playlists()[i].get_title() << std::endl;
                    }
                }
                if (strings.size() > 2)
                {
                    if (strings[2] == "all")
                    {
                        std::cout << "Your playlists:" << std::endl;
                        for (size_t i = 0; i < model::user::get_logged_in().get_playlists().size(); i++)
                        {
                            std::cout << "[ " + std::to_string(i) + " ] "
                                      << model::user::get_logged_in().get_playlists()[i].get_title() << std::endl;
                        }
                        for (size_t i = 0; i < model::user::all().size(); i++)
                        {
                            if (model::user::all()[i] != model::user::get_logged_in())
                            {
                                std::cout << "\nUser: " << model::user::all()[i].get_name() << std::endl;
                                for (size_t j = 0; j < model::user::all()[i].get_playlists().size(); j++)
                                {
                                    std::cout << "[ " + std::to_string(j) + " ] "
                                              << model::user::all()[i].get_playlists()[j].get_title() << std::endl;
                                }
                            }
                        }
                    }
                    if (isdigit(strings[2])) {
                        if (strings.size() == 3){
                            model::playlist list = model::user::get_logged_in().get_playlists()[std::stoi(strings[2])];
                            std::cout << list.get_title() << ":" << std::endl;
                            for (size_t i = 0; i < list.get_size(); i++)
                            {
                                std::cout << list[i].get_song() << " : " << list[i].get_artist() << std::endl;
                            }
                        }
                    }
                }
            }
            else if (strings[1] == "create")
            {
                std::string input;
                if (strings.size() < 3)
                {
                    std::cout << "Name: ";
                    getline(std::cin, input);
                }
                else
                {
                    input = strings[2];
                }

                model::user::get_logged_in().get_playlists().emplace_back(input);
            }
            else
            {
                print_help();
            }
        });

    define("pl",
           [&](std::vector<std::string> strings)
           {
               strings[0] = "playlist";
               mock(strings);
           });

    define("skip",
           [&](std::vector<std::string> strings)
           {
               m_music_controller.get_queue().next();
               std::cout << "Now playing: " << m_music_controller.get_queue().get_current().get_song() << std::endl;
           });

    m_commands[1].fxn({});
}

void debug_client::login()
{
    std::string help_text = "User Name: ";
    int selected_user_index = -1;
    while (m_running)
    {
        std::string input_name;
        std::cout << "username: ";
        getline(std::cin, input_name);

        std::string input_pwd;
        std::cout << "password: ";
        getline(std::cin, input_pwd);

        for (size_t i = 0; i < model::user::all().size(); i++)
        {
            if (model::user::all()[i].get_name() == input_name)
            {
                if (model::user::all()[i].login(input_pwd))
                {
                    m_running = false;
                };
            };
        }

        mock({"clear"});
    }

    m_running = true;
}

void debug_client::loop()
{

    std::cout << "Welcome to Spotivy!" << std::endl;

    while (m_running)
    {
        std::cout << "\x1b[30;42m " + model::user::get_logged_in().get_name() + " 𝄞 Spotivy \x1b[32m▶\x1b[0m ";

        std::string input;

        getline(std::cin, input);

        std::vector<std::string> args;

        std::istringstream stream(input);
        std::string word;
        while (stream >> word)
        {
            args.push_back(word);
        }

        bool found_cmd = false;

        for (commands_t cmd : m_commands)
        {
            if (args[0] == cmd.text)
            {
                found_cmd = true;
                cmd.fxn(args);
            }
        }
        if (!found_cmd)
        {
            std::cout << args[0] << " is not a viable command!" << std::endl;
        }
    }
}

void debug_client::mock(std::vector<std::string> input)
{
    for (commands_t cmd : m_commands)
    {
        if (input[0] == cmd.text)
        {
            cmd.fxn(input);
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