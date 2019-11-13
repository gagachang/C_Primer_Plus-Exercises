/*
 * This program needs to design a bit field structure.
 * Use the structure to store following informations:
 * Font ID    : 0-255
 * Font Size  : 0-127
 * Alignment  : 0-2 (Left, Center, Right)
 * Bold       : off(0) or on(1)
 * Italic     : off(0) or on(1)
 * Underline  : off(0) or on(1)
 *
 * Show the settings of the structure and let the user change
 * the parameters.
 */
#include <stdio.h>
#include <limits.h>
#include <stdbool.h>

/* BIT-FIELD CONSTANTS */
/* Alignment */
#define LEFT   0
#define CENTER 1
#define RIGHT  2

struct Font {
    unsigned int font_id    : 8;
    unsigned int font_size  : 7;
    unsigned int alignment  : 2;
    bool bold               : 1;
    bool italic             : 1;
    bool underline          : 1;
};

void show_settings(const struct Font * ft);
char show_menu();

/* functions for change the settings of font */
void change_font(struct Font * ft);
void change_size(struct Font * ft);
void change_alignment(struct Font * ft);
void toggle_bold(struct Font * ft);
void toggle_italic(struct Font * ft);
void toggle_underline(struct Font * ft);

int main(void)
{
    bool loop = true;
    struct Font font = {1, 12, LEFT, false, false, false};
    char choice;

    while (loop)
    {
        show_settings(&font);
        choice = show_menu();
        switch(choice)
        {
            case 'f' : change_font(&font);
                       break;
            case 's' : change_size(&font);
                       break;
            case 'a' : change_alignment(&font);
                       break;
            case 'b' : toggle_bold(&font);
                       break;
            case 'i' : toggle_italic(&font);
                       break;
            case 'u' : toggle_underline(&font);
                       break;
            case 'q' : loop = false;
                       break;
        }
    }
    puts("Bye!");

    return 0;
}

void show_settings(const struct Font * ft)
{
    puts("  ID SIZE ALIGNMENT   B   I   U ");
    printf(" %3d  %3d", ft->font_id, ft->font_size);
    switch(ft->alignment)
    {
        case LEFT   : printf("   left");
                      break;
        case CENTER : printf(" center");
                      break;
        case RIGHT  : printf("  right");
                      break;
    }
    printf("     %3s %3s %3s\n", (ft->bold ? "on" : "off"), (ft->italic ? "on" : "off"), (ft->underline ? "on" : "off"));
}

char show_menu()
{
    char choice;

    puts("");
    puts("f)change font    s)change size    a)change alignment");
    puts("b)toggle bold    i)toggle italic  u)toggle underline");
    puts("q)quit");
    while (choice = getchar())
    {
        while (getchar() != '\n')
            continue;

        if (choice != 'f' && choice != 's' && choice != 'a' && choice != 'b' &&
            choice != 'i' && choice != 'u' && choice != 'q')
        {
            puts("You can only enter f, s, a, b, i, u, q");
            puts("Try again:");
        }
        else
            break;
    }

    return choice;
}

void change_font(struct Font * ft)
{
    int font_id;

    printf("Enter font id (0-255): ");
    while (scanf("%d", &font_id) != 1 || font_id < 0 || font_id > 255)
    {
        puts("You can only enter 0-255, try again: ");
        while (getchar() != '\n')
            continue;
    }
    while (getchar() != '\n')
        continue;
    
    ft->font_id = font_id;
}

void change_size(struct Font * ft)
{
    int font_size;

    printf("Enter font size (0-127): ");
    while (scanf("%d", &font_size) != 1 || font_size < 0 || font_size > 127)
    {
        puts("You can only enter 0-127, try again: ");
        while (getchar() != '\n')
            continue;
    }
    while (getchar() != '\n')
        continue;
    
    ft->font_size = font_size;
}

void change_alignment(struct Font * ft)
{
    char alignment;

    puts("Select alignment:");
    puts("l)left   c)center   r)right");
    while (scanf("%c", &alignment) != 1 || (alignment != 'l' && alignment != 'c' && alignment != 'r'))
    {
        puts("You can only enter l, c, r, try again: ");
        while (getchar() != '\n')
            continue;
    }
    while (getchar() != '\n')
        continue;
    
    switch(alignment)
    {
        case 'l' : ft->alignment = LEFT;
                   break;
        case 'c' : ft->alignment = CENTER;
                   break;
        case 'r' : ft->alignment = RIGHT;
                   break;
        default  : break;
    }
}

void toggle_bold(struct Font * ft)
{
    ft->bold = !ft->bold;
}

void toggle_italic(struct Font * ft)
{
    ft->italic = !ft->italic;
}

void toggle_underline(struct Font * ft)
{
    ft->underline = !ft->underline;
}
