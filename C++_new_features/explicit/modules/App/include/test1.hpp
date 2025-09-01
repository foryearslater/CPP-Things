#include <iostream>
#include <string>
#include <vector>

class ReportGenerator 
{
public:
    ReportGenerator(const std::string& title) : m_title(title), m_isCache_valid(false) {}

    std::string generate() const 
    {
        if (m_isCache_valid) 
        {
            std::cout << "return report : " << std::endl;
            return m_cached_report;
        }

        std::cout << "create report " << std::endl;
        
        std::string reportContent = "--- " + m_title + " ---\n";
        reportContent += "this is title    \n";
        reportContent += "generate timestamp ";
        

        m_cached_report = reportContent;
        m_isCache_valid = true;

        return m_cached_report;
    }

    void resetCache() 
    {
        m_isCache_valid = false;
        std::cout << "information reset " << std::endl;
    }

private:
    std::string m_title;
   
    mutable std::string m_cached_report;
    mutable bool m_isCache_valid;
};

void test1() 
{
    const ReportGenerator generator("report");

    std::cout << generator.generate() << std::endl;

    std::cout << generator.generate() << std::endl;

    std::cout << std::endl;
    
    ReportGenerator nonConstGenerator("sum");
    nonConstGenerator.generate();
    nonConstGenerator.resetCache(); 
}


#include <mutex>

class ThreadSafeCounter 
{
public:
    int getValue() const
    {
        std::lock_guard<std::mutex> lock(m_mutex);
        return m_value;
    }
private:
    mutable std::mutex m_mutex;
    int m_value = 0; 
};