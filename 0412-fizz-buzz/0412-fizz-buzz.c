/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** fizzBuzz(int n, int* returnSize){
    *returnSize=n;
    char** array=(char**)malloc(n*sizeof(char*));
    for(int i=1;i<=n;i++){
        array[i-1]=(char*)malloc(8*sizeof(char));
        if(i%15==0){
            array[i-1]="FizzBuzz";
        }
        else if(i%3==0){
            array[i-1]="Fizz";
        }
        else if(i%5==0){
            array[i-1]="Buzz";
        }
        else{
            sprintf(array[i-1],"%d",i);
        }
    }
    return array;
}