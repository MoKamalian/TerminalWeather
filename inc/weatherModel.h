/*
 * author: amir kamalian
 * date:   dec 18, 2022
 *
 *
 */

#pragma once

#include <iostream>

/* model for the main weather that is returned from the API
 * call to OpenWeather endpoint */
struct Weather {
    std::string main;
    std::string description;


};


/* main weather model class
 *      - this is where processing of data will occur
 *      - API calls also occur here
 *      - the structs match the JSON response from OpenWeather */
class WeatherModel {

private:
    std::string city;
    std::string country;
    float temperature;
    float feelsLike;


public:

    explicit WeatherModel();
    ~WeatherModel() = default;

    /* getters and setters */
    std::string& getCity() { return this->city; };
    std::string& getCountry() { return this->country; };

};

