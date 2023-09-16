#include <iostream>
#include <ctime>
#include <iomanip>
#include <vector>
#include <stdlib.h>

class Track
{
public:
    std::string name;
    std::time_t time;
    int duration;
};

class AudioPlayer
{
    std::vector<Track> library;
    Track current_track;
    bool is_playing;

public:
    void add_track(Track track)
    {
        library.push_back(track);
    }

    void play(std::string track_name) {



        for (Track track : library) {
            if (track.name == track_name) {
                std::tm* current = std::localtime(&track.time);
                current_track = track;
                std::cout << "Now playing: " << track.name << " - (" << track.duration  << " sec) "
                                             << std::put_time(current, "%Y/%m/%d") <<  std::endl;
                is_playing = true;
            }
        }
    }

    void pause() {
        if (is_playing) {
            std::cout << "Paused: " << current_track.name << std::endl;
            is_playing = false;
        }
    }

    void next() {
        if(library.size() == 0) {
            std::cout << "No tracks available." << std::endl;
            return;
        }

        int index = rand() % library.size();
        Track track = library[index];
        current_track = track;
        std::tm* current = std::localtime(&track.time);
        std::cout << "Playing next track: " << track.name <<  " - (" << track.duration  << " sec) "
                                            << std::put_time(current, "%Y/%m/%d") << std::endl;
        is_playing = true;
    }

    void stop() {
        if (is_playing) {
            std::cout << "Stopped: " << current_track.name << std::endl;
            is_playing = false;
        }
    }

};


int main() {

    Track track_1{"Polo ship", time(nullptr), 180};
    Track track_2{"Wele wonko", time(nullptr), 230};
    Track track_3{"Unga bunga", time(nullptr), 310};

    AudioPlayer player;

    player.add_track(track_1);
    player.add_track(track_2);
    player.add_track(track_3);

    std::string cmd;
    while(true) {
        std::cout << "Enter command: " << std::endl;
        std::cin >> cmd;

        if (cmd == "play")
        {
            std::cout << "Enter Track Name: ";
            std::string track_name;
            std::cin.ignore();
            getline (std::cin, track_name);
            player.play(track_name);

        }else if (cmd == "pause")
        {
            player.pause();
        }else if (cmd == "next")
        {
            player.next();
        }else if (cmd == "stop")
        {
            player.stop();
        }else if (cmd == "exit")
        {
            break;
        } else std::cerr << "incorrect input\n";
    }
    return 0;
}
