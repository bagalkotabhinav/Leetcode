int roman(char * s){
    if(s[0]=='I'){
        if(s[1]=='V'||s[1]=='X')
            return -1;
        return 1;
    }
    if(s[0]=='X'){
        if(s[1]=='C'||s[1]=='L')
            return -10;
        return 10;
    }
    if(s[0]=='C'){
        if(s[1]=='D'||s[1]=='M')
            return -100;
        return 100;
    }
    if(s[0]=='V')
        return 5;
    if(s[0]=='L')
        return 50;
    if(s[0]=='D')
        return 500;
    if(s[0]=='M')
        return 1000;
    return 0;
}

int romanToInt(char * s){
    int num=0;
    while(*s!='\0'){
        num=num+roman(s);
        s++;
    }
    return num;
}