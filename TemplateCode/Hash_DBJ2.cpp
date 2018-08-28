#define T_SIZE 2000
unsigned long long int hash(unsigned char *str)
    {
        unsigned long long int hash = 5381;
        int c;

        while (c = *str++)
            hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

        return hash%T_SIZE;
    }
