#include "CppUTest/TestHarness.h"
#include "EventLog.h"

TEST(EventLog, EventLogCreate)
{
    EventLog *log = new EventLog();
    LONGS_EQUAL(0, log->GetCount());
    delete log;
}