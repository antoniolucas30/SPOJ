#include <iostream>
#include <utility>

long long Knapsack(std::pair <int, int>* vecThings, long long** matrix, int currentIndex, int currentCapacity, int totalLen);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long long** matrix;
  int totalCapacity, totalLen;
  std::pair <int, int>* vecThings;

  std::cin >> totalCapacity >> totalLen;

  vecThings = new std::pair <int, int>[totalLen];
  matrix = new long long*[totalLen + 1];

  for(int i = 0; i < totalLen + 1; i++){

    matrix[i] = new long long[totalCapacity + 1];

    for(int j = 0; j < totalCapacity + 1; j++)
      matrix[i][j] = -1;

    if(i != totalLen)
      std::cin >> vecThings[i].first >> vecThings[i].second;

  }

  std::cout << Knapsack(vecThings, matrix, 0, totalCapacity, totalLen) << std::endl;

  return 0;
}

long long Knapsack(std::pair <int, int>* vecThings, long long** matrix, int currentIndex, int currentCapacity, int totalLen){

  long long temporaryPut, temporaryDontPut;

  if(matrix[currentIndex][currentCapacity] != -1)
    return matrix[currentIndex][currentCapacity];

  if(currentIndex == totalLen || currentCapacity == 0)
    return matrix[currentIndex][currentCapacity] = 0;

  temporaryDontPut = Knapsack(vecThings, matrix, currentIndex + 1, currentCapacity, totalLen);

  if(vecThings[currentIndex].first <= currentCapacity){

    temporaryPut = vecThings[currentIndex].second + Knapsack(vecThings, matrix, currentIndex + 1, currentCapacity - vecThings[currentIndex].first, totalLen);

    return matrix[currentIndex][currentCapacity] = std::max(temporaryDontPut, temporaryPut);

  }

  return matrix[currentIndex][currentCapacity] = temporaryDontPut;

}
