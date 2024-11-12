# include<iostream>
void concatene(char *dest, const char *source){
    int i =0;
    while (source[i] != '\0' )
    {
        i++;
        dest += source[i];
    }
    
}

int main ( int argv, char**argc){
char desti[50] = "mene";
const char *sour = "bon";
concatene(desti, sour);
std:: cout << "la conactenation entre desti et sourc est:" << concatene;
return 0;
}
