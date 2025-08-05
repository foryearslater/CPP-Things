#ifndef LOGGER_H
#define LOGGER_H

#include <string>
#include <fstream> 

/**
* @class Logger
* @brief ����ģʽʵ�֣������ṩһ��ȫ��Ψһ����־��¼��ʵ��.
*
* @detail ����ʵ���˵���ģʽ��ȷ��������Ӧ�ó�������������ֻ��һ��Loggerʵ������.
* @detail ���ṩ��һ��ͳһ�Ľӿ����ڼ�¼�������͵���־��Ϣ������Ϣ�����桢�����.
*/

class Logger 
{
private:
    /**
     * @brief ˽�й��캯������ֹ�ⲿֱ�Ӵ��� Logger ����.
     * @detail ���ǵ���ģʽ�Ĺؼ���ȷ��ֻ��ͨ�� getInstance() ������ȡʵ��.
     */
    Logger();

    /**
     * @brief ˽���������������� Logger �������������.
     * @detail ���� Meyers Singleton (��̬�ֲ�����)�������������ڳ����˳�ʱ�Զ�����.
     */
    ~Logger();

    /**
     * @brief ɾ���������캯������ֹ Logger ���󱻸���.
     * @detail ����ȷ������Ψһ�Ե���Ҫ�ֶ�.
     */
    Logger(const Logger&) = delete;

    /**
     * @brief ɾ����ֵ���������ֹ Logger ���󱻸�ֵ.
     * @detail ����ȷ������Ψһ�Ե���Ҫ�ֶ�.
     */
    Logger& operator=(const Logger&) = delete;

public:
    /**
     * @brief ��ȡ Logger ���Ψһʵ��.
     * @return Logger ������ã���֤��ͬһ��ʵ��.
     */
    static Logger& GetInstance();
    static Logger* GetInstanceLazy();
    /**
     * @brief ��¼һ����־��Ϣ.
     * @detail ����ʽ�������־��Ϣ���������̨.
     * @param message Ҫ��¼���ַ�����Ϣ.
     */
    void Log(const std::string& message);

private:

    static Logger instance_Eager;
    /**
     * @brief ����ʽ 
     */
    static Logger* instance_lazy;

};

/**
* @brief ����ʽ (Eager Initialization)
* @detail ��Դ�ļ��г�ʼ����̬��Ա (���κ��̷߳���֮ǰ)
* @detail �ڳ�������ʱ�������ʱ������������Ψһ��ʵ���������ǵȵ���һ��ʹ��ʱ�Ŵ���
*/

Logger Logger::instance_Eager;


/**
* @brief ����ʽ (Eager Initialization)
* @detail  ֻ���ڵ�һ�ε��� getInstance() ����ʱ�Ŵ���ʵ��
*/

Logger* Logger::instance_lazy = nullptr;
#endif // LOGGER_H