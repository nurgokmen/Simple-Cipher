#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<ctype.h>

#define TABLE_SIZE 26
#define BUFFERSIZE 1024

char table[][26] = {

        {'M','B','C','D','F','E','G','H','K','J','I','S','Z','N','O','P','Q','R','L','T','U','X','W','V','Y','A',},
        {'B','C','D','F','E','G','H','K','J','I','S','Z','N','O','P','Q','R','L','T','U','X','W','V','Y','A','M',},
        {'C','D','F','E','G','H','K','J','I','S','Z','N','O','P','Q','R','L','T','U','X','W','V','Y','A','M','B',},
        {'D','F','E','G','H','K','J','I','S','Z','N','O','P','Q','R','L','T','U','X','W','V','Y','A','M','B','C',},
        {'F','E','G','H','K','J','I','S','Z','N','O','P','Q','R','L','T','U','X','W','V','Y','A','M','B','C','D',},
        {'E','G','H','K','J','I','S','Z','N','O','P','Q','R','L','T','U','X','W','V','Y','A','M','B','C','D','F',},
        {'G','H','K','J','I','S','Z','N','O','P','Q','R','L','T','U','X','W','V','Y','A','M','B','C','D','F','E',},
        {'H','K','J','I','S','Z','N','O','P','Q','R','L','T','U','X','W','V','Y','A','M','B','C','D','F','E','G',},
        {'K','J','I','S','Z','N','O','P','Q','R','L','T','U','X','W','V','Y','A','M','B','C','D','F','E','G','H',},
        {'J','I','S','Z','N','O','P','Q','R','L','T','U','X','W','V','Y','A','M','B','C','D','F','E','G','H','K',},
        {'I','S','Z','N','O','P','Q','R','L','T','U','X','W','V','Y','A','M','B','C','D','F','E','G','H','K','J',},
        {'S','Z','N','O','P','Q','R','L','T','U','X','W','V','Y','A','M','B','C','D','F','E','G','H','K','J','I',},
        {'Z','N','O','P','Q','R','L','T','U','X','W','V','Y','A','M','B','C','D','F','E','G','H','K','J','I','S',},
        {'N','O','P','Q','R','L','T','U','X','W','V','Y','A','M','B','C','D','F','E','G','H','K','J','I','S','Z',},
        {'O','P','Q','R','L','T','U','X','W','V','Y','A','M','B','C','D','F','E','G','H','K','J','I','S','Z','N',},
        {'P','Q','R','L','T','U','X','W','V','Y','A','M','B','C','D','F','E','G','H','K','J','I','S','Z','N','O',},
        {'Q','R','L','T','U','X','W','V','Y','A','M','B','C','D','F','E','G','H','K','J','I','S','Z','N','O','P',},
        {'R','L','T','U','X','W','V','Y','A','M','B','C','D','F','E','G','H','K','J','I','S','Z','N','O','P','Q',},
        {'L','T','U','X','W','V','Y','A','M','B','C','D','F','E','G','H','K','J','I','S','Z','N','O','P','Q','R',},
        {'T','U','X','W','V','Y','A','M','B','C','D','F','E','G','H','K','J','I','S','Z','N','O','P','Q','R','L',},
        {'U','X','W','V','Y','A','M','B','C','D','F','E','G','H','K','J','I','S','Z','N','O','P','Q','R','L','T',},
        {'X','W','V','Y','A','M','B','C','D','F','E','G','H','K','J','I','S','Z','N','O','P','Q','R','L','T','U',},
        {'W','V','Y','A','M','B','C','D','F','E','G','H','K','J','I','S','Z','N','O','P','Q','R','L','T','U','X',},
        {'V','Y','A','M','B','C','D','F','E','G','H','K','J','I','S','Z','N','O','P','Q','R','L','T','U','X','W',},
        {'Y','A','M','B','C','D','F','E','G','H','K','J','I','S','Z','N','O','P','Q','R','L','T','U','X','W','V',},
        {'A','M','B','C','D','F','E','G','H','K','J','I','S','Z','N','O','P','Q','R','L','T','U','X','W','V','Y',},

};



int menu();
const char* encryption(const char table[TABLE_SIZE][TABLE_SIZE]);
const char* decryption(const char table[TABLE_SIZE][TABLE_SIZE]);
//char* decryption(const char* ciphertext, const char* key);
const char* dec_phase2(const char* cipher,const char* key, const char table[TABLE_SIZE][TABLE_SIZE]);
char* dec_phase1(const char* cipher);
void table_load(char table[TABLE_SIZE][TABLE_SIZE], const char* filename);
int find_index(char c,  char tableRow[][TABLE_SIZE]);
void print_table(const char table[TABLE_SIZE][TABLE_SIZE]);
int find_index_in_first_row(char keyC,char textC, const char table[TABLE_SIZE][TABLE_SIZE]);
int enc_phase1(char c, char k, const char table[TABLE_SIZE][TABLE_SIZE]);
char* second_phase_enc(const char* input);


