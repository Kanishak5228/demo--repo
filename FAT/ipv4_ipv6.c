#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool isIPv4(char* ip) {
    int count = 0;
    char* token = strtok(ip, ".");
    
    while (token != NULL) {
        int value = atoi(token);
        
        if (value < 0 || value > 255) {
            return false;
        }
        
        if (token[0] == '0' && strlen(token) > 1) {
            return false;
        }
        
        token = strtok(NULL, ".");
        count++;
    }
    
    return (count == 4);
}

bool isIPv6(char* ip) {
    int count = 0;
    char* token = strtok(ip, ":");
    
    while (token != NULL) {
        int len = strlen(token);
        
        if (len > 4) {
            return false;
        }
        
        for(int i = 0; i < len; i++) {
            if (!((token[i] >= '0' && token[i] <= '9') ||
                  (token[i] >= 'A' && token[i] <= 'F') ||
                  (token[i] >= 'a' && token[i] <= 'f'))) {
                return false;
            }
        }
        
        token = strtok(NULL, ":");
        count++;
    }
    
    return (count == 8);
}

int main() {
    char ip[50];
    
    printf("IP address: ");
    fgets(ip, sizeof(ip), stdin);
    ip[strcspn(ip, "\n")] = '\0';
    
    if (isIPv4(ip)) {
        printf("Valid IPv4\n");
    } else if (isIPv6(ip)) {
        printf("Valid IPv6\n");
    } else {
        printf("Invalid IP\n");
    }
    
    return 0;
}