#include "dataPulling.h"
#include <iostream>
#include "mergeSort.h"
#include <vector>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <string>
// #include <fstream>
using namespace std;

int main() {
    // Just testing out the dataPulling class to make sure it works
    dataPulling example;
    example.readFile();

    // Testing out the Merge Sort
    MergeSort mergeTest;
    vector<int> vec = {1,5,6,3,2,7};
    mergeTest.mergeSort(vec, 0, vec.size()-1);
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
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

        // Goes to next window if goButton pressed
        sf::FloatRect goButtonBounds = goButton.getGlobalBounds();
        sf::Vector2i mouseLocalPosition = sf::Mouse::getPosition(welcomeWindow); // Local position (relative to welcome window)

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
            genreTitle.setPosition({275.f, 100.f});

            // Make genre window home button to go back to welcome window
            sf::RectangleShape homeButton(sf::RectangleShape(sf::Vector2f(175.f, 75.f)));
            homeButton.setFillColor(sf::Color::Green);
            homeButton.setOrigin(sf::Vector2f({50.f, 100.f}));
            homeButton.setPosition({200.f, 450.f});

            // Make genre window exit button (exits out of both genre window and welcome window)
            sf::RectangleShape exitGenreButton(sf::RectangleShape(sf::Vector2f(175.f, 75.f)));
            exitGenreButton.setFillColor(sf::Color::Green);
            exitGenreButton.setOrigin(sf::Vector2f({100.f, 100.f}));
            exitGenreButton.setPosition({600.f, 450.f}); // Position values of x=450.f and y=340.f are middle of screen

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