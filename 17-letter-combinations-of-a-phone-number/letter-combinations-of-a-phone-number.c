/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 char *mapping[] = {
    "","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
 };
 char **result;
 int resultSize = 0;
 int resultCapacity = 10000;
 char combination[10];
 void backtrack(char *digits,int index,int length){
    if(index == length){
        combination[index] = '\0';
        result[resultSize] = malloc((length+1)*sizeof(char));
        strcpy(result[resultSize],combination);
        resultSize++;
        return;

    }
    char *letters = mapping[digits[index]-'0'];
    for(int i = 0;letters[i] != '\0' ;i++){
        combination[index] = letters[i];
        backtrack(digits,index+1,length);
    }
 }
char** letterCombinations(char* digits, int* returnSize) {
    resultSize = 0 ;
    *returnSize = 0;
    int length = strlen(digits);
    if(length == 0){
        return NULL;
    }
    result = malloc(resultCapacity*sizeof(char *));
    backtrack(digits,0,length);
    *returnSize = resultSize;
    return result;
}