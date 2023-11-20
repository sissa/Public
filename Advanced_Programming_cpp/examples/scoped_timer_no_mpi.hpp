#pragma once

#include<iostream>
#include<unordered_map>
#include<chrono>
#include<string>
#include<thread>
#include<cmath>

/**
*  USE THIS AS
*  {CSimple_timer t("WHATEVER YOU ARE TIMING");
*        THE CODE YOU ARE TIMING
*    }
* 
*  THEN AT THE END OF MAIN PUT
*  CSimple_timer::print_timing_results();   
*/
//use an alias so that you could change to seconds or microseconds easier
using time_units=std::chrono::milliseconds;

//group your number of calls and timing results to one variable, so you could have 1 map
struct TimerData{
    int n_calls;
    time_units time_taken;
    TimerData(const int& n_calls0,const time_units& val):n_calls(n_calls0),time_taken(val){}
    TimerData(){};
};


//this needs to be either global or static to be accessible by all instances of the timer
//since we can just keep everything timer-related in this file, no harm in making it global
//I'm not actually sure if unordered map or map is better
std::unordered_map<std::string, TimerData>  table;


class CSimple_timer{
public:
  std::string timewhat;
  std::chrono::time_point<std::chrono::steady_clock> start, stop;

  CSimple_timer( const std::string & timewhat0){
    //can't pass it to destructor, so you need it as a variable
    timewhat=timewhat0;
    start = std::chrono::steady_clock::now();

    //if it's the first occurrence of "what we are timing"
    //then we need to insert
    if (table.find(timewhat) != table.end() ){
      table[timewhat].n_calls++;
    }else{
      table.insert(std::make_pair(timewhat,TimerData(1,time_units(0))));
    }
    start = std::chrono::steady_clock::now();
    };

    //in the destructor it can't be the first occurrence, so we don't have to check 
    ~CSimple_timer(){
        stop  = std::chrono::steady_clock::now();
        auto duration = std::chrono::duration_cast<time_units>(stop-start);
        table[timewhat].time_taken+=duration;
      
    }//destructor
   //this thing is made "static" so that the user needs to call it with the name of the class
   //rather than calling a global function that comes from who knows where
   static void print_timing_results();

};

void CSimple_timer::print_timing_results(){
        for (const auto & pair : table){
            std::cout<< pair.first << ": "<<pair.second.n_calls<<std::endl;
            std::cout<< "time taken: "<<pair.second.time_taken.count()<<std::endl;
        };
};//print

