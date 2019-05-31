#include <iostream>
#include "song.hpp"

int main() {

    Song touch_song;

    touch_song.add_title("Touch by daft punk");

    std::cout << touch_song.get_title();

}