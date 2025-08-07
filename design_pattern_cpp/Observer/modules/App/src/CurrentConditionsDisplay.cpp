#include "CurrentConditionsDisplay.hpp"
#include <iomanip>

CurrentConditionsDisplay::CurrentConditionsDisplay(WeatherData *weatherData)
    : m_weatherData(weatherData), m_temperature(0.0f), m_humidity(0.0f)
{
    if (m_weatherData)
    {
        m_weatherData->RegisterObserver(this);
    }
    std::cout << "CurrentConditionsDisplay created and registered." << std::endl;
}

CurrentConditionsDisplay::~CurrentConditionsDisplay()
{
    if (m_weatherData)
    {
        m_weatherData->RemoveObserver(this);
    }
    std::cout << "CurrentConditionsDisplay destroyed." << std::endl;
}

void CurrentConditionsDisplay::Update()
{
    if (m_weatherData)
    {
        m_temperature = m_weatherData->GetTemperature();
        m_humidity = m_weatherData->GetHumidity();
        Display();
    }
}

void CurrentConditionsDisplay::Display() const
{
    std::cout << "Current conditions: "
              << std::fixed << std::setprecision(1) << m_temperature << "F degrees and "
              << std::fixed << std::setprecision(1) << m_humidity << "% humidity" << std::endl;
}