int main() {


    int opt;


    char *cipher_text, *cipher2, *decryptedtxt,*ciphertext;
    do{
        opt = menu();
       if(opt ==1){
            cipher_text = encryption(table);
            printf("Output (phase -1): %s", cipher_text);
            //cipher2 = second_phase_enc(cipher_text);
            printf("\n");
            printf("Encryption Phase -2\n");
            printf("Input text: %s",cipher_text);

            cipher2 = second_phase_enc(cipher_text);
            printf("Ciphertext: %s\n\n\n\n ", cipher2);
            //free(cipher_text);
            //free(cipher2);
            //free(ciphertext);
            }
       else if(opt == 2){

            decryptedtxt = decryption(table);
            printf("\n\n%s", decryptedtxt);
            free(decryptedtxt);
             }
       else if(opt == 3){
            printf("Goodbye");
            }


    } while(opt !=3);

    return 0;
}

int menu(){

    int selection;

    printf("\n\nSimple Cipher:\n");
    printf("[1] Encrypt\n");
    printf("[2] Decrypt\n");
    printf("[3] Exit\n");
    printf("\n");
    printf("Selection:");

    scanf("%d",&selection);

    int c;
    while ((c = getchar()) != '\n' && c != EOF) {}//instead of using fflush

    if (selection == 1){
        return 1;

    }
    else if(selection == 2){
        return 2;
    }
    else if(selection == 3){
        return 3;
    }


}

const char* encryption(const char table[TABLE_SIZE][TABLE_SIZE]) {

    char text[BUFFERSIZE];
    char key[BUFFERSIZE];
    char newKey[BUFFERSIZE];
    int i, j;


    printf("Enter the text: ");
    fgets(text, BUFFERSIZE, stdin);
    text[strcspn(text, "\n")] = 0;


    printf("Enter the key: ");
    fgets(key, BUFFERSIZE, stdin);
    key[strcspn(key, "\n")] = 0;

    for (i = 0, j = 0; text[i] != '\0'; ++i) {
        if (text[i] != ' ') {
            text[j++] = toupper((unsigned char) text[i]);
        }
    }
    text[j] = '\0';


    for (i = 0; key[i] != '\0'; ++i) {
        key[i] = toupper((unsigned char) key[i]);
    }



    int textLength = strlen(text);
    int keyLength = strlen(key);
    for (i = 0; i < textLength; ++i) {
        newKey[i] = key[i % keyLength];
    }
    newKey[textLength] = '\0';

    printf("**********Encryption**********\n");

    printf("Encryption Phase -1\n");
    printf("Plaintext: %s", text);
    printf("\n");
    printf("Key: %s", newKey);
    printf("\n");

    char *enc_text = malloc(strlen(text) + 1);
    if (!enc_text) {
        fprintf(stderr, "Failed to allocate memory for encrypted text.\n");
        return NULL;
    }

    int k;
    char cipher[strlen(text)];
    char temp[strlen(text)][strlen(text)];
    char temp1[strlen(text)];
    char temp2[strlen(text)];


    for (int i = 0; i < strlen(text); i++) {


        int cipherC = enc_phase1(newKey[i], text[i], table);
        temp1[i] = cipherC;
    }
    enc_text = temp1;

    enc_text[strlen(text)] = '\0';

    return enc_text;

}
int enc_phase1(char keyC,char textC, const char table[TABLE_SIZE][TABLE_SIZE]){

    keyC = toupper(keyC);
    textC = toupper(textC);


    int keyCIndex = (int)keyC - 'A';
    int textCIndex = (int)textC - 'A';


    char cipherChar = table[keyCIndex][textCIndex];
    return cipherChar;

}



