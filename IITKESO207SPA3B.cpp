#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>

long long Knapsack(std::pair <int, int>* vecObjects, long long**matrix, int currentIndex, int currentCapacity, int totalLen);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  long long** matrix;
  int lenVec, capacity;
  std::pair <int, int>* vecObjects;
  std::vector <int> ans;

  std::cin >> lenVec;

  vecObjects = new std::pair <int, int>[lenVec];
  matrix = new long long*[lenVec + 1];

  for(int i = 0; i < lenVec; i++)
    std::cin >> vecObjects[i].first >> vecObjects[i].second;

  std::cin >> capacity;

  for(int i = 0; i < lenVec + 1; i++){

    matrix[i] = new long long[capacity + 1];

    for(int j = 0; j < capacity + 1; j++)
      matrix[i][j] = -1;

  }

  Knapsack(vecObjects, matrix, 0, capacity, lenVec);

  for(int i = 0, currentWeight = capacity; i <= lenVec - 1; i++){

    if(matrix[i][currentWeight] > matrix[i + 1][currentWeight]){

      ans.push_back(vecObjects[i].first);
      currentWeight -= vecObjects[i].first;

    }

  }

  std::sort(ans.begin(), ans.end());

  capacity = ans.size();

  for(int i = 0; i < capacity; i++){
    
    if(i != 0)
      std::cout << ' ';

    std::cout << ans[i];

  }

  std::cout << std::endl;

  return 0;
}

long long Knapsack(std::pair <int, int>* vecObjects, long long**matrix, int currentIndex, int currentCapacity, int totalLen){

  int tmpPut, tmpDontPut;

  if(matrix[currentIndex][currentCapacity] != -1)
    return matrix[currentIndex][currentCapacity];

  if(currentIndex == totalLen || currentCapacity == 0)
    return matrix[currentIndex][currentCapacity] = 0;

  tmpDontPut = Knapsack(vecObjects, matrix, currentIndex + 1, currentCapacity, totalLen);

  if(vecObjects[currentIndex].first <= currentCapacity){

    tmpPut = vecObjects[currentIndex].second + Knapsack(vecObjects, matrix, currentIndex + 1, currentCapacity - vecObjects[currentIndex].first, totalLen);

    return matrix[currentIndex][currentCapacity] = std::max(tmpPut, tmpDontPut);

  }

  return matrix[currentIndex][currentCapacity] = tmpDontPut;

}
