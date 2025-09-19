bool isPrime(const int primeCandidate)
{
    for (int i = primeCandidate-1; i > 1; i--)
    {
        // if dividing by i  gives no remainder, it isn't prime.
        if (primeCandidate % i == 0)
        {
            return false;
        }
    }
    return true;
}