#include "Library.h"
#include "Song.h"
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <algorithm>

/** Library Constructor
@param fileName - name of the file to be read off of. */
Library::Library(std::string fileName)  {

    std::vector<std::string> title, artist, album, year;
    std::string input, titlea, artista, albuma, yeara;
    std::ifstream file (fileName.c_str());

    while (std::getline(file, input))  {

        std::stringstream linestream(input);

        std::getline(linestream, titlea , ',');
        std::getline(linestream, artista, ',');
        std::getline(linestream, albuma , ',');
        std::getline(linestream, yeara  , ',');

        title.push_back(titlea);
        artist.push_back(artista);
        album.push_back(albuma);
        year.push_back(yeara);

    }//end while

    for (int i = 0; i < year.size(); i++)  {
        Song mySong = Song(title[i], artist[i], album[i], year[i]);
        songVec.push_back(mySong);
    }//end for

}//end library

/** Write to File - Allows the user to write to the file.
@param fileName - the name of the file. */
void Library::writeToFile(std::string fileName)  {

    std::ofstream file;
    file.open (fileName.c_str());

    for (int i = 0; i < songVec.size(); i++)  {
        file << songVec[i];
    }//end for

    file.close();

}//end writeToFile

/** Search Title - Lets the user search by titles.
@param title - title the user wants to find.
@param libObj - Library object. */
void Library::searchTitle(std::string title, Library libObj)  {

    bool found = false;
    int index = -1;
    for (int i = 0; i < libObj.songVec.size(); i++)  {
        if (songVec[i].getTitle() == title)  {
            found = true;
            index = i;
        }//end if
    }//end for
    if (found == true)  {
        std::cout << "\n" << songVec[index] << std::endl;
    }//end if

}//end searcher

/** Search Artists - Lets the user search by artist.
@param artist - the artist the user wants to find.
@param libObj - library object. */
void Library::searchArtist(std::string artist, Library libObj)  {

    bool found = false;
    std::vector<int> index;
    for (int i = 0; i < libObj.songVec.size(); i++)  {
        if (songVec[i].getArtist() == artist)  {
            found = true;
            index.push_back(i);
        }//end if
    }//end for
    if (found == true && index.size() > 1)  {
        std::cout << "\n";
        for (int i = 0; i < index.size(); i++)  {
            std::cout << i + 1 << ": " << songVec[index[i]];
        }//end for
        std::cout << "\n";
    }//end if
    else {
        std::cout << "\n";
        std::cout << songVec[index[0]];
        std::cout << "\n";
    }//end else

}//end searcher

/** Search Album - Lets the user search by album.
@param album - album the user wants to search by.
@param libObj - Library object. */
void Library::searchAlbum(std::string album, Library libObj)  {

    bool found = false;
    std::vector<int> index;
    for (int i = 0; i < libObj.songVec.size(); i++)  {
        if (songVec[i].getAlbum() == album)  {
            found = true;
            index.push_back(i);
        }//end if
    }//end for
    if (found == true && index.size() > 1)  {
        std::cout << "\n";
        for (int i = 0; i < index.size(); i++)  {
            std::cout << i + 1 << ": " << songVec[index[i]];
        }//end for
        std::cout << "\n";
    }//end if
    else {
        std::cout << "\n";
        std::cout << songVec[index[0]];
        std::cout << "\n";
    }//end else

}//end searcher

/** Search Year - Lets the user search by year.
@param decade - the decade the user is looking for.
@param libObj - Library object. */
void Library::searchYear(int decade, Library libObj)  {

    bool found = false;
    int foundDate;
    std::vector<int> index;
    for (int i = 0; i < libObj.songVec.size(); i++)  {
        if (songVec[i].getYear() < 2000) {
            foundDate = songVec[i].getYear() - 1900;
        }//end if
        else {
            foundDate = songVec[i].getYear() - 2000;
        }//end else
        if (foundDate >= decade && foundDate <= decade + 9)  {
            found = true;
            index.push_back(i);
        }//end if
    }//end for
    if (found == true && index.size() > 1)  {
        std::cout << "\n";
        for (int i = 0; i < index.size(); i++)  {
            std::cout << i + 1 << ": " << songVec[index[i]];
        }//end for
        std::cout << "\n";
    }//end if
    else {
        std::cout << "\n";
        std::cout << songVec[index[0]];
        std::cout << "\n";
    }//end else

}//end searcher

/** Add Song To Library - Lets the user add a song to the library.
@param newSong - song the user wants to add. */
void Library::addSongLib(Song newSong)  {

    songVec.push_back(newSong);

}//end add

/** Remove Song From Library - Lets the user remove a song from the library.
@param index - the index the user wants to remove. */
void Library::removeSongLib(int index)  {

    songVec.erase(songVec.begin() + index);

}//end remover

/** Remove By Title - Lets the user remove a song by title.
@param silly - it's a silly string. */
void Library::removeByTitle(std::string silly)  {

    int index = -1;
    for (int i = 0; i < songVec.size(); i++)  {
        if (songVec[i].getTitle() == silly)  {
            index = i;
        }//end if
        else {/*1_1*/}
    }//end for

    if (index != -1)  {
        songVec.erase(songVec.begin() + index);
    }//end if
    else {/*hello*/}

}//end removeByTitle

/** Print Vector Unsorted - Prints out the vector unsorted. */
void Library::printVectorNotSorted()  {

    for (int i = 0; i < songVec.size(); i++)  {
        if (i < 9) {
            std::cout << (i + 1) << " : " << songVec[i];
        }//end if
        else  {
            std::cout << (i + 1) << ": " << songVec[i];
        }//end else
    }//end for
    std::cout << "\n";

}//end printVectorNotSorted

/** Print Vector - Sorts, then prints, the song vector. */
void Library::printVector()  {

    std::vector<Song> sortedVec;
    std::vector<Song> finalSortedVec;

    for (int i = 0; i < songVec.size(); i++)  {
        sortedVec.push_back(songVec[i]);
    }//end for

    //Sort the vector.
    for (int i = 0; i < sortedVec.size(); i++)  {

        int lowest = i;

        for (int j = (i + 1); j < sortedVec.size(); j++)  {
            if (sortedVec[lowest] > sortedVec[j])  {
                lowest = j;
            }//end if
        }//end for

        Song swapVar = sortedVec[i];
        sortedVec[i] = sortedVec[lowest];
        sortedVec[lowest] = swapVar;

    }//end for

    for (int i = 0; i < sortedVec.size(); i++)  {
        finalSortedVec.push_back(sortedVec[i]);
    }

    std::cout << "\n";
    std::cout << "Number of Songs: " << finalSortedVec.size() << "\n" << std::endl;
    std::cout << "Songs Listed in Alphabetical Order:" << "\n" << std::endl;
    for (int i = 0; i < finalSortedVec.size(); i++)  {
        if (i < 9) {
            std::cout << (i + 1) << " : " << finalSortedVec[i];
        }//end if
        else  {
            std::cout << (i + 1) << ": " << finalSortedVec[i];
        }//end else
    }//end for
    std::cout << "\n";

}//end printVector

/** Get Size - Returns the size of the song vector. */
int Library::getSize()  {

    return songVec.size();

}//end getSize
