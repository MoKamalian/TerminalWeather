/*
 * author: amir kamalian
 * date:   dec 18, 2022
 *
 *
 */


#include <iostream>
#include <nlohmann/json.hpp>
#include "../lib/curlpp/cURLpp.hpp"
#include "../lib/curlpp/Easy.hpp"
#include "../lib/curlpp/Options.hpp"
#include "../inc/weatherController.h"
#include "../inc/weatherView.h"
#include "../inc/weatherModel.h"

using namespace std;
using namespace curlpp;
using namespace nlohmann;

int main() {

    ostringstream os;
    json response;

    try {
        Cleanup myCleanup;
        Easy myRequest;

        Options::WriteStream ws(&os);
        myRequest.setOpt<options::Url>("https://api.openweathermap.org/data/2.5/weather?q=Halifax&appid=73c88b0be993f33a9f963a3c88c1c3ee");
        myRequest.setOpt(ws);
        myRequest.perform();

        response = json::parse(os.str());
        cout << response["main"] << endl;

    } catch(RuntimeError& re) {
        cout << re.what() << endl;
    } catch(LogicError& le) {
        cout << le.what() << endl;
    }

    WeatherView::displaySnowStorm();
    return 0;
}


// TODO: create the UI ASCII art that will be displayed depending on the weather status
// TODO: create the model class that will actually perform the API calls
    // TODO: methods needed to process the data received from the API call
    // TODO: methods also need to actually make those API calls
