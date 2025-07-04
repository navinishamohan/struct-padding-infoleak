#include <stdio.h>
#include <string.h>

struct user{
  char name[7];
  int isAdmin;
};
int main(){
  char secret[]="LeAKy_{FlAG}";

  struct user u;

  strcpy(u.name,"Cyber");
  u.isAdmin=0;
unsigned char *raw = (unsigned char *)&u;

    printf("Leaked struct bytes:\n");
    for (int i = 0; i < sizeof(struct user); i++) {
        printf("Byte %2d: 0x%02X\n", i, raw[i]);
    }

    printf("\nsizeof(struct user) = %lu bytes\n", sizeof(struct user));
    return 0;
}
