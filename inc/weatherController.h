/*
 * author: amir kamalian
 * date:   dec 19, 2022
 *
 *
 */

#pragma once

#include <iostream>
#include <regex>
#include <iomanip>
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
    static inline WeatherModel model = WeatherModel();
    /* part of city name validation */
    static bool charCheck(char c);

public:
    WeatherController() = default;
    ~WeatherController() = default;

    /* input validator method */
    static bool validateCityName(std::string& city);

    /* validates to see if the city exists; makes the
     * api call and if error condition is raised by model; should re-prompt user
     * to enter the city name; when the proper city name has been entered,
     * data is retrieved and model member variable is properly populated */
    static void retrieveWeatherForCity();

    /* displays the weather data and the associated ascii art
     * for the particular type of weather */
    static void displayFullWeather(const std::string& city, void (*display)());

    /* getters */
    static WeatherModel& getWeatherModel() { return model; };

};






