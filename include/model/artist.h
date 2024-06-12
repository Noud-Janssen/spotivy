#ifndef SPOTIVY_MODEL_ARTIST_H
#define SPOTIVY_MODEL_ARTIST_H

#include <vector>
#include <string>

#include "model/album.h"

namespace model
{
    class artist
    {
    public:
        /**
         * @brief Construct a new artist object
         * 
         */
        artist(std::string name);
        /**
         * @brief Destroy the artist object
         * 
         */
        ~artist() = default;
    public:
        /**
         * @brief get all artists in the system
         * 
         * @note these are hardcoded instances for now
         * 
         * @return std::vector<artist> 
         */
        static std::vector<artist> all();
        /**
         * @brief Get the name of the artist
         * 
         * @return std::string 
         */
        std::string get_name();
        /**
         * @brief Get a vector of all albums belonging to this artist
         * 
         * @return std::vector<model::album> 
         */
        std::vector<model::album> get_albums();
    private:
        std::string m_name;
        std::vector<model::album> m_albums;
    };
    
    
} // namespace model



#endif // SPOTIVY_MODEL_ARTIST_H