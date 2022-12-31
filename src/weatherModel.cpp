/*
 * author: amir kamalian
 * date:   27 dec 2022
 */

#include "../inc/weatherModel.h"


/* main method call that will retrieve the weather data from OpenWeather */
void WeatherModel::fetchWeatherData() {
    /* make the API call: here, replace {API} with the API key from OpenWeather */
    using namespace std;
    using namespace curlpp;
    using namespace nlohmann;

    ostringstream os;
    json response;

    try {
        Cleanup myCleanup;
        Easy myRequest;
        /* os is the object the data response will be sent to */
        Options::WriteStream ws(&os);
        myRequest.setOpt<options::Url>(MY_URL MY_API_KEY);
        myRequest.setOpt(ws);
        myRequest.perform();
        /* actual parsing of the json response; the data is extracted via
         * os.str() method call and passed to json::parse() to perform the parsing action */
        response = json::parse(os.str());

        /* Here, the actual weather object is initialized with the relevant weather data */
        this->weather = Weather(response["weather"]["main"], response["weather"]["description"], response["main"]["pressure"],
                      response["main"]["humidity"], response["main"]["temp"], response["main"]["feels_like"]);


    } catch(RuntimeError& re) {
        std::cout << re.what() << std::endl;
    } catch(LogicError& le) {
        std::cout << le.what() << std::endl;
    }

};

