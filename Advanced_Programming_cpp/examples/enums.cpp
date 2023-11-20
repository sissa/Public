#include <iostream>

enum Days {
    MONDAY,
    TUESDAY,
    WEDNESDAY,
    THURSDAY,
    FRIDAY,
    SATURDAY,
    SUNDAY
 };

enum Animals{
    CAT=3,
    DOG,
    RABBIT,
    HORSE=9,
    BEAR
};
 

int main(){
 
 // Days today = WEDNESDAY;
 Days today=SATURDAY; 
 
  if (today == WEDNESDAY) {
        std::cout << WEDNESDAY << std::endl;
  } else {
        std::cout << SUNDAY+2 << std::endl;
  }

  //works, but if values are not sequential, doesn't give what you expect
  for(int i=CAT;i<=BEAR;i++){
    std::cout<<i<<" ";
  }
  std::cout<<std::endl;
  return 0;
}
