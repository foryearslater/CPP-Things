#include "WeatherData.hpp"
#include "Observer.hpp"

WeatherData::WeatherData() : m_temperature(0.0f), m_humidity(0.0f), m_pressure(0.0f)
{
    std::cout << "WeatherData subject created." << std::endl;
}

WeatherData::~WeatherData()
{
    std::cout << "WeatherData subject destroyed." << std::endl;
}

void WeatherData::RegisterObserver(Observer *o)
{
    m_observers.push_back(o);
    std::cout << "Observer registered." << std::endl;
}

void WeatherData::RemoveObserver(Observer *o)
{

    m_observers.erase(std::remove(m_observers.begin(), m_observers.end(), o), m_observers.end());
    std::cout << "Observer removed." << std::endl;
}

void WeatherData::NotifyObservers()
{
    std::cout << "\nNotifying observers..." << std::endl;

    for (Observer *observer : m_observers)
    {
        if (observer)
        {
            observer->Update();
        }
    }
    std::cout << "Observers notified." << std::endl;
}

void WeatherData::MeasurementsChanged()
{
    NotifyObservers();
}

void WeatherData::SetMeasurements(float temperature, float humidity, float pressure)
{
    m_temperature = temperature;
    m_humidity = humidity;
    m_pressure = pressure;
    MeasurementsChanged();
}

float WeatherData::GetTemperature() const
{
    return m_temperature;
}

float WeatherData::GetHumidity() const
{
    return m_humidity;
}

float WeatherData::GetPressure() const
{
    return m_pressure;
}