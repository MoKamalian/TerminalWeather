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
    /* model testing
    WeatherModel model;
    model.fetchWeatherData();
    cout << model.getWeather().getMain() << endl;
    cout << model.getWeather().getDescription() << endl;
    cout << model.getWeather().getFeelsLike() << endl;
    cout << model.getWeather().getTemp() << endl;
    cout << model.getWeather().getHumidity() << endl;
    cout << model.getWeather().getPressure() << endl;


    cout << model.getCity() << endl;
    cout << model.getCountry() << endl;*/

    /* controller testing */
    string Boston = "Boston";
    string badCity = "02983";
    cout << WeatherController::validateCity(Boston) << endl;
    cout << WeatherController::validateCity(badCity) << endl;


    return 0;
}



// TODO: create the model class that will actually perform the API calls
    // TODO: should change the URL so the city name is not hard coded
    // TODO: controller need to validate input does not contain symbols, only letters
    // TODO: will need to create implementation to display the weather data
    // TODO: have the weather model accept the city name to make the API call

