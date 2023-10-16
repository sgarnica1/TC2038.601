
#include <vector>
#include <limits>

void floyd(std::vector<std::vector<int>> &matrix)
{
    int n = matrix.size();
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
            if (matrix[i][k] != -1)
                for (int j = 0; j < n; ++j)
                    if (matrix[k][j] != -1)
                        if (matrix[i][j] == -1 || matrix[i][j] > matrix[i][k] + matrix[k][j])
                            matrix[i][j] = matrix[i][k] + matrix[k][j];
    }
}