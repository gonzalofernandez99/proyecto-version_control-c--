#ifndef DATETIME_H_
#define DATETIME_H_

#include <ctime>
#include <iostream>
#include<string>
#include <iomanip>
#include <sstream>

using std::string;

namespace UDateTime{
	  struct DateTime {
        unsigned int year;
        unsigned int month;
        unsigned int day;
        unsigned int hour;
        unsigned int minute;
        unsigned int second;
    };
	enum DateTimeFormat{ YYYYMMDD_HHmmss, YYYYMMDD_hhmmss, DDMMYYYY_hhmmss, DDMMYYYY_HHmmss, YYYYMMDDHHmmss, YYMD_Hms, YYMD_hms, DMYY_hms, DMYY_Hms};

	// Precondicion: Ninguna
	// Postcondicion: Devuelve una instancia valida de DateTime que representa la fecha y hora actual del sistema operativo.
	DateTime* Now(){
        std::time_t now = std::time(0);
        std::tm* ltm = std::localtime(&now);

        DateTime* dateTime = new DateTime;

        dateTime->year = 1900 + ltm->tm_year;
        dateTime->month = 1 + ltm->tm_mon;
        dateTime->day = ltm->tm_mday;
        dateTime->hour = ltm->tm_hour;
        dateTime->minute = ltm->tm_min;
        dateTime->second = ltm->tm_sec;

        return dateTime;
	}

	// Precondicion: Ninguna
	// Postcondicion: Devuelve una instancia valida de DateTime para la fecha y hora especificada. Si @month, @day, @hour, @minute y @seconds, no se corresponden a una fecha y hora posible devuleve NULL
	DateTime* CreateDateTime(unsigned int year = 2019, unsigned int month = 1, unsigned int day = 1, unsigned int hour=0, int minutes=0, int seconds=0){
		
        DateTime* dateTime = new DateTime;
        
        dateTime->year = year;
        dateTime->month = month;
        dateTime->day = day;
        dateTime->hour = hour;
        dateTime->minute = minutes;
        dateTime->second = seconds;

        return dateTime;
	}

	// Precondicion: @dateTime es una instancia valida
	// Postcondicion: Devuelve el valor de @dateTime.
	unsigned int GetYear(const DateTime* dateTime){
		return dateTime->year;
	}

	// Precondicion: @dateTime es una instancia valida
	// Postcondicion: Devuelve el mes de @dateTime, siendo un valor de 1 - 12 donde 1 es Enero y 12 es Diciembre
	unsigned int GetMonth(const DateTime* dateTime){
		return dateTime->month;
	}

	// Precondicion: @dateTime es una instancia valida
	// Postcondicion: Devuelve el dia de @dateTime.
	unsigned int GetDay(const DateTime* dateTime){
		return dateTime->day;
	}

	// Precondicion: @dateTime es una instancia valida
	// Postcondicion: Devuelve la hora de @dateTime, siendo un valor entre 0 - 23
	unsigned int GetHour(const DateTime* dateTime){
		return dateTime->hour;
	}

	// Precondicion: @dateTime es una instancia valida
	// Postcondicion: Devuelve los minutos de @dateTime, siendo un valor de 0 - 59
	unsigned int GetMinutes(const DateTime* dateTime){
		return dateTime->minute;
	}

	// Precondicion: @dateTime es una instancia valida
	// Postcondicion: Devuelve los segundos de @dateTime.
	unsigned int GetSeconds(const DateTime* dateTime){
		return dateTime->second;
	}

