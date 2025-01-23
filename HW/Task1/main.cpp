#include <iostream>
#include <vector>
#include <ctime>

class Track {
public:
    std::string name;
    std::tm* timeOfCreation;
    int length;

    Track(std::string name = "null", int length = 0){
        this->name = name;
        this->length = length;
        time_t currentTime = time(nullptr);
        this->timeOfCreation = std::localtime(&currentTime);
    }
};

class Player {
public:
    bool isPlaying = false;
    bool isPaused = false;
    bool isStopped = false;
    static std::vector<Track> playlist;

    void play(std::string name) {
        if(!isPlaying) {
            for (Track &t: playlist) {
                if (t.name == name) {
                    isPlaying = true;
                    std::cout << "Name:" << t.name << " length:" << t.length << t.timeOfCreation << std::endl;
                }
            }
        }
    }

    void pause() {
        if(!isPaused) {
            isPaused = true;
            std::cout << "Paused" << std::endl;
        }
    }

    void next() {
        std::srand(time(nullptr));
        int randomIndex = std::rand() % playlist.size();
        play(playlist[randomIndex].name);
    }

    void stop() {
        if(!isStopped) {
            isStopped = true;
            isPlaying = false;
            isPaused = false;
            std::cout << "Stopped" << std::endl;
        }
    }

    void exit() {
        stop();
        std::exit(0);
    }

};


int main() {
    Track track1 = Track("Randomizer", 196);
    Track track2 = Track("6 AM", 179);
    Track track3 = Track("SZN", 200);
    Track track4 = Track("Turn on", 121);
    Track track5 = Track("Paparazzi", 201);
    Track track6 = Track("Niggas in Paris", 165);
    Player::playlist = {track1, track2, track3, track4, track5, track6};

}