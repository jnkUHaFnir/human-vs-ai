    #include <stdio.h>
    int main(void)
    {
        char string[] = "+6.590472E-01;+2.771043E+07;+\n";
        char s1[2], s2[2], s3[2];
        char int1[21], int2[21], frac1[21], frac2[21], exp1[6], exp2[6];
        int n;
        int rc;
        if ((rc = sscanf(string, "%[-+]%20[0-9].%20[0-9]%*[eE]%5[-+0-9];%[-+]%20[0-9].%20[0-9]%*[eE]%5[-+0-9];%[-+]%n",
                    s1, int1, frac1, exp1, s2, int2, frac2, exp2, s3, &n)) == 9)
        {
            printf("[%s][%s].[%s]E[%s]\n", s1, int1, frac1, exp1);
            printf("[%s][%s].[%s]E[%s]\n", s2, int2, frac2, exp2);
            printf("[%s] %d (%d = '%c')\n", s3, n, string[n], string[n]);
        }
        else
            printf("Oops (rc = %d)!\n", rc);
        return 0;
    }