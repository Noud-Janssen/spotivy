#ifndef SPOTIVY_MODEL_SONG_H
#define SPOTIVY_MODEL_SONG_H

#include <cstdint>
#include <string>
#include <vector>
namespace model
{
    class song
    {
    public:
        song(std::string artist, std::string album, std::string name);
        song(uint64_t song_id);
        ~song() = default;
    public:
        uint64_t get_id();

        std::string get_file_path();
        std::string get_genre();
        std::string get_artist();
        std::string get_song();
        std::string get_filetype();
        std::vector<std::string> get_collabs();   
        std::string get_album();
        static std::vector<song> all(); 

    private:
        uint64_t m_id;     
    
    };

    
} // namespace model


#endif // SPOTIVY_MODEL_SONG_H