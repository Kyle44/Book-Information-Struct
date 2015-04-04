/*
 *  File: test1.c
 *  Date Modified: Mar 31, 2015
 *  Author: Kyle Fritz
 */

#include <stdio.h>
#include <string.h>
#include "book_info_heap.h"

book_info *get_new_book_info(char *title, char *author, unsigned int year_published)
{
    book_info *info = new_book_info();
    if (info == NULL)
    {
        return NULL;
    }
    strncpy(info->title, title, sizeof(info->title) - 1);
    strncpy(info->author, author, sizeof(info->author) - 1);
    info->year_published = year_published;
    return info;
}

void print_info(const book_info *info)
{
    printf("Book Title: %s\n", info->title);
    printf("Book Author: %s\n", info->author);
    printf("Book Year Published: %u\n", info->year_published);
}

int main()
{
  book_info *info1, *info2, *info3, *info4, *info5, *info6, *info7, *info8, *info9, *info10, *info11, *info12, *info13, *info14, *info15, *info16, *info17, *info18, *info19, *info20, *info21;

    init_heap();

    info1 = get_new_book_info("Rant: The Oral Biography of Buster Casey", "Chuck Palahniuk", 2008);
    print_info(info1);
    dump_heap();

    del_book_info(info1);
    printf("*** Add multiple books, then look at dump again ***\n");
    info1 = get_new_book_info("Less Than Zero", "Bret Easton Ellis", 1985);
    info2 = get_new_book_info("What If: Serious Scientific Answers to Absurd Hypothetical Questions", "Randall Monroe", 2014);
    info3 = get_new_book_info("Ender\'s Game", "Orson Scott Card", 1985);
    info4 = get_new_book_info("Matilda", "Roald Dahl", 1988);
    info5 = get_new_book_info("Harry Potter 7", "J.K. Rowling", 2007);
    info6 = get_new_book_info("To Kill A Mockingbird", "Harper Lee", 1960);
    info7 = get_new_book_info("The Hobbit", "J.R.R. Tolkien", 1937);
    info8 = get_new_book_info("Catcher in the Rye", "J.D Salinger", 1951);
    info9 = get_new_book_info("Charlie and the Chocolate Factory", "Roald Dahl", 1964);
    info10 = get_new_book_info("Cat in the Hat", "Dr. Seuss", 1957);
    info11 = get_new_book_info("The Giver", "Lois Lowry", 1993);
    info12 = get_new_book_info("The Great Gatsby", "F. Scott Fitzgerald", 1925);
    info13 = get_new_book_info("The Grapes of Wrath", "John Steinbeck", 1939);
    info14 = get_new_book_info("1984", "George Orwell", 1949);
    info15 = get_new_book_info("Slaughterhouse-Five", "Kurt Vonnegut, Jr.", 1969);
    info16 = get_new_book_info("Adventures of Tom Sawyer", "Mark Twain", 1876);
    info17 = get_new_book_info("Adventures of Huckleberry Finn", "Mark Twain", 1884);
    info18 = get_new_book_info("The Shining", "Stephen King", 1977);
    info19 = get_new_book_info("A Clockwork Orange", "Anthony Burgess", 1962);
    dump_heap();

    del_book_info(info5);
    dump_heap();
    
    printf("*** Add Space Odyssey to next open space, should be space 0 ***\n");
    info20 = get_new_book_info("2001: A Space Odyssey", "Arthur C. Clarke", 1968);
    dump_heap();

    printf("*** Add Hunger Games, should go to space 5 ***\n");
    info21 = get_new_book_info("Hunger Games", "Suzanne Collins", 2008);
    dump_heap();
    
    printf("*** Delete Huck Finn ***\n");
    del_book_info(info17);
    dump_heap();
    
    printf("*** Delete again, so error will occur ***\n");
    del_book_info(info17);
    dump_heap();
    return 0;
}
