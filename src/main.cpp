/*
 * author: amir kamalian
 * date:   dec 18, 2022
 *
 *
 */


#include <iostream>
#include "../inc/weatherController.h"
#include "../inc/weatherView.h"
#include "../inc/weatherModel.h"

using namespace std;
using namespace curlpp;
using namespace nlohmann;

int main() {

    /* calling the main controller function that will
     * ask for user input; make the API request; and
     * handle possible input errors */
    WeatherController::retrieveWeatherForCity();

    /* depending on the weather type different ASCII art will be shown
     * the default is to show clouds */
    string inputCity = WeatherController::getWeatherModel().getCity();
    string mainWeatherDescriptor = WeatherController::getWeatherModel().getWeather().getMain();
    if(mainWeatherDescriptor == "Clouds") {
        WeatherController::displayFullWeather(inputCity, WeatherView::displayCloudy);
    } else if(mainWeatherDescriptor == "Clear") {
        WeatherController::displayFullWeather(inputCity, WeatherView::displaySun);
    } else if(mainWeatherDescriptor == "Rain") {
        WeatherController::displayFullWeather(inputCity, WeatherView::displayRain);
    } else if(mainWeatherDescriptor == "Thunderstorm") {
        WeatherController::displayFullWeather(inputCity, WeatherView::displayThunder);
    } else if(mainWeatherDescriptor == "Snow") {
        WeatherController::displayFullWeather(inputCity, WeatherView::displaySnowfall);
    } else {
        /* base case will simply display clouds */
        WeatherController::displayFullWeather(inputCity, WeatherView::displayCloudy);
    }

    return 0;
}



