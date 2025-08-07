#pragma once
#include "Observer.hpp"
#include "DisplayElement.hpp"
#include "WeatherData.hpp"
#include <vector>

/**
 * @class StatisticsDisplay
 * @brief 具体观察者：显示温度的平均值、最大值和最小值
 * @detail 注册到WeatherData主题，并在数据更新时拉取数据并更新统计信息
 */
class StatisticsDisplay : public Observer, public DisplayElement
{
public:
    explicit StatisticsDisplay(WeatherData *weatherData);

    ~StatisticsDisplay() override;

    void Update() override;

    void Display() const override;

private:

    std::vector<float> m_tempHistory;

    WeatherData *m_weatherData;

};