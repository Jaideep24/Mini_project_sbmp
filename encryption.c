#include <stdio.h>

struct File
{
  char file[100];
  char encrypted[100];
  char decrypted[100];
  int key;
};



char* encrypt1(char* line)
{
  int i = 0;
  char encrypted[100];
  for(i = 0; line[i]!='\0'; i++)
    {
      if(line[i] == '\n')
      {
        encrypted[i] = '\n';
      }
      else
      {
        encrypted[i] = line[i] +3*(-1^(i));
      }
      
    }
  encrypted[i] = '\0';
  return encrypted;
}

char* decrypt1(char* line)
{
  int i = 0;
  char decrypted[100];
  for(i = 0; line[i]!='\0'; i++)
    {
      if(line[i] == '\n')
      {
        decrypted[i] = '\n';
      }
      else
      {
        decrypted[i] = line[i] -3*(-1^(i));
      }
      
    }
  decrypted[i] = '\0';
  printf("%s\n", decrypted);
  return decrypted;
}

void encryption(FILE *fp, struct File *f)
{
  char file[100];
  char line[100];
  sprintf(file, "encrypted_%s", f->file);
  strcpy(f->encrypted,file);
  FILE *ep=fopen(file,"w");
  while(fgets(line,100,fp)!=NULL)
    {
      fprintf(ep,"%s",encrypt1(line));
      printf("encryption working");
    }
  printf("File %s encrypted successfully\n",f->file);

}
void decryption(FILE *fp, struct File *f)
{
  char file[100];
  char line[100];
  sprintf(file, "decrypted_%s", f->encrypted);
  strcpy(f->decrypted,file);
  FILE *sp=fopen(file,"w");
  while(fgets(line,100,fp)!=NULL)
    {
      fprintf(sp,"%s",decrypt1(line));
      printf("working");
    }
  printf("File %s decrypted successfully\n",f->encrypted);

}
int main(void) {
  printf("Hello World\n");
  struct File f;
  printf("Enter the file name: ");
  scanf("%s", f.file);
  FILE *fp = fopen(f.file, "r");
  encryption(fp, &f);
  fclose(fp);
  FILE *ep = fopen(f.encrypted, "r");
  decryption(ep, &f);
  fclose(ep);
  return 0;
}
