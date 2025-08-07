#pragma once
#include "Subject.hpp"
#include <vector>
#include <algorithm>
#include <iostream>

/**
 * @class WeatherData
 * @brief 具体主题：存储天气数据，并在数据改变时通知观察者。
 * @detail 实现了Subject接口，管理观察者的注册、移除和通知
 */
class WeatherData : public Subject
{
public:
    WeatherData();

    ~WeatherData() override;

    void RegisterObserver(Observer *o) override;

    void RemoveObserver(Observer *o) override;

    void NotifyObservers() override;

    void MeasurementsChanged();

    void SetMeasurements(float temperature, float humidity, float pressure);

    float GetTemperature() const;

    float GetHumidity() const;

    float GetPressure() const;

private:
    std::vector<Observer *> m_observers;

    float m_temperature;

    float m_humidity;

    float m_pressure;
};