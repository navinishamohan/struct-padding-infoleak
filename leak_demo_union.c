#include <stdio.h>
#include <string.h>

union container {
    struct {
        char name[7];
        int isAdmin;
    } user;
    char raw[20];  
};

int main() {
    union container u;

   
    strcpy(u.raw, "FLAG{S3cr3t_Inf0}");  // occupies padding if overlaps
    strcpy(u.user.name, "Navi");         // overwrite name only
    u.user.isAdmin = 0;

    
    printf("Leaked struct bytes:\n");
    for (int i = 0; i < sizeof(u.user); i++) {
        printf("Byte %2d: 0x%02X\n", i, ((unsigned char *)&u.user)[i]);
    }

    return 0;
}
