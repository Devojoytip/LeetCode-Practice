// Traverse the arr to find the maxLen pos

int maxLen=0;
for (int i = 0; i <= m; i++) {
      for (int j = 0; j <= n; j++) {
          if (i == 0 || j == 0)
              LCSuff[i][j] = 0;

          else if (X[i - 1] == Y[j - 1]) {
              LCSuff[i][j] = LCSuff[i - 1][j - 1] + 1;
              if (maxLen < LCSuff[i][j]) {
                  maxLen = LCSuff[i][j];
                  Endindex=i;
              }
          }
          else
              LCSuff[i][j] = 0;
      }
  }
return X.substr(Endindex-maxLen,maxLen);
// OR 
// return Y.substr(Endindex-maxLen,maxLen); where Endindex = j


// Similarly for 
