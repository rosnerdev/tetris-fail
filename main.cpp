/*
* WARNING! whoever wrote the comments below is an obvious buffoon, as the code in this repository will not be updated, not now and not ever.
* Also, don't take this code as an example for good code. In fact, I have abandoned this project for this exact reason, among others.
*/

//TODO: tetros should not able to overlap! 
//TODO: user should be able to spin tetros(clockwise and anti-clockwise) 
//TODO: user should be able to move tetros to the left and right
//TODO: if a tetro is on the topmost central point, then GAME OVER!
//TODO: implement line elimination as well as tetris, triple, and double
//TODO: implement points and scoreboard

#include <iostream>
#include <string_view>
#include <vector>
#include <windows.h>

using field = std::string_view[12][11];
using tetro = std::string_view[4][4];

void print_field(field& playground) {
    for (auto& row : playground) {
        for (auto& bar : row) {
            std::cout << bar;
        }
    }
}

void spawn_brick(field* playground, tetro brick) {
    for (int curr_line = -1; curr_line < 8; ++curr_line) {
        std::string_view prev_values[4];

        for (int curr_tetroline = 3; curr_tetroline > -1; --curr_tetroline) {
            for (int curr_pix = 0; curr_pix < 4; ++curr_pix) {
                std::string_view curr_playground_pix = (*playground)[curr_line + curr_tetroline][curr_pix + 4];
                prev_values[curr_pix] = curr_playground_pix;

                (*playground)[curr_line + curr_tetroline][curr_pix + 4] = brick[curr_tetroline][curr_pix];
            }
        }

        print_field(*playground);

        for (int pix = 4; pix < 8; ++pix) {
            (*playground)[curr_line][pix] = prev_values[pix-4];
        }
    
        Sleep(200);
        system("cls");
    }
}

int main(int argc, char* argv[]) {
    tetro i_tetromino = {
        { "   ", "   ", "   ", "   " },
        { "   ", "   ", "   ", "   " },
        { "   ", "   ", "   ", "   " },
        { "[ ]", "[ ]", "[ ]", "[ ]" }
    };
    
    tetro s_tetromino = {
        { "   ", "   ", "   ", "   " },
        { "   ", "   ", "   ", "   " },
        { "   ", "[ ]", "[ ]", "   " },
        { "[ ]", "[ ]", "   ", "   " }
    };

    field playground = {
        {"[ ]", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "[ ]\n"},
        {"[ ]", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "[ ]\n"},
        {"[ ]", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "[ ]\n"},
        {"[ ]", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "[ ]\n"},
        {"[ ]", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "[ ]\n"},
        {"[ ]", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "[ ]\n"},
        {"[ ]", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "[ ]\n"},
        {"[ ]", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "[ ]\n"},
        {"[ ]", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "[ ]\n"},
        {"[ ]", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "[ ]\n"},
        {"[ ]", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "   ", "[ ]\n"},
        {"[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]", "[ ]\n"},
    };

    spawn_brick(&playground, i_tetromino);
    spawn_brick(&playground, s_tetromino);

    std::cout << "Finished!\n";
    Sleep(3000);

    return 0;
}
