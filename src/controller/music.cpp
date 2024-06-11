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
} // namespace controller
