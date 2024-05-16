#ifndef SPOTIVY_CONTROLLER_MUSIC_H
#define SPOTIVY_CONTROLLER_MUSIC_H

namespace controller
{
    class music
    {
    public:
        music() = default;
        ~music() = default;
    public:
        void play();
        void pause();
        void skip();

        void add_to(int placeholder, int placeholder2);
    private:
        
    };

    
} // namespace controller


#endif // SPOTIVY_CONTROLLER_MUSIC_H