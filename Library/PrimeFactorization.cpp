
/*素因数分解*/
template<typename T>
map<T, T> prime_factorization(T m) {

	map<T, T> tmp;
	for (T i = 2; i * i <= m; i++) {
		while (m % i == 0) {
			tmp[i]++;
			m /= i;
		}
	}
	if (m != 1) {
		tmp[m] = 1;
	}
	return tmp;
}