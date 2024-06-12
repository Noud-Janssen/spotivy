#ifndef SPOTIVY_MODEL_QUEUE_H
#define SPOTIVY_MODEL_QUEUE_H

#include "model/song_list_base.h"

namespace model
{
    class queue : public song_list_base
    {
    public:
        queue();
        ~queue() = default;
    public:
        /**
         * @brief select the next song in the queue
         * 
         */
        void next();
        /**
         * @brief go to the previous song in the queue
         * 
         */
        void previous();
        /**
         * @brief Get the current object
         * 
         * @return song 
         */
        song get_current();
        /**
         * @brief clear the queue
         * 
         */
        void clear();
    private:
        int m_index;
    };
    
} // namespace model


#endif // SPOTIVY_MODEL_QUEUE_H