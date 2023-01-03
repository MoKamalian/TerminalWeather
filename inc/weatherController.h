/*
 * author: amir kamalian
 * date:   dec 19, 2022
 *
 *
 */

#pragma once

#include <iostream>
#include "weatherModel.h"
#include "weatherView.h"

/* controller class that will communicate with the
 * model to display the weather data
 *      - input validation is done here
 *      - note: no symbols are permitted in the city name
 *      - note: can only specify city name, country names
 *              are too vague */
class WeatherController {

private:
    WeatherModel model;
    /* part of city name validation */
    static bool charCheck(char c);

public:
    WeatherController() = default;
    ~WeatherController() = default;

    /* input validator method */
    static bool validateCity(std::string& city);

    /* displays the weather data and the associated ascii art
     * for the particular type of weather */
    static void displayFullWeather(const std::string& city, void (*display)());

};






