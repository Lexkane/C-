#define n 3

bool checkMarkov(double m[][n])
{
	
	for (int i = 0; i < n; i++) {

		// Знаходження суми на поточному рядку
		double sum = 0;
		for (int j = 0; j < n; j++)
			sum = sum + m[i][j];

		if (sum != 1)
			return false;
	}

	return true;
}