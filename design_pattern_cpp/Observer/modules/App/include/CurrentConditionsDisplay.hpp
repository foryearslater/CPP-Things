#pragma once
#include "Observer.hpp"
#include "DisplayElement.hpp"
#include "WeatherData.hpp"

/**
 * @class CurrentConditionsDisplay
 * @brief 具体观察者: 显示当前的温度和湿度
 * @detail 注册到WeatherData主题, 并在数据更新时拉取数据并显示
 */
class CurrentConditionsDisplay : public Observer, public DisplayElement
{
public:
    explicit CurrentConditionsDisplay(WeatherData *weatherData);

    ~CurrentConditionsDisplay() override;

    void Update() override;

    void Display() const override;

private:
    float m_temperature;
    float m_humidity;
    WeatherData *m_weatherData;
};