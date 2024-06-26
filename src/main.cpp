#include "debug_client.h"
#include "driver/audio_wav.h"
#include "model/artist.h"
#include "model/song.h"
#include "model/song_list_base.h"
#include <iostream>

#include "model/user.h"

int main(int argc, char const *argv[])
{
#ifndef __UNIX__
    std::system("chcp 65001");
#endif

    // Hardcoded variables
    model::user::create("Noud", "Welkom123");
    model::user::create("Jordi", "pwd");
    // model::user::all()[0].login("Welkom123");

    model::user::all()[0].get_playlists().emplace_back("Bangers");
    model::user::all()[0].get_playlists().back().add(
        model::artist::all()[0].get_albums()[0][2]
    );

    model::user::all()[0].get_playlists().back().add(
        model::artist::all()[1].get_albums()[0][2]
    );

    model::user::all()[0].get_playlists().emplace_back("Sad times :(");

    model::user::all()[1].get_playlists().emplace_back("my list");
    model::user::all()[1].get_playlists().emplace_back("Hola list");

    debug_client client;
    client.init();
    client.login();
    client.loop();
    return 0;
}
