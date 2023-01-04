/*
 * author: amir kamalian
 * date:   27 dec 2022
 */

#include "../inc/weatherModel.h"


/* main method call that will retrieve the weather data from OpenWeather */
bool WeatherModel::fetchWeatherData(std::string& _city) {
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
        myRequest.setOpt<options::Url>(MY_URL(_city));
        // std::cout << MY_URL(_city) << std::endl; --> uncomment for testing to see what final URL result looks like
        myRequest.setOpt(ws);
        myRequest.perform();
        /* actual parsing of the json response; the data is extracted via
         * os.str() method call and passed to json::parse() to perform the parsing action */
        response = json::parse(os.str());

        /* Here, the actual weather object is initialized with the relevant weather data */
        this->weather = Weather(response["weather"][0]["main"], response["weather"][0]["description"], response["main"]["pressure"],
                      response["main"]["humidity"], response["main"]["temp"], response["main"]["feels_like"]);

        /* setting city and country */
        this->city = response["name"];
        this->country = response["sys"]["country"];

        return true;

    } catch(RuntimeError& re) {
        //std::cout << re.what() << std::endl;
        return false;
    } catch(LogicError& le) {
        //std::cout << le.what() << std::endl;
        return false;
    } catch(json_abi_v3_11_2::detail::type_error& te) {
        /* error called when OpenWeather returns city not found error
         * i.e. response values become null */
        //std::cout << te.what() << std::endl;
        return false;
    }

};

