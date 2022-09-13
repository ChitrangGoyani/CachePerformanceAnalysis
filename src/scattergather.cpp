#include <iostream>
using namespace std;
void parsec_roi_begin() 
{

}
void parsec_roi_end() 
{

}

void scatterOperation(int rows,int cols,int dataset[][3], int scatterindices[][3])
{
  int datavalues[] = {32,49,57,99,22};
  int datavalueindex = 0;
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      if(scatterindices[i][j] == 1)
      { dataset[i][j] = datavalues[datavalueindex];
        datavalueindex++;
      }
    }
  }
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++)
      {
    cout << dataset[i][j] << " ";
      }
    cout << endl;
    }
  cout << endl;
}

void gatherOperation(int rows,int cols,int dataset[][3], int gatherindices[][3]){
  int result[5] = {};
  int resultiterator = 0;
  for(int i = 0; i < rows; i++){
    for(int j = 0; j < cols; j++){
      if(gatherindices[i][j] == 1)
      { result[resultiterator] = dataset[i][j];
        resultiterator++;  
      }
    }
  }
  for(int i = 0; i < 5; i++){
    cout << result[i] << " ";
  }
  
}
int main() {
  int dataset[5][3] = {{29, 14, 9},
                       {36, 31, 41},
                       {35, 3, 47},
                       {39, 24, 10},
                       {15, 16, 22}};
  int scatterindices[5][3] = {{0, 1, 1},
                       {0, 0, 0},
                       {0, 1, 0},
                       {1, 1, 0},
                       {0, 0, 0}};
  int gatherindices[5][3] = {{1, 0, 1},
                       {0, 1, 0},
                       {0, 0, 0},
                       {0, 1, 0},
                       {1, 0, 0}};
  int rows = sizeof(dataset)/sizeof(dataset[0]);
  int cols = sizeof(dataset[0])/sizeof(int);
  parsec_roi_begin();
  scatterOperation(rows,cols,dataset,scatterindices);
//   gatherOperation(rows,cols,dataset,gatherindices);
  parsec_roi_end();
  return 0;
}
