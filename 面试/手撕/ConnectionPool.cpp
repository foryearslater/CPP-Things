#include <bits/stdc++.h>

class ConnectionPool
{
private:
    std::string connection_string;
    size_t max_size;
    std::queue<pqxx::connection *> pool;
    std::mutex mtx;
    std::condition_variable cv;

    pqxx::connection *createNewConnection()
    {
        pqxx::connection *conn = new pqxx::connection(connection_string);
        if (conn->is_open())
        {
            return conn;
        }
        return nullptr;
    }

public:
    ConnectionPool(const std::string &dbname, const std::string &user, const std::string &password,
                   const std::string &host = "127.0.0.1", int port = 5432, size_t maxSize = 8)
        : max_size(maxSize)
    {

        std::stringstream ss;
        ss << "dbname=" << dbname << " user=" << user << " password=" << password
           << " hostaddr=" << host << " port=" << port;
        connection_string = ss.str();

        for (size_t i = 0; i < max_size / 2; ++i)
        {
            pqxx::connection *conn = createNewConnection();
            if (conn)
            {
                pool.push(conn);
            }
        }
    }

    ~ConnectionPool()
    {
        std::unique_lock<std::mutex> lock(mtx);
        while (!pool.empty())
        {
            pqxx::connection *conn = pool.front();
            pool.pop();
            delete conn;
        }
    }

    pqxx::connection *getConnection()
    {
        std::unique_lock<std::mutex> lock(mtx);

        cv.wait(lock, [this]
                { return !pool.empty(); });

        pqxx::connection *conn = pool.front();
        pool.pop();

        if (!conn->is_open())
        {
            delete conn;
            conn = createNewConnection();
        }

        return conn;
    }

    void releaseConnection(pqxx::connection *conn)
    {
        if (conn)
        {
            std::unique_lock<std::mutex> lock(mtx);
            if (pool.size() < max_size)
            {
                pool.push(conn);
            }
            else
            {
                delete conn;
            }
            cv.notify_one();
        }
    }
};