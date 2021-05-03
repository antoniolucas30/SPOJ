#include <iostream>

long LCS(std::string S1, std::string S2, long lenS1, long lenS2, long** DP);

int main(){

  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  std::string s1, s2;
  long lenS1, lenS2, **DP;

  std::cin >> s1 >> s2;

  lenS1 = s1.size(), lenS2 = s2.size();

  DP = new long*[lenS1];

  for(long i = 0; i < lenS1; i++){
  
    DP[i] = new long[lenS2];

    for(long j = 0; j < lenS2; j++)
      DP[i][j] = -1;

  }

  std::cout << LCS(s1, s2, lenS1 - 1, lenS2 - 1, DP) << std::endl;

  return 0;
}

long LCS(std::string S1, std::string S2, long lenS1, long lenS2, long** DP){

  int result, tmp1, tmp2;

  if(lenS1 < 0 || lenS2 < 0)
    return 0;

  if(DP[lenS1][lenS2] != -1)
    return DP[lenS1][lenS2];

  if(S1[lenS1] == S2[lenS2]){
    
    result = 1 + LCS(S1, S2, lenS1 - 1, lenS2 - 1, DP);

  }

  else{

    tmp1 = LCS(S1, S2, lenS1 - 1, lenS2, DP);
    tmp2 = LCS(S1, S2, lenS1, lenS2 - 1, DP);

    result = std::max(tmp1, tmp2);

  }

  DP[lenS1][lenS2] = result;

  return result;

}
