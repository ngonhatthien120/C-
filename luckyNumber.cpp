int luckyNumber(std::vector<std::vector<int>> arr)
{
    int i, j,k=0;
	int result = -1;
	for (i = 0; i < arr.size(); i++)
	{
		int min = arr[i][0];
		for (j = 0; j < arr[i].size(); j++)
		{
			if (arr[i][j] < min) {
				min = arr[i][j];
				k = j;
			}
		}

		for (int t = 0; t < arr.size(); t++) {
			if (arr[t][k] > min)
				break;
			if (t == arr.size() - 1) {
				result = min;
				break;
			}
		}
    }
	return result;
}
