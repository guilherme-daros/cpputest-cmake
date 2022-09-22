class EventLog
{
public:
    EventLog(/* args */);
    ~EventLog();

private:
    EventLog(const EventLog &);            // Hide copy constructor
    EventLog &operator=(const EventLog &); // Hide assignment
};