char* second_phase_enc(const char* cipher){

    int length = strlen(cipher);
    int padding = length % 2;
    char* text = (char*)malloc(length + 1);

    char group1[(length / 2) + padding + 1];
    char group2[(length / 2) + 1];

    strncpy(group1, cipher, (length / 2) + padding);
    group1[(length / 2) + padding] = '\0';


    strncpy(group2, cipher + ((length / 2) + padding), (length / 2));
    group2[(length / 2)] = '\0';

    printf("\nGroup -1: %s\n", group1);
    printf("Group -2: %s \n", group2);

    int j = 0;

    for (int i = 0; i < strlen(group1) || i < strlen(group2); i++) {
        if (i < strlen(group1)) {
            text[j++] = group1[i];
        }
        if (i < strlen(group2)) {
            text[j++] = group2[i];
        }
    }

    text[j] = '\0';

    return text;

}
char* dec_phase1(const char* cipher) {
    int length = strlen(cipher);
    int half_length = (length + 1) / 2;

    char* group1 = (char*)malloc(half_length + 1);
    char* group2 = (char*)malloc(length - half_length + 1);

    for (int i = 0, j = 0, k = 0; i < length; ++i) {
        if (i % 2 == 0) {
            group1[j++] = cipher[i];
        } else {
            group2[k++] = cipher[i];
        }
    }
    group1[half_length] = '\0';
    group2[length - half_length] = '\0';


    char* decryptedText = (char*)malloc(length + 1);

    for (int i = 0, j = 0, k = 0; i < length; ++i) {
        if (i < half_length) {
            decryptedText[i] = group1[j++];
        } else {
            decryptedText[i] = group2[k++];
        }
    }
    decryptedText[length] = '\0';

    free(group1);
    free(group2);

    return decryptedText;
    }



const char* dec_phase2(const char* cipher, const char* key, const char table[TABLE_SIZE][TABLE_SIZE]) {

    int length = strlen(cipher);
    char* plaintext = (char*)malloc(length + 1);

    if (!plaintext) {
        fprintf(stderr, "Memory allocation failed.\n");
        return NULL;
    }

    for (int i = 0; i < length; ++i) {

        int keyAlphabeticalIndex = (int)((key[i % strlen(key)]) - 'A');

        char cipherChar = toupper(cipher[i]);


        int plaintextIndex = -1;
        for (int col = 0; col < TABLE_SIZE; ++col) {
            if (table[keyAlphabeticalIndex][col] == cipherChar) {

                for (int firstRowCol = 0; firstRowCol < TABLE_SIZE; ++firstRowCol) {
                    if (table[keyAlphabeticalIndex][firstRowCol] == cipherChar) {
                        plaintextIndex = firstRowCol;
                        break;
                    }
                }
                break;
            }
        }


        if (plaintextIndex == -1) {
            free(plaintext);
            fprintf(stderr, "Cipher character '%c' not found in the first row for key character '%c'.\n",
                    cipherChar, key[i % strlen(key)]);
            return NULL;
        }

        plaintext[i] = 'A' + plaintextIndex;
    }

    plaintext[length] = '\0'; //
    return plaintext;
}

const char* decryption(const char table[TABLE_SIZE][TABLE_SIZE]) {


        printf("\n\nDecryption Phase -1\n");

        char ciphertext[BUFFERSIZE];
        printf("Input ciphertext: ");

        fgets(ciphertext, BUFFERSIZE, stdin);
        ciphertext[strcspn(ciphertext, "\n")] = 0; // Remove newline character if present
        int cipherLength = strlen(ciphertext);
        for (int i = 0; i < strlen(ciphertext); ++i) {
             ciphertext[i] = toupper((unsigned char)ciphertext[i]);
        }

        char* transposed = dec_phase1(ciphertext);
        printf("Group-1: ");
        for (int i = 0; i < cipherLength / 2; ++i) {
             printf("%c", transposed[i]);
         }

        printf("\nGroup-2: ");
        for (int i = cipherLength / 2; i < cipherLength; ++i) {
            printf("%c", transposed[i]);
        }
        printf("\n");

        printf("Output (phase -1): %s",transposed);
        printf("\n");


        printf("Decryption Phase -2\n");
        printf("Input text: %s \n",transposed);

        char key[BUFFERSIZE];
        printf("Enter the key: ");
        fgets(key, BUFFERSIZE, stdin);
        key[strcspn(key, "\n")] = 0;


        char repeatedKey[BUFFERSIZE];
        int keyLength = strlen(key);
        for (int i = 0; i < cipherLength; ++i) {
            repeatedKey[i] = toupper((unsigned char)key[i % keyLength]);
        }
        repeatedKey[cipherLength] = '\0';
        const char* decryptedtxt;
        char* temp3[strlen(ciphertext)];

        printf("Key:%s", repeatedKey);
        for(int p = 0; p<TABLE_SIZE;p++){
            repeatedKey[p] = toupper(repeatedKey[p]);
            transposed[p] = toupper(transposed[p]);
        }
        decryptedtxt = dec_phase2(transposed, repeatedKey, table);


        printf("\nPlaintext: %s\n", decryptedtxt);

        free(transposed);

        return decryptedtxt;
    }

