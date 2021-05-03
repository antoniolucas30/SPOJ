#include <iostream>

long long mergeSort(long* vec, long indexLeft, long indexRight);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int testCases;
  long totalLen, *vec;

  std::cin >> testCases;

  for(int i = 0; i < testCases; i++){

    std::cin >> totalLen;

    vec = new long[totalLen];

    for(long j = 0; j < totalLen; j++)
      std::cin >> vec[j];

    std::cout << mergeSort(vec, 0, totalLen - 1) << std::endl;

    delete[] vec;

  }

  return 0;
}

long long mergeFcn(long* vec, long indexLeft, long indexMiddle, long indexRight){

  long* temporaryArray = new long[indexRight - indexLeft + 1], changeLeft = indexLeft, changeRight = indexMiddle + 1, indexChange = 0;
  long long countInversions = 0;

  while((changeLeft <= indexMiddle) && (changeRight <= indexRight)){

    if(vec[changeLeft] <= vec[changeRight])
      temporaryArray[indexChange++] = vec[changeLeft++];

    else{

      temporaryArray[indexChange++] = vec[changeRight++];

      countInversions += (indexMiddle - changeLeft) + 1;

    }

  }

  while(changeLeft <= indexMiddle)
    temporaryArray[indexChange++] = vec[changeLeft++];

  while(changeRight <= indexRight)
    temporaryArray[indexChange++] = vec[changeRight++];

  for(long i = 0, j = indexLeft; j <= indexRight; i++, j++)
    vec[j] = temporaryArray[i];

  delete[] temporaryArray;

  return countInversions;

}

long long mergeSort(long* vec, long indexLeft, long indexRight){

  int middle;
  long long countInversions = 0;

  if(indexLeft < indexRight){

    middle = (indexLeft + indexRight) / 2;

    countInversions += mergeSort(vec, indexLeft, middle);
    countInversions += mergeSort(vec, middle + 1, indexRight);

    countInversions += mergeFcn(vec, indexLeft, middle, indexRight);

  }

  return countInversions;

}
