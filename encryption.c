#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<time.h>
struct File {
  char file[100];
  char encrypted[100];
  char decrypted[100];
  int key;
};

// Function to encrypt a line
void encrypt1(char *line, char *encrypted) {
  int i = 0;
  while (line[i] != '\0') {
    if (line[i] == '\n') {
      encrypted[i] = '\n'; // Preserve newline characters
    } else {
      // Encrypt with alternating addition and subtraction
      encrypted[i] = line[i] + 3 * ((i % 2 == 0) ? 1 : -1);
    }
    i++;
  }
  encrypted[i] = '\0'; // Null terminate the string
}

// Function to decrypt a line
void decrypt1(char *line, char *decrypted) {
  int i = 0;
  while (line[i] != '\0') {
    if (line[i] == '\n') {
      decrypted[i] = '\n'; // Preserve newline characters
    } else {
      // Decrypt with alternating addition and subtraction
      decrypted[i] = line[i] - 3 * ((i % 2 == 0) ? 1 : -1);
    }
    i++;
  }
  decrypted[i] = '\0'; // Null terminate the string
}
void encrypt2(char *line, char *encrypted) {
  int i = 0;
  while (line[i] != '\0') {
    if (line[i] == '\n') {
      encrypted[i] = '\n'; // Preserve newline characters
    } else {
      // Encrypt with alternating addition and subtraction
      encrypted[i] = line[i] + 6 * ((i % 2 == 0) ? 1 : -1);
    }
    i++;
  }
  encrypted[i] = '\0'; // Null terminate the string
}

// Function to decrypt a line
void decrypt2(char *line, char *decrypted) {
  int i = 0;
  while (line[i] != '\0') {
    if (line[i] == '\n') {
      decrypted[i] = '\n'; // Preserve newline characters
    } else {
      // Reverse the encryption: first undo the +1 or -1, then divide by 2
      decrypted[i] = (line[i] - 6 * ((i % 2 == 0) ? 1 : -1));
    }
    i++;
  }
  decrypted[i] = '\0'; // Null terminate the string
}
void encrypt3(char *line, char *encrypted) {
  int i = 0;
  while (line[i] != '\0') {
    if (line[i] == '\n') {
      encrypted[i] = '\n'; // Preserve newline characters
    } else {
      // Encrypt with alternating addition and subtraction
      encrypted[i] = line[i] + 2 * ((i % 2 == 0) ? 1 : -1);
    }
    i++;
  }
  encrypted[i] = '\0'; // Null terminate the string
}

// Function to decrypt a line
void decrypt3(char *line, char *decrypted) {
  int i = 0;
  while (line[i] != '\0') {
    if (line[i] == '\n') {
      decrypted[i] = '\n'; // Preserve newline characters
    } else {
      // Decrypt with alternating addition and subtraction
      decrypted[i] = line[i] - 2 * ((i % 2 == 0) ? 1 : -1);
    }
    i++;
  }
  decrypted[i] = '\0'; // Null terminate the string
}
void encrypt4(char *line, char *encrypted) {
  int i = 0;
  while (line[i] != '\0') {
    if (line[i] == '\n') {
      encrypted[i] = '\n'; // Preserve newline characters
    } else {
      // Encrypt with alternating addition and subtraction
      encrypted[i] = line[i] + 5 * ((i % 2 == 0) ? 1 : -1);
    }
    i++;
  }
  encrypted[i] = '\0'; // Null terminate the string
}

// Function to decrypt a line
void decrypt4(char *line, char *decrypted) {
  int i = 0;
  while (line[i] != '\0') {
    if (line[i] == '\n') {
      decrypted[i] = '\n'; // Preserve newline characters
    } else {
      // Decrypt with alternating addition and subtraction
      decrypted[i] = line[i] - 5 * ((i % 2 == 0) ? 1 : -1);
    }
    i++;
  }
  decrypted[i] = '\0'; // Null terminate the string
}

// Function to encrypt the file
void encryption(FILE *fp, struct File *f) {
    char line[100];
    char encryptedLine[100];
    sprintf(f->encrypted, "encrypted_%s", f->file);
    FILE *ep = fopen(f->encrypted, "w");
    printf("Encryption type: %d is being applied\n", f->key);
    if (!ep) 
    {
        printf("Error opening encrypted file for writing\n");
        return;
    }
    switch(f->key)
        {
            case 1:
                while (fgets(line, sizeof(line), fp) != NULL) 
                {
                    encrypt1(line, encryptedLine);
                    fprintf(ep, "%s", encryptedLine);
                }
                break;
            case 2:
                while (fgets(line, sizeof(line), fp) != NULL) 
                {
                    encrypt2(line, encryptedLine);
                    fprintf(ep, "%s", encryptedLine);
                }
                break;
            case 3:
                while (fgets(line, sizeof(line), fp) != NULL) 
                {
                    encrypt3(line, encryptedLine);
                    fprintf(ep, "%s", encryptedLine);
                }
                break;
            case 4:
                while (fgets(line, sizeof(line), fp) != NULL) 
                {
                    encrypt4(line, encryptedLine);
                    fprintf(ep, "%s", encryptedLine);
                }
                break;
        }
      
      fclose(ep);
      printf("File %s encrypted successfully\n", f->file);

}

// Function to decrypt the file
void decryption(FILE *fp, struct File *f) {
    printf("Decryption in progress for encryption type: %d\n", f->key);
    char line[100];
    char decryptedLine[100];
    sprintf(f->decrypted, "decrypted_%s", f->encrypted);
    FILE *sp = fopen(f->decrypted, "w");
    if (!sp) 
    {
        printf("Error opening decrypted file for writing\n");
        return;
    }
    switch(f->key)
        {
            case 1:
                while (fgets(line, sizeof(line), fp) != NULL) 
                {
                    decrypt1(line, decryptedLine);
                    fprintf(sp, "%s", decryptedLine);
                }
                break;
            case 2:
                while (fgets(line, sizeof(line), fp) != NULL) 
                {
                    decrypt2(line, decryptedLine);
                    fprintf(sp, "%s", decryptedLine);
                }
                break;
            case 3:
                while (fgets(line, sizeof(line), fp) != NULL) 
                {
                    decrypt3(line, decryptedLine);
                    fprintf(sp, "%s", decryptedLine);
                }
                break;
            case 4:
                while (fgets(line, sizeof(line), fp) != NULL) 
                {
                    decrypt4(line, decryptedLine);
                    fprintf(sp, "%s", decryptedLine);
                }
                break;
             
        }
    fclose(sp);
    printf("File %s decrypted successfully\n", f->encrypted);
}

int main(void) {
    struct File f;
    printf("Enter the file name: ");
    scanf("%s", f.file);

    FILE *fp = fopen(f.file, "r");
    if (!fp) {
        printf("Error opening file %s\n", f.file);
        return 1;
    }

    srand(time(NULL));
    f.key = (rand() % 4) + 1;
    printf("Randomly selected encryption key: %d\n", f.key);  // Move this line here

    encryption(fp, &f);
    fclose(fp);

    FILE *ep = fopen(f.encrypted, "r");
    if (!ep) {
        printf("Error opening encrypted file %s\n", f.encrypted);
        return 1;
    }

    decryption(ep, &f);
    fclose(ep);

    return 0;
}
