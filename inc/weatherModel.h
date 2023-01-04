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
 * replace with your specific key */                                                        /* PUT YOUR KEY HERE */
#define MY_URL(string) (("https://api.openweathermap.org/data/2.5/weather?q=") + (string) + ("&appid={YOUR_API_KEY"))
#define KELVIN_CONST 273.15
/* main weather model class
 *      - this is where processing of data will occur
 *      - API calls are made here
 *      - the Weather struct will contain the information received from OpenWeather */
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
        std::string getMain() const { return this->main; };
        std::string getDescription() const { return this->description; };
        float getPressure() const { return this->pressure; };
        float getHumidity() const { return this->humidity; };
        float getTemp() const { return tempConvert(this->temperature); };
        float getFeelsLike() const { return tempConvert(this->feelsLike); };

        /* temperature converter to Celsius */
        static float tempConvert(float t) {
            return (float) (t - KELVIN_CONST);
        };

    };

    /* default values will be null for the city and country names;
     * these member variables are set when fetchWeatherData is called */
    mutable std::string city = "null";
    mutable std::string country = "null";
    Weather weather;

public:
    WeatherModel() = default;
    WeatherModel(const WeatherModel&) = delete;
    ~WeatherModel() = default;

    /* make the api request and fill out the properties of Weather
     * returns true if the data retrieval and parsing was successful; false
     * if error conditions are raised */
    bool fetchWeatherData(std::string& _city);

    /* getters and setters */
    const Weather& getWeather() { return this->weather; };
    std::string& getCity() const { return this->city; };
    std::string& getCountry() const { return this->country; };

};



