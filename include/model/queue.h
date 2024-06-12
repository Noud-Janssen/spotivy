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
    private:
        
    };
    
} // namespace model


#endif // SPOTIVY_MODEL_QUEUE_H