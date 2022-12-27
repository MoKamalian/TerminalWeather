/*
 * author: amir kamalian
 * date:   dec 19, 2022
 * description: below class will display different ascii art
 *              based on the weather data returned from API call.
 *
 * art reference(s): https://www.asciiart.eu/
 *                   https://ascii.co.uk/
 *
 */

#pragma once

#include <iostream>

/* The below class is used to display the ASCII art corresponding to
 * the type of weather.  This class is meant for UI/ASCII art display
 * purposes only and no data validation and/or processing occurs here */
class WeatherView {

public:
    /* methods for displaying UI ASCII art of depending on the weather */
    static void displaySun();
    static void displayRain();
    static void displayCloudy();
    static void displayThunder();
    static void displaySnowfall();
    static void displaySnowStorm();

};