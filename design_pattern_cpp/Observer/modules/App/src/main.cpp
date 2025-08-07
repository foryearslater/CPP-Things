#include <iostream>
#include <memory>

#include "WeatherData.hpp"
#include "CurrentConditionsDisplay.hpp"
#include "StatisticsDisplay.hpp"

int main()
{

    std::unique_ptr<WeatherData> weatherData = std::make_unique<WeatherData>();

    std::unique_ptr<CurrentConditionsDisplay> currentDisplay =
        std::make_unique<CurrentConditionsDisplay>(weatherData.get());

    std::unique_ptr<StatisticsDisplay> statisticsDisplay =
        std::make_unique<StatisticsDisplay>(weatherData.get());

    std::cout << "\n--- First measurement update ---" << std::endl;
    weatherData->SetMeasurements(80, 65, 30.4f);

    std::cout << "\n--- Second measurement update ---" << std::endl;
    weatherData->SetMeasurements(82, 70, 29.2f);

    std::cout << "\n--- Third measurement update (after removing one observer) ---" << std::endl;
    currentDisplay.reset();

    weatherData->SetMeasurements(78, 90, 29.2f);

    std::cout << "\nProgram finished." << std::endl;

    return 0;
}