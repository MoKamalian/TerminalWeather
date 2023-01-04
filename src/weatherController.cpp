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
bool WeatherController::validateCityName(std::string& city) {
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

/* retrieves the weather for the specified city; will reprompt
 * user to re-enter city if error condition is raised (i.e. city
 * does not exist) */
void WeatherController::retrieveWeatherForCity() {

    bool validRetrieval = false;
    while(!validRetrieval) {
        /* first check if the city name has no numbers/special characters */
        std::string city = WeatherView::displayPrompts();
        /* fetch the actual data and if the result is null (meaning
         * city does not exist), re-prompt for entering the city again */
        city = std::regex_replace(city, std::regex(" "), "%20");
        if(WeatherController::model.fetchWeatherData(city)) {
            validRetrieval = true;
        } else {
            std::cout << "The city you have entered does not exist; please try again.. " << std::endl;
        }
    }

};

/* below method formats data properly to be sent off to
 * view for display */
void WeatherController::displayFullWeather(const std::string& city, void (*display)()) {
    display();
    std::string finalString = "\nCity: " + city + "\tCountry: " + model.getCountry() +
                              "\nDescription: " + model.getWeather().getDescription() +
                              "\nTemperature (in Celsius): " + std::to_string((int) model.getWeather().getTemp()) +
                              "\tFeels like (in Celsius): " + std::to_string((int) model.getWeather().getFeelsLike()) +
                              "\nPressure: " + std::to_string((int) model.getWeather().getPressure()) +
                              "\tHumidity: " + std::to_string((int) model.getWeather().getHumidity());

    std::cout << std::fixed  << std::setprecision(0);
    std::cout << "\n-----------------------------" << finalString << "\n-----------------------------" << std::endl;

};



