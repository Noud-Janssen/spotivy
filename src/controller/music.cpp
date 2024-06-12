#include "controller/music.h"

namespace controller
{
    void music::play() {
        
    }

    void music::pause() {

    }

    void music::skip() {
        
    }

    std::vector<model::artist> music::get_artists() {
        return model::artist::all();
    }

    model::artist music::find_artist(std::string s)
    {
        std::vector<model::artist> artists = get_artists();
        for (model::artist art : artists) {
            if (art.get_name() == s) {
                return art;
            }
        }
        return model::artist(s);

    }
} // namespace controller
