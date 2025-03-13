#include <stdio.h>
#include <string.h>

void replace_var(const char *input, const char *var_name, const char *var_value, char *output) {
    const char *pos = strstr(input, var_name); // Find $VAR position
    if (!pos) {
        strcpy(output, input); // No replacement needed
        return;
    }

    // Copy text before $VAR
    int before_len = pos - input;
    strncpy(output, input, before_len);
    output[before_len] = '\0'; // Null-terminate the string

    // Append var_value
    strcat(output, var_value);

    // Append text after $VAR
    strcat(output, pos + strlen(var_name));
}

int main() {
    char input[] = "Hello $VAR world!"; // $VAR is between words
    char var_value[] = "beautiful";
    char output[100]; // Make sure it's large enough

    replace_var(input, "$VAR", var_value, output);

    printf("%s\n", output); // Output: Hello beautiful world!
    return 0;
}
