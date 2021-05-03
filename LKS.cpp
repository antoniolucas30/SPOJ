#include <iostream>
#include <utility>

long long Knapsack(std::pair <long long, long long>* vecObj, long long** matrix, long long currentIndex, long long currentCapacity, long long totalLen);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long long lenVec, maxCapacity, **matrix;
  std::pair <long long, long long>* vecObj;

  std::cin >> maxCapacity >> lenVec;

  vecObj = new std::pair <long long, long long>[lenVec];
  matrix = new long long*[lenVec + 1];

  for(long long i = 0; i < lenVec + 1; i++){
        
    matrix[i] = new long long[maxCapacity + 1];

    for(long long j = 0; j < maxCapacity + 1; j++)
      matrix[i][j] = -1;

    if(i != lenVec)
      std::cin >> vecObj[i].second >> vecObj[i].first;

  }

  std::cout << Knapsack(vecObj, matrix, 0, maxCapacity, lenVec) << std::endl;

  return 0;
}

long long Knapsack(std::pair <long long, long long>* vecObj, long long** matrix, long long currentIndex, long long currentCapacity, long long totalLen){

  long long tmpPut, tmpDontPut;

  if(matrix[currentIndex][currentCapacity] != -1)
    return matrix[currentIndex][currentCapacity];

  if(currentIndex == totalLen || currentCapacity == 0)
    return matrix[currentIndex][currentCapacity] = 0;

  tmpDontPut = Knapsack(vecObj, matrix, currentIndex + 1, currentCapacity, totalLen);

  if(vecObj[currentIndex].first <= currentCapacity){

    tmpPut = vecObj[currentIndex].second + Knapsack(vecObj, matrix, currentIndex + 1, currentCapacity - vecObj[currentIndex].first, totalLen);

    return matrix[currentIndex][currentCapacity] = std::max(tmpDontPut, tmpPut);

  }

  return matrix[currentIndex][currentCapacity] = tmpDontPut;

}
