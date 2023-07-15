#include "String.h"

void strcrear(String &s) {
    s = new char [1];
    s[0] = '\0';
}

void LiberarString(String &s) {
    delete[] s;
    s = NULL;
}

int strlar(String s) {
    int i = 0;
    while (s[i] != '\0') i++;
    return i;
}

void strcop(String from, String &to) {
    int i = 0;
    LiberarString(to);
    to = new char [strlar(from) + 1];
    while (from[i] != '\0') {
        to[i] = from[i];
        i++;
    }
    to[i] = '\0';
}

void scan(String &s) {
    fflush(stdin);

    String aux = new char [MAX];

    char c;
    scanf("%c", &c);

    int i = 0;
    while (i < MAX - 1 && c != '\n') {
        aux[i] = c;
        scanf("%c", &c);
        i++;
    }
    aux[i] = '\0';

    strcrear(s);
    strcop(aux, s);
    LiberarString(aux);
}

void print(String s1) {
    int i = 0;
    while (s1[i] != '\0') {
        printf("%c", s1[i]);
        i++;
    }
}

bool streq(String s1, String s2, bool ignoreCase){
    bool iguales = true;
    int i = 0;
    while(s1[i] != '\0' && s2[i] != '\0' && iguales == true){
        if(ignoreCase == false) {
            if (s1[i] != s2[i]) {
                iguales = false;
            }
        } else {
            int c1 = s1[i] >= 65 && s1[i] <= 90 ? s1[i] + 32 : s1[i];
            int c2 = s2[i] >= 65 && s2[i] <= 90 ? s2[i] + 32 : s2[i];
            if (c1 != c2) {
                iguales = false;
            }
        }
        i++;
    }
    if(s1[i]!='\0' || s2[i]!='\0')
                iguales=false;
    return iguales;
}

void Substr(String &input, int from) {
    String aux = new char[strlar(input) + 1];
    int j = 0;
    while (input[from] != '\0') {
        aux[j] = input[from];
        from++;
        j++;
    }
    aux[j] = '\0';

    strcop(aux, input);
    LiberarString(aux);
}

void Trim(String &input) {
    TrimLeft(input);
    TrimRight(input);
}

void TrimLeft(String &input) {
    int largo = strlar(input);
    if (largo == 0 || input[0] != ' ') {
        return;
    }

    int offset = 0;
    while (offset < largo && input[offset] == ' ') {
        offset++;
    }

    if (offset > 0) {
        Substr(input, offset);
    }
}

void TrimRight(String &input) {
    int offset = 0, inputLength = strlar(input), wsFrom = -1;
    while (offset < inputLength) {
        if (input[offset] == ' ') {
            if (wsFrom == -1) {
                wsFrom = offset;
            }
        } else if (wsFrom >= 0) {
            wsFrom = -1;
        }
        offset++;
    }

    if (wsFrom == 0 && input[offset] == ' ') {
        LiberarString(input);
        strcrear(input);
    } else if (wsFrom > 0) {
        offset = 0;
        String aux = new char[wsFrom + 1];
        while (offset < wsFrom) {
            aux[offset] = input[offset];
            offset++;
        }
        aux[offset] = '\0';

        strcop(aux, input);
        LiberarString(aux);
    }
}
