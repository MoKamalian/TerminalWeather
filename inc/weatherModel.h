/*
 * author: amir kamalian
 * date:   dec 18, 2022
 *
 *
 */

#pragma once

#include <iostream>
#include <nlohmann/json.hpp>

// TODO: need to write the Weather struct and how it will be instantiated
// TODO: need to write the actual method that will make the API call

/* main weather model class
 *      - this is where processing of data will occur
 *      - API calls also occur here
 *      - the structs match the JSON response from OpenWeather */
class WeatherModel {

private:
    /* the main weather data model that is returned from OpenWeather */
    struct Weather {
        std::string main; /* main title for the weather */
        std::string description; /* short description of the current weather */
        float temperature;
        float feelsLike;

        explicit Weather(std::string _main, std::string _description, float _temp, float _feelsLike) :
                            main{_main}, description{_description}, temperature{_temp}, feelsLike{_feelsLike} {};
    };

    mutable std::string city;
    mutable std::string country;
    Weather weather;

public:

    explicit WeatherModel();
    ~WeatherModel() = default;

    /* make the api request and fill out the properties of Weather */
    void fetchWeatherData();

    /* getters and setters */
    const Weather& getWeather() { return this->weather; };
    std::string& getCity() const { return this->city; };
    std::string& getCountry() const { return this->country; };




};

