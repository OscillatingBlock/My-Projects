int strStr(char* haystack, char* needle) {
    int m = strlen(haystack);
    int n = strlen(needle);   
    int k;
    if (n == 0 || n > m) 
    {
      return -1;
    }
    for (int i = 0; i < m; i++)
    {
        if (needle[0] == haystack[i])
        {
             int j = 0;
          while (needle[j] != '\0' && haystack[i + j] == needle[j]) 
             {
                j++;
             }
             if (needle[j] == '\0') 
             { 
                return i;
             }
        }
    }
    return -1;
}
