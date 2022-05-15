void getNext(char * p, int * next)
{
	next[0] = -1;
	int i = 0, j = -1;

	while (i < strlen(p) - 1)
	{
		if (j == -1 || p[i] == p[j])
		{
			++i;
			++j;
			next[i] = j;
		}	
		else
			j = next[j];
	}
}

int strStr(char * haystack, char * needle){
    if (strlen(needle) == 0) return 0;
    int * next = (int*)malloc(sizeof(int) * strlen(needle));
    getNext(needle, next);
    int i = 0;
	int j = 0;

	while (i < strlen(haystack) && j < (int)strlen(needle))
	{
		if (j == -1 || haystack[i] == needle[j]) 
		{
			i++;
           	j++;
		}
	 	else 
           	j = next[j];
    }

    if (j == strlen(needle))
        return i - j;
    else 
        return -1;
}