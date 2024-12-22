int diagonalSum(vector<vector<int>> &mat)
{
    int sizes = mat.size();
    int sum = mat[0][0];
    for (auto i : mat)
    {
        for (auto j : i)
        {
            if (count == sizes - 2)
            {
                sum = sum + j;
                count == 0;
            }
            else
            {
                count++;
            }
        }
    }

    return sum;
}

int main()
{
    vector<int, vector<int>(3)> arr
    {
        {1, 2, 3}, {3, 4, 5};
    }
    cout < "Added Number" << endl;
    return 0;
}