//
// Created by Ruslan on 30.01.2024.
//
#include <ctime>

class Date__ {
    public:
        inline static const unsigned msInSecond = 1000;
        inline static const unsigned secondsInMinute = 60;
        inline static const unsigned msInMinute = msInSecond * secondsInMinute;
        inline static const unsigned minutesInHour = 60;
        inline static const unsigned secondsInHour = secondsInMinute * minutesInHour;
        inline static const unsigned msInHour = msInMinute * minutesInHour;
        // TODO: fill others ...
        inline static const unsigned hoursInDay = 24;
        inline static const unsigned daysInWeek = 7;
        /** approximate */
        inline static const unsigned daysInMonth = 30;
        /** approximate */
        inline static const unsigned weeksInMonth = 4;
        /** approximate */
        inline static const unsigned daysInHalfOfYear = 180;
        inline static const unsigned monthsInYear = 12;
        inline static const unsigned monthsInQuarter = 3;
        inline static const unsigned monthsInHalfOfYear = monthsInQuarter * 2;
        time_t ms;
        static Date__ now()
        {
            return Date__(time(0));
        }
        static std::string toISOString(const Date__ &date) {
            const time_t* t = &date.ms;
            std::string str = String__::to_string(ctime(t));
            str.erase(str.length() - 1);

            return str;
        }
        Date__(const time_t ms)
        {
            this->ms = ms;
        }
        ~Date__()
        {
        }
};
