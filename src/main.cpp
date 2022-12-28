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

    WeatherModel model;
    model.fetchWeatherData();

    return 0;
}



// TODO: create the model class that will actually perform the API calls
    // TODO: methods needed to process the data received from the API call
    // TODO: methods also need to actually make those API calls
    // TODO: the actual weather object will be instantiated inside the fetch method call