	// Precondicion: @dateTime es una instancia valida
	// Postcondicion: Devuelve @dateTime en el formato especificado por @format.
	// Valores esperados por cada formato.
	// Para la fecha y hora 27/4/2019 19:01:10
	// - YYYYMMDD_HHmmss: 2019-04-27 19:01:10
	// - YYYYMMDD_hhmmss: 2019-04-27 07:01:10 p.m.
	// - DDMMYYYY_hhmmss: 27-04-2019 07:01:10 p.m.
	// - DDMMYYYY_HHmmss: 27-04-2019 19:01:10
	// - YYYYMMDDHHmmss: 20190427191410
	// - YYMD_Hms: 19-4-27 19:1:10
	// - YYMD_hms: 19-4-27 7:1:10 p.m.
	// - DMYY_hms: 27-4-19 7:1:10 p.m.
	// - DMYY_Hms: 27-4-19 19:1:10
	string ToFormat(const DateTime* dateTime, DateTimeFormat format){
		string formatted_time;
        switch (format) {
            case YYYYMMDD_HHmmss:
                formatted_time = std::to_string(dateTime->year) + "-" +
                                std::string(dateTime->month < 10 ? "0" : "") + std::to_string(dateTime->month) + "-" +
                                std::string(dateTime->day < 10 ? "0" : "") + std::to_string(dateTime->day) + " " +
                                std::string(dateTime->hour < 10 ? "0" : "") + std::to_string(dateTime->hour) + ":" +
                                std::string(dateTime->minute < 10 ? "0" : "") + std::to_string(dateTime->minute) + ":" +
                                std::string(dateTime->second < 10 ? "0" : "") + std::to_string(dateTime->second);
                break;
            case YYYYMMDD_hhmmss:
                formatted_time = std::to_string(dateTime->year) + "-" +
                                std::string(dateTime->month < 10 ? "0" : "") + std::to_string(dateTime->month) + "-" +
                                std::string(dateTime->day < 10 ? "0" : "") + std::to_string(dateTime->day) + " " +
                                std::string((dateTime->hour % 12) < 10 ? "0" : "") + std::to_string(dateTime->hour % 12) + ":" +
                                std::string(dateTime->minute < 10 ? "0" : "") + std::to_string(dateTime->minute) + ":" +
                                std::string(dateTime->second < 10 ? "0" : "") + std::to_string(dateTime->second) + 
                                (dateTime->hour < 12 ? " a.m." : " p.m.");
                break;
            case DDMMYYYY_hhmmss:
                formatted_time = std::string(dateTime->day < 10 ? "0" : "") + std::to_string(dateTime->day) + " " +
                                std::string(dateTime->month < 10 ? "0" : "") + std::to_string(dateTime->month) + "-" +
								std::to_string(dateTime->year) + "-" +
                                std::string((dateTime->hour % 12) < 10 ? "0" : "") + std::to_string(dateTime->hour % 12) + ":" +
                                std::string(dateTime->minute < 10 ? "0" : "") + std::to_string(dateTime->minute) + ":" +
                                std::string(dateTime->second < 10 ? "0" : "") + std::to_string(dateTime->second) + 
                                (dateTime->hour < 12 ? " a.m." : " p.m.");
                break;
            case DDMMYYYY_HHmmss:
                formatted_time = std::string(dateTime->day < 10 ? "0" : "") + std::to_string(dateTime->day) + " " +
                                std::string(dateTime->month < 10 ? "0" : "") + std::to_string(dateTime->month) + "-" +
								std::to_string(dateTime->year) + "-" +
                                std::string(dateTime->hour < 10 ? "0" : "") + std::to_string(dateTime->hour) + ":" +
                                std::string(dateTime->minute < 10 ? "0" : "") + std::to_string(dateTime->minute) + ":" +
                                std::string(dateTime->second < 10 ? "0" : "") + std::to_string(dateTime->second);
			case YYYYMMDDHHmmss:
                formatted_time = std::to_string(dateTime->year) +
                                std::string(dateTime->month < 10 ? "0" : "") + std::to_string(dateTime->month)+
                                std::string(dateTime->day < 10 ? "0" : "") + std::to_string(dateTime->day)+
                                std::string(dateTime->hour < 10 ? "0" : "") + std::to_string(dateTime->hour)+
                                std::string(dateTime->minute < 10 ? "0" : "") + std::to_string(dateTime->minute)+
                                std::string(dateTime->second < 10 ? "0" : "") + std::to_string(dateTime->second);
                break;
            case YYMD_Hms:
                formatted_time = std::to_string(dateTime->year % 100) + "-" +
                                std::to_string(dateTime->month) + "-" +
                                std::to_string(dateTime->day) + " " +
                                std::to_string(dateTime->hour) + ":" +
                                std::to_string(dateTime->minute) + ":" +
                                std::to_string(dateTime->second);
                break;
            case YYMD_hms:
                formatted_time = std::to_string(dateTime->year % 100) + "-" +
                                std::to_string(dateTime->month) + "-" +
                                std::to_string(dateTime->day) + " " +
                                std::to_string(dateTime->hour % 12) + ":" +
                                std::to_string(dateTime->minute) + ":" +
                                std::to_string(dateTime->second) +
                                (dateTime->hour < 12 ? " a.m." : " p.m.");
                break;
            case DMYY_hms:
                formatted_time = std::to_string(dateTime->day) + " " +
                                std::to_string(dateTime->month) + "-" +
                                std::to_string(dateTime->year % 100) + "-" +
                                std::to_string(dateTime->hour % 12) + ":" +
                                std::to_string(dateTime->minute) + ":" +
                                std::to_string(dateTime->second) +
                                (dateTime->hour < 12 ? " a.m." : " p.m.");
                break;
            case DMYY_Hms:
                formatted_time = std::to_string(dateTime->day) + " " +
                                std::to_string(dateTime->month) + "-" +
                                std::to_string(dateTime->year % 100) + "-" +
                                std::to_string(dateTime->hour) + ":" +
                                std::to_string(dateTime->minute) + ":" +
                                std::to_string(dateTime->second);
                break;
            default:
                return "";
        }
        return formatted_time;

    }

	// Precondicion: @dateTime es una instancia v�lida
	// Postcondicion: Devuelve el a�o de @dateTime.
	void DestroyDateTime(DateTime* dateTime){
		delete dateTime;
	}
}


#endif
