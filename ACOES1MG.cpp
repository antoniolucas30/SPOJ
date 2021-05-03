#include <iostream>

void funcRecur(long maxMoney, long currentMoney, long* result);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long initial;
  long maxMoney;
  long result;

  while(std::cin >> initial >> maxMoney && initial != 0 && maxMoney != 0){

    result = 0;

    funcRecur(maxMoney, initial, &result);

    std::cout << result << '\n';

  }

  return 0;
}

void funcRecur(long maxMoney, long currentMoney, long* result){

  if(currentMoney > maxMoney){

    if((currentMoney % 2) == 0){

      funcRecur(maxMoney, currentMoney / 2, result);
      funcRecur(maxMoney, currentMoney / 2, result);

    }

    else{

      funcRecur(maxMoney, (currentMoney / 2), result);
      funcRecur(maxMoney, (currentMoney / 2) + 1, result);

    }
  
  }

  else
    (*result)++;

}
