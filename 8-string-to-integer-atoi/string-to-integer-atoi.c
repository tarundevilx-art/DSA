int myAtoi(char* s) {
    int i=0,sign=1;
    long result = 0;
    while(s[i]==' '){
        i++;
    }
    if(s[i]=='-' || s[i]=='+'){
        if(s[i]=='-'){
            sign = -1;
        }
        i++;
    }
    while(s[i]>='0' && s[i]<='9'){
        result=result*10 + (s[i++]-'0');
        if(result*sign >= INT_MAX){
            return INT_MAX;
        }
        if(result*sign <= INT_MIN){
            return INT_MIN;
        }
    }
    return (int)(result*sign);
}