/*
 *
 * author: amir kamalian
 * date:   jan 01 2023
 *
 *
 */

#include "../inc/weatherController.h"

/* below method will validate if the city name only contains characters
 * and no symbols or numbers */
bool WeatherController::validateCity(std::string& city) {
    for(char c : city) {
        if(charCheck(c)) {
            continue;
        } else {
            return false;
        }
    }

    return true;
};

/* part of city name validation */
bool WeatherController::charCheck(char c) {
    if(!((c <= 'z' && c >= 'a') || (c <= 'Z' && c >= 'A') || (c == ' '))) {
        return false;
    } else {
        return true;
    }
};

/* below method formats data properly to be sent off to
 * view for display */
void WeatherController::displayFullWeather(const std::string& city, void (*display)()) {

};



