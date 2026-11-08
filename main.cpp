#include "dataPulling.h"
#include "minHeap.h"
#include "mergeSort.h"
#include <iostream>
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
// #include <fstream>
using namespace std;

int main() {
    string genre; // Gets input from the user on the welcome window; determines which genre for genre window

    // Just testing out the dataPulling class to make sure it works
    dataPulling example;
    const vector<Song> songs = example.readFile();
    cout <<"Loaded" << songs.size() << " songs" << endl;
    if (!songs.empty()) {
        const Song& first = songs.front();
        cout << first.title << ", " << first.artist << "..." << first.popularityScore << "-" << first.genre << endl;
    }

    // Testing out the Merge Sort
    // MergeSort mergeTest;
    // vector<int> vec = {1,5,6,3,2,7};
    // cout << "Merge Sort should be outputted: " << endl;
    // mergeTest.mergeSort(vec, 0, int(vec.size()-1));
    // for (int i = 0; i < vec.size(); i++) {
    //     cout << vec[i] << " ";
    // }

    //sample scores just to test minHeap
    vector<int> scores = {46, 90, 73, 82, 99, 46};
    int k = 3;
    vector<int> rankedSongs = topKByPopularity(scores, k);
    cout<< "Top" << k << "songs:" << endl;
    for (int rank = 0; rank < static_cast<int>(rankedSongs.size()); rank++) {
        int index = rankedSongs[rank];
        cout << rank + 1 << "Song index: " << index << "\nPopularity: " << scores[index] << endl;
    }

    // Creating the welcome window
    // Reference: Used SFML documentation online to do user interface (https://www.sfml-dev.org/tutorials/3.1/)
    sf::RenderWindow welcomeWindow(sf::VideoMode({800, 680}), "Test Window");

    // Reference: Font is from Google Fonts (https://fonts.google.com/)
    sf::Font font("RobotoMono-VariableFont_wght.ttf");

    // Title text at top of welcome screen
    sf::Text titleText(font);
    titleText.setFillColor(sf::Color::White);
    titleText.setCharacterSize(24);
    titleText.setStyle(sf::Text::Bold);
    titleText.setString("EE Music Rankings");
    titleText.setPosition({275.f, 0.f});

    // Question text on welcome screen
    sf::Text questionText(font);
    questionText.setFillColor(sf::Color::White);
    questionText.setCharacterSize(24);
    questionText.setStyle(sf::Text::Regular);
    questionText.setString("What Genre Are You Listening To?");
    questionText.setOrigin(sf::Vector2f({24.f, 24.f})); // This line might not actually do anything
    questionText.setPosition({210.f, 100.f});

    // Exit button on welcome screen
    sf::RectangleShape exitButton(sf::RectangleShape(sf::Vector2f(175.f, 75.f)));
    exitButton.setFillColor(sf::Color::Green);
    exitButton.setOrigin(sf::Vector2f({100.f, 100.f}));
    exitButton.setPosition({200.f, 450.f}); // Position values of x=450.f and y=340.f are middle of screen

    // Go button on welcome screen (takes you to the next screen)
    sf::RectangleShape goButton(sf::RectangleShape(sf::Vector2f(175.f, 75.f)));
    goButton.setFillColor(sf::Color::Green);
    goButton.setOrigin(sf::Vector2f({50.f, 100.f}));
    goButton.setPosition({600.f, 450.f});

    // Exit text on welcome screen (on top of exit button)
    sf::Text exitText(font);
    exitText.setFillColor(sf::Color::White);
    exitText.setCharacterSize(24);
    exitText.setStyle(sf::Text::Regular);
    exitText.setString("Exit");
    exitText.setOrigin(sf::Vector2f({24.f, 24.f})); // This line might not actually do anything
    exitText.setPosition({182.f, 395.f});

    // Go text on welcome screen (on top of go button)
    sf::Text goText(font);
    goText.setFillColor(sf::Color::White);
    goText.setCharacterSize(24);
    goText.setStyle(sf::Text::Regular);
    goText.setString("Go");
    goText.setOrigin(sf::Vector2f({24.f, 24.f})); // This line might not actually do anything
    goText.setPosition({650.f, 395.f});




    while (welcomeWindow.isOpen()) { // Welcome window is open

        while (const std::optional event = welcomeWindow.pollEvent()) { // Checks events
            if (event->is<sf::Event::Closed>()) { // Closes window if close button pressed
                welcomeWindow.close();
            }
        }

        welcomeWindow.clear(sf::Color::Black); // Need

        welcomeWindow.draw(titleText);
        welcomeWindow.draw(questionText);
        welcomeWindow.draw(goButton);
        welcomeWindow.draw(exitButton);
        welcomeWindow.draw(exitText);
        welcomeWindow.draw(goText);

        // Exits welcome window if exitButton pressed
        sf::FloatRect exitButtonBounds = exitButton.getGlobalBounds();
        sf::Vector2i mouseLocalPosition = sf::Mouse::getPosition(welcomeWindow); // Local position (relative to welcome window)
        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && exitButtonBounds.contains({float(mouseLocalPosition.x), float(mouseLocalPosition.y)})) {
            cout << "Button pressed in exitButton bounds" << endl;
            welcomeWindow.setVisible(false);
            welcomeWindow.close();
        }

        // Goes to next window if goButton pressed
        sf::FloatRect goButtonBounds = goButton.getGlobalBounds();
        // sf::Vector2i mouseLocalPosition = sf::Mouse::getPosition(welcomeWindow); // Local position (relative to welcome window)

        if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && goButtonBounds.contains({float(mouseLocalPosition.x), float(mouseLocalPosition.y)})) {
            cout << "Button pressed in goButton bounds" << endl;
            // Draw genre window here (new window)
            sf::RenderWindow genreWindow(sf::VideoMode({800, 680}), "Genre Window");

            // Make genre title text
            sf::Text genreTitle(font);
            genreTitle.setFillColor(sf::Color::White);
            genreTitle.setCharacterSize(24);
            genreTitle.setStyle(sf::Text::Regular);
            genreTitle.setString("Genre Ranked");
            genreTitle.setOrigin(sf::Vector2f({24.f, 24.f})); // This line might not actually do anything
            genreTitle.setPosition({345.f, 100.f});

            // Make genre window home button to go back to welcome window
            sf::RectangleShape homeButton(sf::RectangleShape(sf::Vector2f(175.f, 75.f)));
            homeButton.setFillColor(sf::Color::Green);
            homeButton.setOrigin(sf::Vector2f({50.f, 100.f}));
            homeButton.setPosition({100.f, 650.f});

            // Make genre window exit button (exits out of both genre window and welcome window)
            sf::RectangleShape exitGenreButton(sf::RectangleShape(sf::Vector2f(175.f, 75.f)));
            exitGenreButton.setFillColor(sf::Color::Green);
            exitGenreButton.setOrigin(sf::Vector2f({100.f, 100.f}));
            exitGenreButton.setPosition({680.f, 650.f}); // Position values of x=450.f and y=340.f are middle of screen

            // Make "Home" text for genre window's return to home button
            sf::Text genreHome(font);
            genreHome.setFillColor(sf::Color::White);
            genreHome.setCharacterSize(24);
            genreHome.setStyle(sf::Text::Regular);
            genreHome.setString("Home");
            genreHome.setOrigin(sf::Vector2f({24.f, 24.f})); // This line might not actually do anything
            genreHome.setPosition({132.f, 595.f});

            // Make "Exit" text for genre window's exit button
            sf::Text genreExit(font);
            genreExit.setFillColor(sf::Color::White);
            genreExit.setCharacterSize(24);
            genreExit.setStyle(sf::Text::Regular);
            genreExit.setString("Exit");
            genreExit.setOrigin(sf::Vector2f({24.f, 24.f})); // This line might not actually do anything
            genreExit.setPosition({667.f, 595.f});

            // From now until start of while loop, we are making the box of the ranked songs in the genre
            sf::RectangleShape rankingBox(sf::RectangleShape(sf::Vector2f(600.f, 345.f)));
            rankingBox.setFillColor(sf::Color::Green);
            rankingBox.setOrigin(sf::Vector2f({300.f, 300.f}));
            rankingBox.setPosition({408.f, 460.f}); // Position values of x=450.f and y=340.f are middle of screen

            // Make "Song Title" text for genre window's ranking box
            sf::Text songTitle(font);
            songTitle.setFillColor(sf::Color::White);
            songTitle.setCharacterSize(24);
            songTitle.setStyle(sf::Text::Regular);
            songTitle.setString("Song Title");
            songTitle.setOrigin(sf::Vector2f({24.f, 24.f})); // This line might not actually do anything
            songTitle.setPosition({150.f, 200.f});

            // Make "Score" text for genre window's ranking box
            sf::Text score(font);
            score.setFillColor(sf::Color::White);
            score.setCharacterSize(24);
            score.setStyle(sf::Text::Regular);
            score.setString("Score");
            score.setOrigin(sf::Vector2f({24.f, 24.f})); // This line might not actually do anything
            score.setPosition({430.f, 200.f});

            // Make "Rank" text for genre window's ranking box
            sf::Text rank(font);
            rank.setFillColor(sf::Color::White);
            rank.setCharacterSize(24);
            rank.setStyle(sf::Text::Regular);
            rank.setString("Rank");
            rank.setOrigin(sf::Vector2f({24.f, 24.f})); // This line might not actually do anything
            rank.setPosition({650.f, 200.f});

            // Make the lines in genre window's ranking box for list to sit on
            // Might do a for loop so don't have to do 6 different times
            sf::RectangleShape line0({550.f, 2.f});
            line0.setFillColor(sf::Color::Black);
            line0.setPosition({130.f, 220.f});

            sf::RectangleShape line1({550.f, 2.f});
            line1.setFillColor(sf::Color::Black);
            line1.setPosition({130.f, 270.f});

            sf::RectangleShape line2({550.f, 2.f});
            line2.setFillColor(sf::Color::Black);
            line2.setPosition({130.f, 320.f});

            sf::RectangleShape line3({550.f, 2.f});
            line3.setFillColor(sf::Color::Black);
            line3.setPosition({130.f, 370.f});

            sf::RectangleShape line4({550.f, 2.f});
            line4.setFillColor(sf::Color::Black);
            line4.setPosition({130.f, 420.f});

            sf::RectangleShape line5({550.f, 2.f});
            line5.setFillColor(sf::Color::Black);
            line5.setPosition({130.f, 470.f});

            while (genreWindow.isOpen()) {
                welcomeWindow.setVisible(false);

                while (const std::optional event = genreWindow.pollEvent()) { // Checks events
                    if (event->is<sf::Event::Closed>()) { // Closes window if close button pressed
                        genreWindow.close();
                        welcomeWindow.close();
                    }
                }

                genreWindow.clear(sf::Color::Black); // Need

                genreWindow.draw(genreTitle);
                genreWindow.draw(homeButton);
                genreWindow.draw(exitGenreButton);
                genreWindow.draw(genreExit);
                genreWindow.draw(genreHome);
                genreWindow.draw(rankingBox);
                genreWindow.draw(songTitle);
                genreWindow.draw(score);
                genreWindow.draw(rank);
                genreWindow.draw(line0);
                genreWindow.draw(line1);
                genreWindow.draw(line2);
                genreWindow.draw(line3);
                genreWindow.draw(line4);
                genreWindow.draw(line5);

                sf::FloatRect homeButtonBounds = homeButton.getGlobalBounds();
                sf::FloatRect exitGenreButtonBounds = exitGenreButton.getGlobalBounds();
                sf::Vector2i mouseLocalPositionGenre = sf::Mouse::getPosition(genreWindow); // Local position (relative to welcome window)


                if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && homeButtonBounds.contains({float(mouseLocalPositionGenre.x), float(mouseLocalPositionGenre.y)})) {
                    cout << "Button pressed in exitButton bounds" << endl;
                    genreWindow.setVisible(false);
                    genreWindow.close();
                    welcomeWindow.setVisible(true);
                }

                // Maybe make a flag for genreWindow and welcomeWindow for exit button
                // Exit button on genre screen SHOULD close out of both welcome window AND genre windows
                // Does not close out right now
                // if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Left) && exitGenreButtonBounds.contains({float(mouseLocalPositionGenre.x), float(mouseLocalPositionGenre.y)})) {
                //     cout << "Button pressed in exitButton bounds" << endl;
                //     genreWindow.setVisible(false);
                //     genreWindow.close();
                //     welcomeWindow.setVisible(false);
                //     welcomeWindow.close();
                // }

                genreWindow.display(); // Need
            }

        }

        welcomeWindow.display(); // Need
    }

    return 0;
}