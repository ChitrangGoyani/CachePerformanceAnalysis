#include <iostream>
#include <vector>
using namespace std;
void parsec_roi_begin() 
{

}
void parsec_roi_end() 
{

}

void printMatrix(int dst[4][4]){
  for(int row = 0; row < 4; row++){
    for(int col = 0; col < 4; col++){
      cout << dst[row][col] << " ";
    }
    cout << endl;
  }
}

int main() {
  int n = 4;
  int src[4][4] = { {4,5,9,0},
                    {2,1,3,3},
                    {2,2,9,4},
                    {7,5,9,4}};
   int dst[4][4] = {};
  parsec_roi_begin();
  // transpose loop
  for(int row = 0; row < 4; row++){
    for(int col = 0; col < 4; col++){
      dst[row][col] = src[col][row];
    }
  }
  parsec_roi_end();
  printMatrix(dst);
  return 0;
}