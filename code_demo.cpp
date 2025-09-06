#include "iostream"



int main(){
  // инициализация
  double var_1 = 333;
  int var_2 = 1.11;
  // инициализация в функциональном виде
  int var_4(1.11);// OK
  //int var_5{1.11};// Error. Присутствует валидация
  std::cout << var_2;
  // POINTERS
  int value = 333;
  int* pointer = 0; // Нулевой указатель на int
  pointer = &value; // записан адрес value
  *pointer = 42; // разыменовывание по адресу и запись значения 42
  std::cout << pointer;
  
  int* data;
  data = new int(4);
  std::cout << data << std::endl;
  std::cout << *data;
  int* array;
  array = new int[10];

  // Различие 
}
