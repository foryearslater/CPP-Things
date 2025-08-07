#include "StatisticsDisplay.hpp"
#include <numeric>
#include <limits>
#include <algorithm>
#include <iomanip>

StatisticsDisplay::StatisticsDisplay(WeatherData* weatherData)
	: m_weatherData(weatherData)
{
	if (m_weatherData)
	{
		m_weatherData->RegisterObserver(this);
	}
	std::cout << "StatisticsDisplay created and registered." << std::endl;
}

StatisticsDisplay::~StatisticsDisplay()
{
	if (m_weatherData)
	{
		m_weatherData->RemoveObserver(this);
	}
	std::cout << "StatisticsDisplay destroyed." << std::endl;
}

void StatisticsDisplay::Update()
{
	if (m_weatherData)
	{
		m_tempHistory.push_back(m_weatherData->GetTemperature());
		Display();
	}
}

void StatisticsDisplay::Display() const
{
	if (m_tempHistory.empty())
	{
		std::cout << "Statistics: No data yet." << std::endl;
		return;
	}

	float sum = std::accumulate(m_tempHistory.begin(), m_tempHistory.end(), 0.0f);
	float avg = sum / m_tempHistory.size();

	float minTemp = std::numeric_limits<float>::max();
	float maxTemp = std::numeric_limits<float>::min();

	if (!m_tempHistory.empty())
	{
		minTemp = *std::min_element(m_tempHistory.begin(), m_tempHistory.end());
		maxTemp = *std::max_element(m_tempHistory.begin(), m_tempHistory.end());
	}

	std::cout << "Avg/Max/Min temperature: "
		<< std::fixed << std::setprecision(1) << avg << "F/"
		<< std::fixed << std::setprecision(1) << maxTemp << "F/"
		<< std::fixed << std::setprecision(1) << minTemp << "F" << std::endl;
}