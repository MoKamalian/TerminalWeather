/*
 * author: amir kamalian
 * date:   dec 18, 2022
 *
 *
 */

#pragma once

#include <iostream>
#include <nlohmann/json.hpp>
#include "../lib/curlpp/cURLpp.hpp"
#include "../lib/curlpp/Easy.hpp"
#include "../lib/curlpp/Options.hpp"

/* this is the API key that will be used to make the requests;
 * replace with your specific key */
#define MY_API_KEY "{YOUR_API}"
// TODO: below url is for testing only since city is hardcoded; should change so it is not hardcoded
#define MY_URL "https://api.openweathermap.org/data/2.5/weather?q=London&appid="

/* main weather model class
 *      - this is where processing of data will occur
 *      - API calls also occur here
 *      - the structs match the JSON response from OpenWeather */
class WeatherModel {

private:
    /* the main weather data model that is returned from OpenWeather */
    struct Weather {
    private:
        std::string main; /* main title for the weather */
        std::string description; /* short description of the current weather */
        float pressure;
        float humidity;
        /* note: temperatures are received in Kelvin */
        float temperature;
        float feelsLike;

    public:
        Weather() = default;
        Weather(const Weather&) = delete;
        explicit Weather(std::string _main, std::string _description, float _pres, float _hum, float _temp, float _feelsLike) :
                            main{_main}, description{_description}, temperature{_temp}, feelsLike{_feelsLike},
                            pressure{_pres}, humidity{_hum} {};

        /* getters */
        std::string getMain() { return this->main; };
        std::string getDescription() { return this->description; };
        float getPressure() { return this->pressure; };
        float getHumidity() { return this->humidity; };
        float getTemp() { return this->temperature; };
        float getFeelsLike() { return this->feelsLike; };

    };

    mutable std::string city;
    mutable std::string country;
    Weather weather;

public:
    WeatherModel() = default;
    WeatherModel(const WeatherModel&) = delete;
    ~WeatherModel() = default;

    /* make the api request and fill out the properties of Weather */
    void fetchWeatherData();

    /* getters and setters */
    const Weather& getWeather() { return this->weather; };
    std::string& getCity() const { return this->city; };
    std::string& getCountry() const { return this->country; };


};

