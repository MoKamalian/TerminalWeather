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

    WeatherController::retrieveWeatherForCity();


    return 0;
}

// TODO:: write implementation for main function
// TODO:: write implementation for displayFullWeather in controller class 


