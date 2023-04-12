#include <iostream>
#include <vector>

void print_vector(const std::vector<int> &v) {
  std::cout << " [ ";
  for (const auto &elem : v) {
    std::cout << elem << " ";
  }
  std::cout << "]" << std::endl;
}

void print_matrix(const std::vector<std::vector<int>> &A) {
  std::cout << "[" << std::endl;
  for (const auto &row : A) {
    for (const auto &elem : row) {
      std::cout << elem << " ";
    }
    std::cout << std::endl;
  }
  std::cout << "]" << std::endl;
}

int main() {

  // Get the vector elements from the user
  std::vector<int> v{};
  std::cout << "Give elements to the vector v\n";
  int x;
  while (std::cin >> x) {
    v.push_back(x);
  }
  std::cin.clear();
  std::cin.ignore();

  // Print the vector v
  std::cout << "Vector v is:\n";
  print_vector(v);

  // Get a square matrix A
  const auto N = v.size();
  std::cout << "Give the " << N * N << " elements of matrix A (row-first)\n";
  std::vector<std::vector<int>> A(N); // We define just the lines for now
  for (auto i = 0; i < N; ++i) {
    for (auto j = 0; j < N; ++j) {
      int y;
      std::cin >> y;
      A[i].push_back(y);
    }
  }

  // Print the matrix A
  std::cout << "Matrix A is:" << std::endl;
  print_matrix(A);

  // Multiply A * v and store it to a vector m
  std::vector<int> m(N, 0);
  for (auto i = 0; i < N; ++i) {
    for (auto j = 0; j < N; ++j) {
      m[i] += A[i][j] * v[j];
    }
  }

  // Print the vector m
  std::cout << "Vector m = A * v is:" << std::endl;
  print_vector(m);

  return 0;
}
