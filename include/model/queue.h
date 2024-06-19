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
        void next();
        void previous();
        song get_current();
        void clear();
    private:
        int m_index;
    };
    
} // namespace model


#endif // SPOTIVY_MODEL_QUEUE_H