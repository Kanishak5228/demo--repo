#include <stdio.h>
#include <string.h>

#define MAX_TITLE_SIZE 50
#define MAX_AUTHOR_SIZE 50
#define MAX_COLOR_SIZE 20
#define MAX_DESIGN_SIZE 20

// Structure for book
struct Book {
    char title[MAX_TITLE_SIZE];
    char author[MAX_AUTHOR_SIZE];
    int numPages;
    float price;
};

// Structure for shirt
struct Shirt {
    char color[MAX_COLOR_SIZE];
    char size;
    char design[MAX_DESIGN_SIZE];
    float price;
};

// Union for book and shirt
union Item {
    struct Book book;
    struct Shirt shirt;
};

// Structure for store item
struct StoreItem {
    int type;  // 0 for book, 1 for shirt
    union Item item;
};

int main() {
    // Create store items
    struct StoreItem item1, item2;
    item1.type = 0;  // book
    strcpy(item1.item.book.title, "The Great Gatsby");
    strcpy(item1.item.book.author, "F. Scott Fitzgerald");
    item1.item.book.numPages = 180;
    item1.item.book.price = 9.99;

    item2.type = 1;  // shirt
    strcpy(item2.item.shirt.color, "Blue");
    item2.item.shirt.size = 'M';
    strcpy(item2.item.shirt.design, "Striped");
    item2.item.shirt.price = 19.99;

    // Display store items
    printf("Item 1: Book\n");
    printf("Title: %s\n", item1.item.book.title);
    printf("Author: %s\n", item1.item.book.author);
    printf("Number of Pages: %d\n", item1.item.book.numPages);
    printf("Price: %.2f\n", item1.item.book.price);

    printf("\nItem 2: Shirt\n");
    printf("Color: %s\n", item2.item.shirt.color);
    printf("Size: %c\n", item2.item.shirt.size);
    printf("Design: %s\n", item2.item.shirt.design);
    printf("Price: %.2f\n", item2.item.shirt.price);

    return 0;
}
