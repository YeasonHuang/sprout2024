#include <algorithm>
#include <iostream>
#include <vector>
#include <random>
using namespace std;

void generate(int N, int seed) {
  vector<pair<unsigned int, int>> A(N);
  mt19937 rd(seed);

  for (int i = 0; i < N; i++) 
    A[i] = make_pair(rd(), i + 1); // fill with [1, 2, ..., N] with random seed
  sort(A.begin(), A.end());

  for (int i = 0; i < N; i++)
    cout << A[i].second << " \n"[i + 1 == N];
}