#include "model/queue.h"

namespace model
{
    queue::queue() 
        : 
    song_list_base("queue"),
    m_index(0) 
    {

    }

    void queue::next() {
        if(m_index == m_songs.size() - 1) {
            return;
        }
        m_index++;
    }

    void queue::previous() {
        if(m_index == 0) {
            return;
        }
        m_index--;
    }
    
    void queue::clear() {
        m_songs.clear();
        m_index = 0;
    }

    song queue::get_current() {
        return m_songs[m_index];
    }

    int queue::get_current_index() {
        return m_index;
    }


} // namespace model
