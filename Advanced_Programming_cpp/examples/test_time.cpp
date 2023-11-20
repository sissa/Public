#include <thread>
#include "scoped_timer_no_mpi.hpp"
#include <iostream>

void sleep1(){
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
}

void sleep2(){
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
}


int main(){
    
    {CSimple_timer t("sleep1");
        sleep1();
    }
    {CSimple_timer t("sleep2");
        sleep2();
    }
    {CSimple_timer t("sleep1");
        sleep1();
    }
    {CSimple_timer t("sleep2");
        sleep2();
    }

    CSimple_timer::print_timing_results();  

    return 0;
}
