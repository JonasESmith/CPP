#include "song.hpp"

// add Song method definitions here:
void Song::add_title(std::string new_title) {

  title = new_title;

}

std::string Song::get_title() {

  return title;

}

void Song::add_artist(std::string artist_name)
{
  artist = artist_name;
}

std::string Song::get_artist()
{
  return artist;
}